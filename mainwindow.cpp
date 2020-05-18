#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>


#include <usbreader.h>

#include <QMessageBox>
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

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


void MainWindow::warnAndReboot()
{
    ui->progressBar->setValue(ui->progressBar->maximum());
    QMessageBox msg;
    msg.setText("NASTAPI RESET URZADZENIA");
    msg.show();

    usleep(8000);


    emit timeToUmountDevice();
    //emit signal umount and system reboot
    //odmontuj urzadzenie

}
