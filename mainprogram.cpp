#include "mainprogram.h"

#include <usbreader.h>
#include <copierthread.h>
#include <QDebug>
#include <pathdetails.h>
#include <unistd.h>
#include <readconfig.h>
#include <programkiller.h>
#include <QProcess>
#include <scriptexecutor.h>



MainProgram::MainProgram()
{
    usbReader= new UsbReader(this);
    folderCopier = new CopierThread(this);
    reader = new ReadConfig(this);
    scriptexecutor= new ScriptExecutor(this);

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

     connect(&windowProgress,&MainWindow::timeToUmountDevice,
             this,&MainProgram::goToSleep, Qt::QueuedConnection);

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

    QString configFilePath = mountingPoint + QDir::separator()+"config.ini";
    qDebug()<<"ConfigFilePath" <<configFilePath;
    QFile file(configFilePath);
    if(!file.exists()) return;

    programKiller = new ProgramKiller(this,configFilePath);
    programKiller->setProgramsToKill();
    programKiller->startKillingLoop();


    scriptexecutor->executeScript("enter-edit-mode.sh","/opt/");
    scriptexecutor->executeScript("mount-rw-system.sh","/opt/");
   // scriptexecutor->executeScript("enter-edit-mode.sh","/opt/");




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


//find device, umount it and go to sleep
void MainProgram::goToSleep()
{

    QProcess process;
    process.start("umount " + usbReader->getMountedPartition() );
    process.waitForFinished();

   // system("reboot");
}



