#include "filesmanage.h"


#include <QDir>
#include <QDebug>

FilesManage::FilesManage()
{

}


 void FilesManage::getListOfFilInDir(QString directoryRoot)
{
    QDir directory(directoryRoot);
    if (directory.exists())
    {
        QFileInfoList listOfFiles = directory.entryInfoList();

        for (QFileInfo info:listOfFiles)
        {
            if (info.baseName()!="")
            {

                qDebug()<<"Basename: " << info.baseName()<<"isFile:"<<info.isFile();
                qDebug()<<"isDir: "<<info.isDir();
                qDebug()<<"Path: " << info.path()<<"AbsolutePath:"<<info.absolutePath();
                if(info.isDir() && !info.isFile()){
                   getListOfFilInDir(info.absolutePath()+"/"+info.baseName());
                   qDebug()<<"Basename: " << info.baseName()<<"isFile:"<<info.isFile();
                   qDebug()<<"isDir: "<<info.isDir();
                   qDebug()<<"Path: " << info.path()<<"AbsolutePath:"<<info.absolutePath();
                }
            }

        }

    }

}


 void getStringListInfo(QString type)
 {

 }

 void FilesManage::getListReadableForm(QFileInfoList list)
 {

 }
