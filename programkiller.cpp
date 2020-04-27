#include "programkiller.h"

#include <QProcess>
#include <pathdetails.h>

ProgramKiller::ProgramKiller(QString config)
{
configFilePath = config;
}


void ProgramKiller::setProgramsToKill( )
{
PathDetails d(configFilePath);
programToKill = d.returnKillArguments();
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

void ProgramKiller::killProgram(QString  &programName)
{

    QProcess process;
    process.start("pkill "+ programName);
    process.waitForFinished();

}
