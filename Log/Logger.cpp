#include "Logger.h"

#include <QDateTime>
#include <QDebug>
#include <QFileInfo>
#include <QDataStream>

//QString Logger::path="";
//const QString Logger::m_sFileName = "Log.txt";
Logger* Logger::m_pThis = NULL;
//QFile Logger::m_Logfile;
//QTextStream Logger::stream(&Logger::m_Logfile);
QTextStream * Logger::stream = NULL;

Logger::Logger(){

    m_sFileName = "/home/radek/Dokumenty/Log.txt";
    m_Logfile.setFileName(m_sFileName);
    m_Logfile.open(QIODevice::ReadWrite);
    Logger::stream = new QTextStream(&m_Logfile);

    if (!m_Logfile.exists()){
        qDebug()<<"Plik do logowania nie istnieje";} else
    {
        qDebug()<<"Plik istnieje";
        QFileInfo info(Logger::m_Logfile);
        qDebug()<<"Absolute file path " << info.absoluteFilePath();
    }


}

Logger* Logger::GetLogger(){

    if (m_pThis == NULL){
        m_pThis = new Logger();

       // return m_pThis;
    }
    return m_pThis;
}

void Logger::Log(const QString & sMessage){
  //  QDataStream stream(&m_Logfile);
   // stream<<"dupa";
    *Logger::stream<<"test";
    //*Logger::stream << QDateTime::currentDateTime().toString() << ":\t";
    //*Logger::stream << sMessage << "\n";
    qDebug()<<"Trying to log"<<sMessage<<"time"<<QDateTime::currentDateTime().toString();
}

/*
Logger& Logger::operator<<(const QString& sMessage){
    *Logger::stream << "\n" << QDateTime::currentDateTime().toString() << ":\t";
    *Logger::stream << sMessage << "\n";
    qDebug()<<"Trying to log"<<sMessage<<"time"<<QDateTime::currentDateTime().toString();
    return *this;
}
*/

void Logger::setPath(QString path){

   // Logger::path=path;
}

