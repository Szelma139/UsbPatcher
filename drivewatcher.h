#ifndef DRIVEWATCHER_H
#define DRIVEWATCHER_H

#include <QThread>
#include <QList>
#include <QStorageInfo>

class QFileSystemWatcher;
class DriveWatcher: public QThread
{
    Q_OBJECT
public:
    DriveWatcher(QObject * parent = nullptr);

    QFileSystemWatcher * usbDirWatcher;

private:
    QList<QStorageInfo> lastKnownListOfDrives;


private slots:
    void spottedChangesOnDrive(QString folder);
    void findNewDrive();

private:
    QByteArray getLastKnownElement(QList<QStorageInfo>info);


protected:
    void run();

signals:
    void foundNewUsbDev(QString);

};

#endif // DRIVEWATCHER_H
