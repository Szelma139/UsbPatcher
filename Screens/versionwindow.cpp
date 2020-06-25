#include "versionwindow.h"
#include "ui_versionwindow.h"
#include <Constants/Constants.h>
#include <Functionality/versionchecker.h>
#include <Functionality/copyupdate.h>
#include <Functionality/copierthread.h>
#include <Screens/progressbarwindow.h>
#include <QDebug>

VersionWindow::VersionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VersionWindow)
{
    ui->setupUi(this);
    v=new VersionChecker;
    folderCopier = new CopierThread(this);
    windowProgress = new ProgressBarWindow(this);

    connect(folderCopier, &CopierThread::minimumChanged,
            windowProgress, &ProgressBarWindow::setProgressBarMin, Qt::QueuedConnection);

    connect(folderCopier, &CopierThread::maximumChanged,
            windowProgress, &ProgressBarWindow::setProgressBarMax, Qt::QueuedConnection);

    connect(folderCopier, &CopierThread::progressChanged,
            windowProgress, &ProgressBarWindow::setProgressBarValue, Qt::QueuedConnection);

    connect(folderCopier, &CopierThread::finishedUpdatingFiles,
            windowProgress, &ProgressBarWindow::warnAndReboot, Qt::QueuedConnection);


}


void VersionWindow::initLabels(QString source){

    qDebug()<<"Init labels " << 1;
    installedVncVersion = v->returVersion(Path::installedVnc);
    USBVncVersion  = v->returVersion(configFilePath +Path::USBDefaultVnc);           //SOFTWARE/hybryda/version.ini
    installedHybrydaVersion = v->returVersion(Path::installedHybryda);
    USBHybrydaVersion = v->returVersion(configFilePath +Path::USBDefaultHybryda);



    ui->labelVncUsb->setText(USBVncVersion);
    ui->labelHybrydaUsb->setText(USBHybrydaVersion);
    ui->labelHybrydaInstalled->setText(installedHybrydaVersion);
    ui->labelVncInstalled->setText(installedVncVersion);

    //connect()
                                            //dest, source, folderCopier
    hybrydaCopyUpdate = new CopyUpdate(Path::installedHybryda,source,folderCopier);
    vncCopyUpdate = new CopyUpdate(Path::installedVnc, source, folderCopier);

    connect(ui->buttonRemoveVnc, &QPushButton::clicked, vncCopyUpdate,&CopyUpdate::remove, Qt::UniqueConnection);
    connect(ui->buttonRestoreVnc, &QPushButton::clicked, vncCopyUpdate,&CopyUpdate::restore, Qt::UniqueConnection);
    connect(ui->buttonBackupVnc, &QPushButton::clicked, vncCopyUpdate, &CopyUpdate::backup, Qt::UniqueConnection);
    connect(ui->buttonUpdateVnc, &QPushButton::clicked, vncCopyUpdate, &CopyUpdate::update, Qt::UniqueConnection);

    connect(ui->buttonBackupHybryda, &QPushButton::clicked, hybrydaCopyUpdate, &CopyUpdate::backup, Qt::UniqueConnection);
    connect(ui->buttonRemoveHybryda, &QPushButton::clicked, hybrydaCopyUpdate, &CopyUpdate::remove, Qt::UniqueConnection);
    connect(ui->buttonUpdateHybryda, &QPushButton::clicked, hybrydaCopyUpdate, &CopyUpdate::update, Qt::UniqueConnection);
    connect(ui->buttonResotreHybryda,&QPushButton::clicked, hybrydaCopyUpdate, &CopyUpdate::restore, Qt::UniqueConnection);

}


VersionWindow::~VersionWindow()
{
    delete ui;
}

QString VersionWindow::getConfigFilePath() const
{
    return configFilePath;
}

void VersionWindow::setConfigFilePath(const QString value)
{
    configFilePath = value;

}

