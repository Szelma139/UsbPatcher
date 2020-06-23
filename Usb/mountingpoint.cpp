#include "mountingpoint.h"


#include <QDebug>
#include <QFile>

#include <Log/Logger.h>

MountingPoint::MountingPoint()
{

}


QString MountingPoint::getProcessedMountingPoint(QString partitionName)
{
        QString mountPointNewLine;

    QFile file("/proc/self/mounts");

        if (file.exists())
        QString fullMountingPoint;


    if(file.open(QIODevice::ReadOnly))
    {

        qDebug() << "Przeprowadzam czytanie pliku";
        QTextStream stream(&file);
        QString line;
        int number = 0;


        line = stream.readLine();

        while (!line.isNull())
        {

            if (line.contains(partitionName))
            {
                mountPointNewLine = line;
                break;
            }

            line=stream.readLine();
            number++;
        }
    }
    QString mountedPath = returnMountingPath(mountPointNewLine);

    return mountedPath;
}


QString MountingPoint::returnMountingPath(QString mountPointLine )
{
    int firstSpace = mountPointLine.indexOf(" ");
    mountPointLine = mountPointLine.mid(firstSpace+1);
    int secondSpace = mountPointLine.indexOf(" ");
    mountPointLine = mountPointLine.left(secondSpace);

    qDebug()<<"Mount: " << mountPointLine;


///@
///
/// if it contains space fix it
    while (mountPointLine.contains("\\"))
    {
        mountPointLine=mountPointLine.replace("\\040","\ ");
        qDebug()<<"Nowy" << mountPointLine;
        Logger::GetLogger()->Log("Path to device is containing spaces. Fixing path");

    }

    Logger::GetLogger()->Log("Mounting point found. It is " + mountPointLine);

    return mountPointLine;
}


