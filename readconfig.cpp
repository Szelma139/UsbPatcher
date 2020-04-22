#include "readconfig.h"

#include <QFile>
#include <QDebug>
#include <pathdetails.h>

#include <QDir>

ReadConfig::ReadConfig(QObject * parent):
    QObject(parent)
{

}


void ReadConfig::readConfPaths(QString src, QString mountPoint)
{
    QFile configDirectory(src);
    QString destinationFolder, folderToCopy;
    QString mount = mountPoint;


    if (configDirectory.exists())
    {
        qDebug()<<"plik  konfiguracyjny istnieje";
       PathDetails  conf(src);
        destinationFolder = conf.returnDestFromConfig();
        folderToCopy = conf.returnSourceFromConfig();

        qDebug()<<"uzywam docelowego z pliku"<<destinationFolder;
        qDebug()<<"Uzywam zrodlowego z pliku"<<folderToCopy;
        QString sourceFolder = mount + QDir::separator() + folderToCopy;

        emit copyPathsSet(sourceFolder, destinationFolder);
    }
    //////

   // usleep(2000);


}
