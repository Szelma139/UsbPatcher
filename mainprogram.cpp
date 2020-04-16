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

    connect(folderCopier, &CopierThread::finishedCopyingFiles,
            &windowProgress, &MainWindow::finishUpdating);
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

    QString sourceFolder = path + QDir::separator()+folderToCopy;

    folderCopier->copy(sourceFolder, destinationFolder);
}


void MainProgram::copyFilesFromUsb()
{
usbReader->start();

}


