#include "drivewatcher.h"

#include <QFileSystemWatcher>

#include <QTimer>

#include <QDebug>

DriveWatcher::DriveWatcher(QObject * parent)
    :QThread()
{
    usbDirWatcher = new QFileSystemWatcher(this);
    QString path = "/dev/";
    usbDirWatcher->addPath(path);
    lastKnownListOfDrives = QStorageInfo::mountedVolumes();
}



void DriveWatcher::run()
{
    connect(usbDirWatcher,SIGNAL(directoryChanged(QString)),
            this,SLOT(spottedChangesOnDrive()));
}


void DriveWatcher::spottedChangesOnDrive(QString folder)
{
    qDebug()<<QString("Found changes on ").arg(folder);
    QTimer::singleShot(2000,this,SLOT(findNewDrive()));
}


QByteArray DriveWatcher::getLastKnownElement(QList<QStorageInfo>info)
{

    if (!info.isEmpty())
        return info.last().device();
}

void DriveWatcher::findNewDrive()
{

    QList<QStorageInfo> newListOfKnownDrives = QStorageInfo::mountedVolumes();
    if (newListOfKnownDrives.length()>lastKnownListOfDrives.length())
    {

        QString newDevice = getLastKnownElement(newListOfKnownDrives);
        if (newDevice.contains("dev")) {
            qDebug()<<QString("Found new device name %1").
                      arg(newDevice);

                emit foundNewUsbDev(newDevice);
        }



}
