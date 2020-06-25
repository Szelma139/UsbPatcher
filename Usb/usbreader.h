#ifndef USBREADER_H
#define USBREADER_H


#include <QObject>
#include <QStorageInfo>



class QStorageInfo;
class UsbReader: public QObject
{
    Q_OBJECT
public:
    UsbReader(QObject * parent);
    void findNewDrive();

    void findMountingPoint(QString partitionName);


    QString getMountedPartition() const;
    void setMountedPartition(const QString &value);

private:
    QByteArray getLastKnownElement(QList<QStorageInfo>info);
    void showListElements(QList<QStorageInfo> list);
    QString mountedPartition;


public slots:
    void fetchMountingPoint();


signals:
    void returnPath(QString);
};

#endif // USBREADER_H
