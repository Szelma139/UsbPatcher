#include "usbreader.h"

#include <QFileSystemWatcher>


#include <QDebug>

#include <QDir>
#include <QTimer>
#include <QProcess>
#include <QFile>
#include <QRegExp>
#include <unistd.h>

UsbReader::UsbReader(QObject * parent, QString path):
    QThread()
{
    usbDirWatcher = new QFileSystemWatcher(this);
    usbDirWatcher->addPath(path);
    lastKnownListOfDrives = QStorageInfo::mountedVolumes();
    w = new MainWindow;

}


void UsbReader::run()
{
    connect(usbDirWatcher, SIGNAL(directoryChanged(QString)),
            this,SLOT(getFolderChanges(QString)),Qt::UniqueConnection);



}


void UsbReader::getFolderChanges(QString path)
{
    QTimer::singleShot(1500,this, SLOT(findNewDrive()));
}


void UsbReader::showListElements(QList<QStorageInfo> info){
    for (QStorageInfo element:info)
    {

        //     qDebug()<<"Name: "<<element.name()<<
        //             "Device " <<QString::fromStdString(element.device().toStdString());
    }
}


QByteArray UsbReader::getLastKnownElement(QList<QStorageInfo>info)
{

    if (!info.isEmpty())
        return info.last().device();
}

void UsbReader::findNewDrive()
{
    QList<QStorageInfo> newListOfKnownDrives = QStorageInfo::mountedVolumes();
    if (newListOfKnownDrives.length()>lastKnownListOfDrives.length())
    {
        showListElements(newListOfKnownDrives);

        QString newDevice = getLastKnownElement(newListOfKnownDrives);
        if (newDevice.contains("dev")) {
            qDebug()<<QString("Found new device name %1").
                      arg(newDevice);
            findMountingPoint(newDevice);
        }

    }

}


void UsbReader::getListOfLines(QStringList list)
{
    for (QString element: list)
    {
        qDebug()<< QString(" Element listy: %1 ").arg(element);
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
    // qDebug()<<line;

    while (!line.isNull())
    {
        line=stream.readLine();
        // qDebug()<<line << number;
        number++;

        if (line.contains(partitionName))
        {
            qDebug()<< "Panie to ta linia"
                    <<line;
            fullMountingPoint = line;
            break;
        }

    }
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

    /*
    //8QString pathToCopyFiles;
    QDir dir(fullMountingPoint);
    qDebug()<< "czytany dir: "<< fullMountingPoint;
    if (dir.exists() && dir.isReadable())
    {
        qDebug()<< " Mamy go";
        QFile file(fullMountingPoint+"/Piersi/drugaPiersAgaty.txt");
        pathToCopyFiles = fullMountingPoint+"/Piersi/drugaPiersAgaty.txt";
        if (!file.exists()){
            qDebug()<<"Pliku nie ma mistrzu";
        }
        else qDebug("znaleziono piers");

    }
    else
        qDebug()<<"Cos chyba jest nie tak";

QFile file2(pathToCopyFiles);
if (file2.exists()) qDebug()<<"Wszystko w porzadku. Plik istnieje";

    QString sourcePath = pathToCopyFiles;
    QString destFilePath = "/opt/pliki/pliki2/dupa.txt";

    if (QFile::exists(destFilePath)){
        QFile::remove(destFilePath);
    }
       if (QFile::copy(sourcePath, destFilePath))
           qDebug()<<"!!!!!!!!!!!!!!!!!!!!!!!SUKCES!!!!!!!!!!!!!";


*/
}


