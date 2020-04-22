#include <mainwindow.h>
#include <QApplication>
#include <filesmanage.h>
#include <mainprogram.h>
#include <QSettings>
#include <QDebug>



void copy(QString sourcePath)
{
  /*  CopierThread t;
    QString destinationFolder = "/opt/pliki/pliki2/";
    QString source = sourcePath + QDir::separator() + "duzyfolder";



t.copy(source,destinationFolder);

*/
}


void createConfigFile()
{

    QSettings * settings = new QSettings("/media/radek/KARTA\ USB/config.ini", QSettings::IniFormat);
    settings->beginGroup("conf");
    settings->setValue("Source","siostramalgosia");
    settings->setValue("Destination","/opt/pliki/pliki2/rabarbar");
    settings->endGroup();
    qDebug()<<"Zapisano";
}

int main(int argc, char ** argv){

QApplication a(argc,argv);



MainProgram m;
//m.setFolderToCopy("duzyfolder");
m.copyFilesFromUsb();





//changeConfigFile();
return a.exec();
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

}


