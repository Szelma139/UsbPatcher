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
    UsbReader();

protected:
    void run() override;

signals:
    void spottedChanges(QString);

private:
    QFileSystemWatcher * usbDirWatcher;


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



};

#endif // USBREADER_H
