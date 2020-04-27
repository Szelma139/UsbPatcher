#include "pathdetails.h"

#include <QSettings>
#include <QDir>
#include <QDebug>
#include <QFile>

PathDetails::PathDetails(QString confPath)
{
    m_configFilePath = confPath;
    qDebug()<<"Uzywany config to bedzie !!!!!!!!!!!!!!!!!" << m_configFilePath;
}


QString PathDetails::returnSourceFromConfig()
{
    QFile file(m_configFilePath);
    if(!file.exists()) qDebug()<<"Blad";
    QSettings settings(m_configFilePath, QSettings::IniFormat);

    QString source = settings.value("conf/Source").toString();
    qDebug()<<"SOURCE !!!!!!!! " << source;
    return source;

}

QString PathDetails::returnDestFromConfig()
{
    QFile file(m_configFilePath);
    if(!file.exists()) qDebug()<<"Blad";
    QSettings settings(m_configFilePath, QSettings::IniFormat);
    QString destination = settings.value("conf/Destination").toString();
    qDebug()<<"DESTINATION !!!!!!!! " << destination;

    return destination;
}


QStringList PathDetails::returnKillArguments()
{
    QStringList programKillList;
    int SIZE = 6;
    QFile file(m_configFilePath);
    if(!file.exists()) qDebug()<<"Blad";
    QSettings settings(m_configFilePath, QSettings::IniFormat);
    for (int i =1; i<SIZE;i++)
    {
        QString configProgram="conf/KillProgram"+QString::number(i);
        QString killProgram = settings.value(configProgram).toString();
        programKillList.append(killProgram);

    }

    return programKillList;
}

///
/// \brief PathDetails::createConf
/// \param srcPath
/// \param destPath
///
///create configuration file on usb Device
///
void PathDetails::createConf(QString srcPath, QString destPath)
{

  QSettings settings(m_configFilePath);
  settings.beginGroup("conf");
  settings.setValue("Source",srcPath);
  settings.setValue("Destination", destPath);
  settings.endGroup();

}


