#include "usbreader.h"

#include <QFileSystemWatcher>
#include <QDir>
#include <QTimer>
#include <QFile>
#include <QRegExp>
#include <unistd.h>
#include <QDebug>


UsbReader::UsbReader(QObject * parent):
    QObject(parent)

{

}


void UsbReader::fetchMountingPoint(){

findNewDrive();

}

QByteArray UsbReader::getLastKnownElement(QList<QStorageInfo>info)
{

    if (!info.isEmpty())
        return info.last().device();
}

void UsbReader::showListElements(QList<QStorageInfo> list){

    for (QStorageInfo info:list){
        qDebug()<<info.name()<<info.device()<<info.displayName();
    }
}

QString UsbReader::getMountedPartition() const
{
    return mountedPartition;
}

void UsbReader::setMountedPartition(const QString &value)
{
    mountedPartition = value;
}

void UsbReader::findNewDrive()
{
    sleep(8);
    QList<QStorageInfo > newListOfKnownDrives = QStorageInfo::mountedVolumes();


    showListElements(newListOfKnownDrives);

        QString newDevice = getLastKnownElement(newListOfKnownDrives);
        QStringList listOfPossibleDevices = {"dev/sda1","dev/sda2","dev/sda3",
                                             "dev/sdb1", "dev/sdb2","dev/sdb3",
                                             "dev/sdc1", "dev/sdc2", "dev/sdc3"};
        if (newDevice.contains("dev")) {
            qDebug()<<QString("Found new device name %1").
                      arg(newDevice);
            findMountingPoint(newDevice);
        }

}




void UsbReader::findMountingPoint(QString partitionName)
{
    QFile file("/proc/self/mounts");
    QString fullMountingPoint;
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"Czy plik istnieje"<<file.error();
        return;
    }

    qDebug() << "Przeprowadzam czytanie pliku";
    QTextStream stream(&file);
    QString line;

    int number = 0;

    line = stream.readLine();

    while (!line.isNull())
    {
        line=stream.readLine();
        number++;

        if (line.contains(partitionName))
        {
            fullMountingPoint = line;
            break;
        }

    }
    mountedPartition = fullMountingPoint.left(fullMountingPoint.indexOf(" "));
    qDebug()<<"Mounted parition on drive" << mountedPartition;
    int firstSpace = fullMountingPoint.indexOf(" ");
    fullMountingPoint = fullMountingPoint.mid(firstSpace+1);
    int secondSpace = fullMountingPoint.indexOf(" ");
    fullMountingPoint = fullMountingPoint.left(secondSpace);


    qDebug()<<"M" << fullMountingPoint;


    while (fullMountingPoint.contains("\\"))
    {
        fullMountingPoint=fullMountingPoint.replace("\\040","\ ");
        qDebug()<<"Nowy" << fullMountingPoint;
    }
    usleep(3000);



    emit returnPath(fullMountingPoint);


}


