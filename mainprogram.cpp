#include "mainprogram.h"

#include <usbreader.h>
#include <copierthread.h>
#include <QDebug>


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

    if (!QDir(destinationFolder).exists())
        return;

    ////
    /// \copy only Contents Of Folder Contents on new connected DRIVE
    /// device must use udev/dev
    ///
    QString sourceFolder = path + QDir::separator() + folderToCopy;

    folderCopier->copy(sourceFolder, destinationFolder);
}


void MainProgram::copyFilesFromUsb()
{
usbReader->start();

}





