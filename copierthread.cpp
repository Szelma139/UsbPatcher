#include "copierthread.h"


#include <QDir>
#include <QFileInfo>

#include <QDebug>

CopierThread::CopierThread(QObject * parent)
    :QThread()
{

}

double CopierThread::minimum() const
{
    return mMinimum;
}

double CopierThread::maximum() const
{
    return mMaximum;
}

double CopierThread::progress() const
{
    return mProgress;
}

void CopierThread::copy(QString &sourceFolder, QString &destFolder)
{


    mSourceFolder = sourceFolder;
    mDestFolder = destFolder;
    mFileList = getFolderContents(sourceFolder);


    for (QString el:mFileList)
    {
        qDebug()<<"File x" <<el;
    }

    mMinimum = 0;
    mMaximum = fileSize(sourceFolder, mFileList);
    emit minimumChanged(mMinimum);
    emit maximumChanged(mMaximum);

    if(!isRunning())
    {

        start();

    }

}

QStringList CopierThread::getFolderContents(QString &sourceFolder)
{
    QStringList fileList;
    qDebug()<<"Czekaj basiu na mnie";
    std::function<bool(const QString&, const QString&)> folderContents;
    folderContents = [&](const QString &sourceFolder, const QString &destFolder)->bool {
        QDir sourceDir(sourceFolder);
        qDebug()<<"sourceDir"<<sourceFolder;
        if (!sourceDir.exists())
            return false;

        foreach (const QFileInfo &fileInfo, sourceDir.entryInfoList(QDir::NoDotAndDotDot | QDir::NoSymLinks
                                                                    | QDir::Dirs | QDir::Files)) {
            QString srcFilePath = fileInfo.filePath();
            qDebug()<<"sourceFilePath"<<srcFilePath;
            QString dstFilePath = destFolder.isEmpty() ? fileInfo.fileName() : destFolder + QDir::separator() + fileInfo.fileName();
            qDebug()<<"dstFilePath"<<dstFilePath;

            if (fileInfo.isDir()) {
                if (!folderContents(srcFilePath, dstFilePath))
                    return false;
            } else {
                fileList.append(dstFilePath);
            }
        }

        return true;
    };

    if (folderContents(sourceFolder, QString()))
        return fileList;
    else
        return QStringList();
}

qint64 CopierThread::fileSize( QString &sourceFolder,  QStringList &fileList)
{
    qint64 total = 0;

    foreach (const QString &fileName, fileList)
        total += QFile(sourceFolder+ QDir::separator() + fileName).size();

    return total;
}

void CopierThread::copyFiles()
{
    qint64 bufferSize = 4194304;
    QByteArray buffer;
    mProgress = 0;
    emit progressChanged(mProgress);

    foreach (const QString &fileName, mFileList) {
        QString srcFilePath = mSourceFolder + QDir::separator() + fileName;
        QString dstFilePath = mDestFolder + QDir::separator() + fileName;
        qDebug()<<"SourceFilePath"<<srcFilePath;
        qDebug()<<"DestFilePath"<<dstFilePath;
        QFile srcFile(srcFilePath);
        QFile dstFile(dstFilePath);

        QFileInfo dst(dstFilePath);
        QDir dir = dst.dir();
        if (!dst.isDir() && !dir.exists())
            dir.mkpath(dir.path());

        if (srcFile.open(QIODevice::ReadOnly) && dstFile.open(QIODevice::WriteOnly)) {
            qint64 internalBufferSize = srcFile.size() < bufferSize ? srcFile.size() : bufferSize;

            while (1) {
                buffer = srcFile.read(internalBufferSize);
                if (buffer.isEmpty())
                    break;

                dstFile.write(buffer);
                mProgress += internalBufferSize;
                emit progressChanged(mProgress);
            }
            srcFile.close();
            dstFile.close();
            //emit +1
        }
    }
    //emit 100%
    emit finishedUpdatingFiles();

    //emit md5 check
    //stworz Hashmap plikow




    qDebug()<<"Zakonczono kopiowanie i wyslano sygnal";
}

void CopierThread::run()
{
    copyFiles();
}
