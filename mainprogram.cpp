#include "mainprogram.h"

#include <usbreader.h>
#include <copierthread.h>

MainProgram::MainProgram(QObject * parent)
{
    usbReader= new UsbReader(this);
    folderCopier = new CopierThread(this);
    connect(usbReader,SIGNAL(returnPath(QString)),this,SLOT(getPathToFiles(QString)));
    connect(folderCopier,SIGNAL(minimumChanged()), w,)
}

QString MainProgram::getFolderToCopy() const
{
    return folderToCopy;
}

void MainProgram::setFolderToCopy(const QString &value)
{
    folderToCopy = value;
}

void MainProgram::showWindow()
{
    windowProgress->show();
}

void MainProgram::getPathToFiles(QString mountingPoint)
{
    path = mountingPoint;
    this->showWindow();

}


void MainProgram::copyFilesFromUsb()
{
usbReader->start();

}


