#include "confreader.h"

#include <QSettings>
#include <QDir>

ConfReader::ConfReader(QString confPath)
{
    m_configFilePath = confPath;
}






QString ConfReader::returnSourceFromConfig()
{

    QSettings settings(m_configFilePath);
    QString source = settings.value("conf/Source").toString();
    return source;

}

QString ConfReader::returnDestFromConfig()
{
    QSettings settings(m_configFilePath);
    QString source = settings.value("conf/Destination").toString();
    return source;
}
