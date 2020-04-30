#include "mainprogram.h"

#include <usbreader.h>
#include <copierthread.h>
#include <QDebug>
#include <pathdetails.h>
#include <unistd.h>
#include <readconfig.h>
#include <programkiller.h>


MainProgram::MainProgram()
{
    usbReader= new UsbReader(this);
    folderCopier = new CopierThread(this);
    reader = new ReadConfig(this);

    connect(usbReader, &UsbReader::returnPath,
            this, &MainProgram::getPathToFiles);

    connect(folderCopier, &CopierThread::minimumChanged,
            &windowProgress, &MainWindow::setProgressBarMin, Qt::QueuedConnection);

    connect(folderCopier, &CopierThread::maximumChanged,
            &windowProgress, &MainWindow::setProgressBarMax, Qt::QueuedConnection);

    connect(folderCopier, &CopierThread::progressChanged,
            &windowProgress, &MainWindow::setProgressBarValue, Qt::QueuedConnection);

    connect(folderCopier, &CopierThread::finishedUpdatingFiles,
            &windowProgress, &MainWindow::warnAndReboot, Qt::QueuedConnection);

    connect(reader, &ReadConfig::copyPathsSet,
                this, &MainProgram::runCopyMechanism, Qt::QueuedConnection);

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
    ////
    /// if config with paths on pendrive use them if not use default
    ///



    QString configFilePath = mountingPoint + QDir::separator()+"config.ini";
    qDebug()<<"ConfigFilePath" <<configFilePath;
    QFile file(configFilePath);
    if(!file.exists()) return;


    //Parameters::Task task = Parameters::Task::onlyKill

    programKiller = new ProgramKiller(this,configFilePath);
    programKiller->setProgramsToKill();
    programKiller->startKillingLoop();

    reader->readConfPaths(configFilePath,path);
    ////
    /// \copy only Contents Of Folder Contents on new connected DRIVE
    /// read conf, take paths from config file and start copying proc
    /// device must use udev/dev
    ///

    programKiller->deleteLater();
}


void MainProgram::copyFilesFromUsb()
{
usbReader->start();

}


void MainProgram::runCopyMechanism(QString s, QString d)
{
    qDebug()<<QString("Source %1, Destination %1").arg(s).arg(d);

 folderCopier->copy(s, d);
}







