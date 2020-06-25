#include "mainprogram.h"

#include "Usb/usbreader.h"
#include <Functionality/copierthread.h>
#include <QDebug>
#include <Usb/pathdetails.h>
#include <unistd.h>
#include <Functionality/readconfig.h>
#include <Functionality/programkiller.h>
#include <QProcess>
#include <Functionality/scriptexecutor.h>
#include <Log/Logger.h>
#include <Screens/progressbarwindow.h>
#include <Screens/versionwindow.h>
#include <Usb/usbnotifications.h>
#include <QDir>




MainProgram::MainProgram()
{
    usbReader= new UsbReader(this);
    reader = new ReadConfig(this);
    scriptexecutor= new ScriptExecutor(this);
    versionWindow = new VersionWindow;
    usbNotifications = new UsbNotifications(this);


    connect(usbReader, &UsbReader::returnPath,
          this, &MainProgram::getPathToFiles, Qt::UniqueConnection);

    connect(usbNotifications,&UsbNotifications::insertedUsbDevice, usbReader,&UsbReader::fetchMountingPoint);

    connect(usbNotifications, &UsbNotifications::removedUsbDevice,this, &MainProgram::hideAndClose);

    connect(reader, &ReadConfig::copyPathsSet,
            this, &MainProgram::runCopyMechanism, Qt::QueuedConnection);

    connect(&windowProgress,&MainWindow::timeToUmountDevice,
            this,&MainProgram::goToSleep, Qt::QueuedConnection);

    connect(this,&MainProgram::gotPath,this,
            &MainProgram::showVersionNumber, Qt::UniqueConnection);

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
    //this->showWindow();

    QString configFilePath = mountingPoint + QDir::separator()+"config.ini";

    QFile file(configFilePath);
    if(!file.exists())
    {
       // Logger::GetLogger()->Log("Config file on device not found. Returning..");
        return;
    }

    usleep(5000);

    emit gotPath(path);




    //ret ver
/*
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
*/
}



void MainProgram::showVersionNumber(QString path){

    //show version window
    versionWindow->initLabels(path); //usb Device path
    versionWindow->show();


}

void MainProgram::copyFilesFromUsb(){


}


void MainProgram::hideAndClose(){
    versionWindow->hide();
    windowProgress.close();

}

void MainProgram::runCopyMechanism(QString s, QString d){
    qDebug()<<QString("Source %1, Destination %1").arg(s).arg(d);
    //Logger::GetLogger()->operator<<("test");
    Logger::GetLogger()->Log("test");
    folderCopier->copy(s, d);
}


//find device, umount it and go to sleep
void MainProgram::goToSleep()
{

    //QProcess process;
    //process.start("umount " + usbReader->getMountedPartition() );
    //process.waitForFinished();
    //Logger::GetLogger()->Log("Unmounting status:"+ QString::number(process.exitStatus()));
    //Logger::GetLogger()->Log("Trying to reboot device");


    // system("reboot");
}



