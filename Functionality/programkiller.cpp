#include "programkiller.h"

#include <QProcess>
#include <Usb/pathdetails.h>
#include <QDebug>
#include <Log/Logger.h>

ProgramKiller::ProgramKiller(QObject * parent, QString config):
    QObject(parent)
{
    configFilePath = config;
    qDebug()<<"uzywam configa"<<configFilePath;
}


void ProgramKiller::setProgramsToKill( )
{
    PathDetails d(configFilePath);
    programToKill = d.returnKillArguments();

    for (QString program:programToKill)
    {
     qDebug()<<QString("Program %1 will be killed").arg(program);
    }
}



void ProgramKiller::startKillingLoop()
{
    if (!programToKill.isEmpty())
    {
        for (QString program: programToKill)
        {

            killProgram(program);
        }
    }
    else
        return;
}

void ProgramKiller::killProgram(QString &programName)
{

    QProcess process;
    process.start("pkill "+ programName);
    process.waitForFinished();
    qDebug()<<"Killing process"<<programName;
    Logger::GetLogger()->Log("Trying to kill" +QString::number(process.exitStatus()));

}
