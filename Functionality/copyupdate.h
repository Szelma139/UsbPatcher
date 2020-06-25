#ifndef COPYUPDATE_H
#define COPYUPDATE_H

#include <QObject>

class CopierThread;
class CopyUpdate: public QObject
{
    Q_OBJECT
public:
    CopyUpdate(QString dirContent, QString source, CopierThread * copier);
    QString getSourceFolder() const;
    void setSourceFolder(const QString &value);

    QString getDestFolder() const;
    void setDestFolder(const QString &value);

public slots:

    void backup();
    void update();
    void remove();
    void restore();




private:
    QString sourceFolder;
    QString destFolder;
    CopierThread * copier;

};

#endif // COPYUPDATE_H
