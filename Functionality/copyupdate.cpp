#include "copyupdate.h"

#include <QDebug>

CopyUpdate::CopyUpdate(QString dirContent)
{
destFolder = dirContent;
qDebug()<<"SF:"<<sourceFolder;
}

void CopyUpdate::backup()
{
    qDebug()<<"backup";
}

void CopyUpdate::update()
{
    qDebug()<<"update";

}

void CopyUpdate::remove()
{
    qDebug()<<"remove";

}

void CopyUpdate::restore()
{
    qDebug()<<"restore";

}

QString CopyUpdate::getSourceFolder() const
{
    return sourceFolder;
}

void CopyUpdate::setSourceFolder(const QString &value)
{
    sourceFolder = value;
}
