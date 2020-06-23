#include "versionwindow.h"
#include "ui_versionwindow.h"
#include <Constants/Constants.h>
#include <Functionality/versionchecker.h>
#include <Functionality/copyupdate.h>

#include <QDebug>

VersionWindow::VersionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VersionWindow)
{
    ui->setupUi(this);
    v=new VersionChecker;



}


void VersionWindow::initLabels(){


    installedVncVersion = v->returVersion(Path::installedVnc);
    USBVncVersion  = v->returVersion(configFilePath +Path::USBDefaultVnc);           //SOFTWARE/hybryda/version.ini
    installedHybrydaVersion = v->returVersion(Path::installedHybryda);
    USBHybrydaVersion = v->returVersion(configFilePath +Path::USBDefaultHybryda);



    ui->labelVncUsb->setText(USBVncVersion);
    ui->labelHybrydaUsb->setText(USBHybrydaVersion);
    ui->labelHybrydaInstalled->setText(installedHybrydaVersion);
    ui->labelVncInstalled->setText(installedVncVersion);

    //connect()

    hybrydaCopyUpdate = new CopyUpdate(Path::installedHybryda);
    vncCopyUpdate = new CopyUpdate(Path::installedVnc);


    connect(ui->buttonRemoveVnc,&QPushButton::clicked,vncCopyUpdate,&CopyUpdate::remove);
    connect(ui->buttonRestoreVnc,&QPushButton::clicked,vncCopyUpdate,&CopyUpdate::restore);
    connect(ui->buttonUpdateVnc,&QPushButton::clicked,vncCopyUpdate,&CopyUpdate::update);
    connect(ui->buttonBackupVnc,&QPushButton::clicked,vncCopyUpdate,&CopyUpdate::backup);

    connect(ui->buttonBackupHybryda, &QPushButton::clicked, hybrydaCopyUpdate,&CopyUpdate::backup);
    connect(ui->buttonRemoveHybryda, &QPushButton::clicked, hybrydaCopyUpdate,&CopyUpdate::remove);
    connect(ui->buttonUpdateHybryda, &QPushButton::clicked, hybrydaCopyUpdate, &CopyUpdate::update);
    connect(ui->buttonResotreHybryda,&QPushButton::clicked, hybrydaCopyUpdate, &CopyUpdate::restore);
}


VersionWindow::~VersionWindow()
{
    delete ui;
}

QString VersionWindow::getConfigFilePath() const
{
    return configFilePath;
}

void VersionWindow::setConfigFilePath(const QString &value)
{
    configFilePath = value;
}
