#ifndef PROGRAMKILLER_H
#define PROGRAMKILLER_H

#include <QObject>

class ProgramKiller: public QObject
{
public:
    ProgramKiller(QObject * parent, QString config);



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
