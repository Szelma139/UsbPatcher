#ifndef Logger_H
#define Logger_H
#include <QFile>
#include <QString>
#include <QTextStream>
#define LOGGER Logger::GetLogger()

class Logger
{
public:

    void Log(const QString &sMessage);

    //Logger& operator<<(const QString &sMessage);


    static Logger* GetLogger();
    void setPath(QString path);

private:

    Logger();

    Logger(const Logger&){};

    Logger& operator=(const Logger&){ return *this; };

    //QString m_sFileName;

    QString  m_sFileName;
    static Logger* m_pThis;

    QFile m_Logfile;

    static QTextStream * stream;

    QString path;

};
#endif
