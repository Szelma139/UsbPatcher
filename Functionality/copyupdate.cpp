#include "copyupdate.h"

#include <QDebug>
#include <Functionality/copierthread.h>

CopyUpdate::CopyUpdate(QString dirContent, QString source,CopierThread * copier)
{
    this->copier = copier;
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

QString CopyUpdate::getDestFolder() const
{
    return destFolder;
}

void CopyUpdate::setDestFolder(const QString &value)
{
    destFolder = value;
}

QString CopyUpdate::getSourceFolder() const
{
    return sourceFolder;
}

void CopyUpdate::setSourceFolder(const QString &value)
{
    sourceFolder = value;
}
