#include <QCoreApplication>
#include <mainwindow.h>
#include <usbreader.h>
#include <QApplication>
#include <filesmanage.h>

#include <copierthread.h>
#include <QObject>


void showWindow(MainWindow * w)
{
w->show();
}


void copy(QString sourcePath)
{
    CopierThread t;
    QString destinationFolder = "/opt/pliki/pliki2/";
    QString source = sourcePath + QDir::separator() + "duzyfolder";
    t.copy(source,destinationFolder);
}

int main(int argc, char ** argv){

    QApplication a(argc,argv);
MainWindow * w = new MainWindow;
UsbReader * r = new UsbReader;

QObject::connect(r,SIGNAL(showWindow()), &a,SLOT(showWindow()));
QObject::connect(r,SIGNAL(returnPath(QString)),&a,SLOT(copy(QString)));
r->start();

FilesManage m;
m.getListOfFilInDir("/media/radek/KARTA USB");
//w.show();

    return a.exec();
}


