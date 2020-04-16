#include "mainprogram.h"

#include <usbreader.h>
#include <copierthread.h>
#include <QDebug>
#include <confreader.h>


MainProgram::MainProgram(QObject * parent)
{
    usbReader= new UsbReader(this);
    folderCopier = new CopierThread(this);

    connect(usbReader, &UsbReader::returnPath,
            this, &MainProgram::getPathToFiles);

    connect(folderCopier, &CopierThread::minimumChanged,
            &windowProgress, &MainWindow::setProgressBarMin, Qt::QueuedConnection);

    connect(folderCopier, &CopierThread::maximumChanged,
            &windowProgress, &MainWindow::setProgressBarMax, Qt::QueuedConnection);

    connect(folderCopier, &CopierThread::progressChanged,
            &windowProgress, &MainWindow::setProgressBarValue, Qt::QueuedConnection);

    connect(folderCopier, &CopierThread::finishedUpdatingFiles,
            &windowProgress, &MainWindow::warnAndReboot);


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
    windowProgress.show();
}

void MainProgram::getPathToFiles(QString mountingPoint)
{
    path = mountingPoint;
    this->showWindow();
    QString sourceFolder = path + QDir::separator() + folderToCopy;

   //folderToCopy
    //destinationFolder



    ////
    /// if config with paths on pendrive use them if not use default
    ///
    ///

    QString configFilePath = mountingPoint + QDir::separator()+"config.init";
    QDir dir(configFilePath);
    if (dir.exists())

    {
       ConfReader conf(configFilePath);
        destinationFolder = conf.returnDestFromConfig();
        sourceFolder = conf.returnSourceFromConfig();

    }
    //////



    if (!QDir(destinationFolder).exists())
        return;

    ////
    /// \copy only Contents Of Folder Contents on new connected DRIVE
    /// device must use udev/dev
    ///


    folderCopier->copy(sourceFolder, destinationFolder);
}


void MainProgram::copyFilesFromUsb()
{
usbReader->start();

}





