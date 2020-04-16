#ifndef CONFREADER_H
#define CONFREADER_H

#include <QString>

class ConfReader
{
public:
    ConfReader(QString confPath );
    QString returnSourceFromConfig();


    QString returnDestFromConfig();


private:
    QString m_configFilePath;
};

#endif // CONFREADER_H
