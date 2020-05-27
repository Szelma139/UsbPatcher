#include "Logger.h"
#include "Logger.h"

#include <QDateTime>

const QString CLogger::m_sFileName = "Log.txt";
CLogger* CLogger::m_pThis = NULL;
QFile CLogger::m_Logfile;
QTextStream CLogger::stream;
CLogger::CLogger()
{

    m_Logfile.setFileName(m_sFileName);
    m_Logfile.open(QIODevice::OpenModeFlag::ReadWrite);



}
CLogger* CLogger::GetLogger(){

    if (m_pThis == NULL){
        m_pThis = new CLogger();

        return m_pThis;
    }
}



void CLogger::Log(const QString & sMessage)
{
    stream << QDateTime::currentDateTime().toString() << ":\t";
    stream << sMessage << "\n";
}

CLogger& CLogger::operator<<(const QString& sMessage)
{
    stream << "\n" << QDateTime::currentDateTime().toString() << ":\t";
    stream << sMessage << "\n";
    return *this;
}

