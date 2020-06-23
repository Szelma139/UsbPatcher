#ifndef SCRIPTEXECUTOR_H
#define SCRIPTEXECUTOR_H

#include <QObject>

class ScriptExecutor: public QObject
{
public:
    ScriptExecutor(QObject * parent);
    void executeScript(QString filename, QString path);

private:
    QString returnRealPath(QString filename, QString path);

};

#endif // SCRIPTEXECUTOR_H
