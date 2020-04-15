#include "mountingpoint.h"


#include <QDebug>
#include <QFile>
MountingPoint::MountingPoint()
{

}


void MountingPoint::getMountPointLineFroFil(QString partitionName)
{

    QFile file("/proc/self/mounts");

        if (!file.exists())
            return;

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
                fullMountingPoint = line;
                break;
            }

            line=stream.readLine();
            number++;
        }
    }
    QString mountedPath = returnMountingPath(fullMountingPoint);

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
    }

    return mountPointLine;
}


