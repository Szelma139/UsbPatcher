#ifndef COPYUPDATE_H
#define COPYUPDATE_H

#include <QObject>

class CopyUpdate: public QObject
{
    Q_OBJECT
public:
    CopyUpdate(QString dirContent);
    QString getSourceFolder() const;
    void setSourceFolder(const QString &value);

public slots:

    void copy();
    void update();
    void remove();
    void restore();



private:
    QString sourceFolder;
    QString destFolder;
};

#endif // COPYUPDATE_H
