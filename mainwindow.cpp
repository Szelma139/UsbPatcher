#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <usbdevicediscover.h>
#include <QDebug>


#include <usbreader.h>

#include <QMessageBox>
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
   // QString path = "/dev/";
   // watcher = new QFileSystemWatcher(this);
   // watcher->addPath(path);

   // connect(watcher,SIGNAL(directoryChanged(QString)), this, SLOT(showPort(QString)));
    //reader = new UsbReader();

   // connect(reader,SIGNAL(spottedChanges(QString)),this,SLOT(showChanges(QString)));
    //reader->start();

}



void MainWindow::setProgressBarValue(double value)
{
    ui->progressBar->setValue(value);
}
void MainWindow::setProgressBarMin(double min)
{

    ui->progressBar->setMinimum(min);
}
void MainWindow::setProgressBarMax(double max)
{
    ui->progressBar->setMaximum(max);
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


void MainWindow::warnAndReboot()
{

    QMessageBox msg;
    msg.setText("NASTAPI RESET URZADZENIA");
    msg.show();

    usleep(8000);


    //system("reboot");

}



void MainWindow::on_pushButton_2_clicked()
{
    QString mainRoot = "/media/radek/KARTA\ USB/";
    QFileSystemModel * model = new QFileSystemModel;
    model->setRootPath(mainRoot);

    ui->treeView->setModel(model);
ui->treeView->setRootIndex(model->index(mainRoot));

}
