#ifndef COPIERTHREAD_H
#define COPIERTHREAD_H

#include <QObject>
#include <QThread>

class CopierThread: public QThread
{

   Q_OBJECT

public:
    CopierThread(QObject * parent = nullptr);

    double minimum() const;
    double maximum() const;
    double progress() const;

    void copy( QString &sourceFolder, QString &destFolder);

private:

    QStringList getFolderContents(QString &sourceFolder);
    qint64 fileSize(QString &sourceFolder, QStringList &fileList);
    void copyFiles();


protected:
    void run();

private:
    QString mSourceFolder;
    QString mDestFolder;
    QStringList mFileList;
    double mMinimum;
    double mMaximum;
    double mProgress;

signals:
    void minimumChanged(double minimum);
    void maximumChanged(double maximum);
    void progressChanged(double progress);

    void finishedUpdatingFiles();



};

#endif // COPIERTHREAD_H
