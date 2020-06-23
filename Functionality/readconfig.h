#ifndef READCONFIG_H
#define READCONFIG_H

#include <QObject>

class ReadConfig: public QObject
{
    Q_OBJECT
public:
    ReadConfig(QObject * parent);

signals:
    void copyPathsSet(QString src, QString dst);


public:
    void readConfPaths(QString src, QString mountPoint);
};

#endif // READCONFIG_H
