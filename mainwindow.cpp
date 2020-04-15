#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <usbdevicediscover.h>
#include <QDebug>


#include <usbreader.h>

#include <stdio.h>
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString path = "/dev/";
    watcher = new QFileSystemWatcher(this);
    watcher->addPath(path);

    connect(watcher,SIGNAL(directoryChanged(QString)), this, SLOT(showPort(QString)));
    reader = new UsbReader();

    connect(reader,SIGNAL(spottedChanges(QString)),this,SLOT(showChanges(QString)));
    reader->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//reader->start();
}

void MainWindow::showChanges(QString changes)
{
    qDebug()<<QString("Changes in folder: %1 \n").arg(changes);
    UsbDeviceDiscover r;
    //r.

//system("/home/radek/scripts_bash/usb_list_devices.sh");


}



void MainWindow::showPort(QString path)
{
    UsbDeviceDiscover r;
    //r.getUsbDevice();
  //  qDebug()<<r.getUsbDevice();
   // qDebug()<<r.getDevice_name();
}
