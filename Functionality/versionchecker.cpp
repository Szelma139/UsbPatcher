#include "versionchecker.h"

#include <QFile>
#include <QDebug>

VersionChecker::VersionChecker()
{
qDebug()<<"V checker";
}


QString VersionChecker::returVersion(QString path)
{
    qDebug()<<"Trying " << path;
   QFile file(path);

    if ((!file.exists()) || (!file.open(QIODevice::ReadOnly | QFile::Text))) return "NIE ZNALEZIONO";
   else {

       QTextStream in(&file);
       return in.readAll();
   }








}
