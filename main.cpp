﻿#include <mainwindow.h>
#include <QApplication>
#include <filesmanage.h>
#include <mainprogram.h>
#include <QSettings>
#include <QDebug>
#include <parameters.h>



void copy(QString sourcePath)
{
  /*  CopierThread t;
    QString destinationFolder = "/opt/pliki/pliki2/";
    QString source = sourcePath + QDir::separator() + "duzyfolder";



t.copy(source,destinationFolder);

*/
}




int main(int argc, char ** argv){

QApplication a(argc,argv);

//int 0 open app
//int 1 only createFile
int t = 0;

/*switch (t)
{
case 0:
{


}
    break;

case 1:
{
    //createConfigFile();
        return a.exec();
}


break;

*/

MainProgram m;
//m.setFolderToCopy("duzyfolder");
m.copyFilesFromUsb();
return a.exec();
}








//changeConfigFile();
/*

MainWindow * w = new MainWindow;
UsbReader * r = new UsbReader;

QObject::connect(r,SIGNAL(showWindow()), &a,SLOT(showWindow()));
QObject::connect(r,SIGNAL(returnPath(QString)),&a,SLOT(copy(QString)));
r->start();

FilesManage m;
m.getListOfFilInDir("/media/radek/KARTA USB");
//w.show();
*/

//}


