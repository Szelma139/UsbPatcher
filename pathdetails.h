#ifndef PATHDETAILS_H
#define PATHDETAILS_H

#include <QString>
#include <QObject>

class PathDetails
{
public:
    PathDetails(QString confPath );
    QString returnSourceFromConfig();
    QString returnDestFromConfig();
    void createConf(QString srcPath, QString destPath);
    QStringList returnKillArguments();



private:
    QString m_configFilePath;
};

#endif // PATHDETAILS_H
