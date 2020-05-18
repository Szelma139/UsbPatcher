#ifndef USBREADER_H
#define USBREADER_H

#include <QThread>

#include <QStorageInfo>
#include <QList>
#include <mainwindow.h>


class QFileSystemWatcher;
class UsbReader: public QThread
{
    Q_OBJECT
public:
    UsbReader(QObject * parent, QString path = "/dev/");

protected:
    void run() override;

signals:
    void spottedChanges(QString);
    void showWindow();
    void returnPath(QString);

private:
    QFileSystemWatcher * usbDirWatcher;
    QString mountedPartition;

    bool foundNewUsbDev = false;


private slots:
    void getFolderChanges(QString);
    void findNewDrive();


public:
    void showListElements(QList<QStorageInfo> info);

private:
    QList<QStorageInfo> lastKnownListOfDrives;

    MainWindow * w;


public:
    QByteArray getLastKnownElement(QList<QStorageInfo>info);
    void findMountingPoint(QString partitionName);
    void getListOfLines(QStringList list);





    QString getMountedPartition() const;
    void setMountedPartition(const QString &value);
};

#endif // USBREADER_H
