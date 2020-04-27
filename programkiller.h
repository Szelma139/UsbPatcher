#ifndef PROGRAMKILLER_H
#define PROGRAMKILLER_H

#include <QObject>

class ProgramKiller
{
public:
    ProgramKiller(QString config);



public:
    void startKillingLoop();
    void setProgramsToKill();


private:
     void killProgram(QString  &programName);


private:
     QStringList programToKill;
     QString configFilePath;

};

#endif // PROGRAMKILLER_H
