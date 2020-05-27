#ifndef CUSTOM_CLogger_H
#define CUSTOM_CLogger_H
#include <QFile>
#include <QString>
#include <QTextStream>
#define LOGGER CLogger::GetLogger()

class CLogger
{
public:

    void Log(const QString &sMessage);

    CLogger& operator<<(const QString &sMessage);

	static CLogger* GetLogger();

private:

	CLogger();

    CLogger(const CLogger&){};

    CLogger& operator=(const CLogger&){ return *this; };

    static const QString m_sFileName;

	static CLogger* m_pThis;

    static QFile m_Logfile;
    static QTextStream stream;
};
#endif
