#include "filecopier.h"
#include <QDir>
#include <QDebug>

FileCopier::FileCopier(QString sourcePath)
{


    ////source Path is mount point, without definitive path

    m_sourcePath = sourcePath;

}



void FileCopier::restartDevice()
{
    system("reboot");
}


bool FileCopier::checkIfSourceDevExists()
{

    QDir dir(m_sourcePath);
    qDebug()<< "czytany dir: "<< m_sourcePath;
    if (dir.exists() && dir.isReadable())
       return true;
    else
        return false;

}

bool FileCopier::checkIfSourceFileExists(QString filepath)
{
    //media/radek/linux + "/" + filepath
    QFile file(m_sourcePath + filepath);
    if (file.exists())
        return true;
    else
        return false;
}



void FileCopier::copyFilesTo(QString targetPath)
{

    if (QFile::exists(targetPath)){
        QFile::remove(targetPath);
    }
       if (QFile::copy(m_sourcePath, targetPath))
           qDebug()<<"!!!!!!!!!!!!!!!!!!!!!!!SUKCES!!!!!!!!!!!!!";
}
