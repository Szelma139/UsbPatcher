#include "scriptexecutor.h"
#include <QProcess>
#include <QDebug>
#include <QFile>
#include <QDir>

ScriptExecutor::ScriptExecutor(QObject * parent)
    :QObject(parent)
{

}


void ScriptExecutor::executeScript(QString filename, QString path){


    QString filepath = returnRealPath(filename, path);

    if (filepath == "null") {qDebug()<<"Wrong filepath";return;}


    QProcess process;
  //  process.startDetached("/bin/sh", QStringList()<< filepath);

    process.startDetached("/bin/sh",QStringList()<< "sudo ."<<  filepath);
    process.waitForFinished();
    qDebug()<<"Process code "<< process.exitCode();

}


QString ScriptExecutor::returnRealPath(QString filename, QString path)
{
    QFile file;
    QString tempPath = filename + path;
    file.setFileName(tempPath);
    if(file.exists()) {

        qDebug()<< QString("Path is good, we can proceed, filepath set to %1")
                   .arg(tempPath);

        return tempPath;
    }
    else
    {
        tempPath=filename + QDir::separator() + filename;
        file.setFileName(tempPath);
        if (file.exists()){
            qDebug()<<QString("Path was fixed, returning correct Path")
                      .arg(tempPath);

            return tempPath;
        }
        else {return "null"; qDebug()<<"Path might be the problem";}
    }


}
