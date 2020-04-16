#include <QCoreApplication>
#include <mainwindow.h>
#include <usbreader.h>
#include <QApplication>
#include <filesmanage.h>




int main(int argc, char ** argv){

    QApplication a(argc,argv);
MainWindow w;
UsbReader * r = new UsbReader;
r->start();

FilesManage m;
m.getListOfFilInDir("/media/radek/KARTA USB");
//w.show();

    return a.exec();
}
