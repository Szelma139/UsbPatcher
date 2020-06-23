#include "progressbarwindow.h"
#include "ui_progressbarwindow.h"

#include <QDebug>


#include <Usb/usbreader.h>

#include <QMessageBox>
#include <unistd.h>

ProgressBarWindow::ProgressBarWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProgressBarWindow)
{

    ui->setupUi(this);

}


void ProgressBarWindow::setProgressBarValue(double value)
{
    ui->progressBar->setValue(value);
}
void ProgressBarWindow::setProgressBarMin(double min)
{

    ui->progressBar->setMinimum(min);
}
void ProgressBarWindow::setProgressBarMax(double max)
{
    ui->progressBar->setMaximum(max);
}

ProgressBarWindow::~ProgressBarWindow()
{
    delete ui;
}


void ProgressBarWindow::warnAndReboot()
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
