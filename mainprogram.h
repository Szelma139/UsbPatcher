#ifndef MAINPROGRAM_H
#define MAINPROGRAM_H

#include <QObject>


#include <mainwindow.h>
#include <Usb/parameters.h>
#include <Screens/versionwindow.h>


class ReadConfig;
class CopierThread;
class UsbReader;
class ProgramKiller;
class ScriptExecutor;

class MainProgram : public QObject
{

    Q_OBJECT

public:
    MainProgram();


    QString getFolderToCopy() const;
    void setFolderToCopy(const QString &value);
    void copyFilesFromUsb();


   private:
    void showWindow();


private slots:
    void getPathToFiles(QString);
    void runCopyMechanism(QString s, QString d);




private:
    MainWindow windowProgress;

    QString path;
    QString folderToCopy = "duzyfolder";
    QString destinationFolder = "/opt/pliki/pliki2/";
    UsbReader * usbReader;
    CopierThread * folderCopier;
    ReadConfig * reader;
    ProgramKiller * programKiller;
    ScriptExecutor * scriptexecutor;
    VersionWindow * versionWindow;

public slots:
    void goToSleep();
    void showVersionNumber(QString); //string path usb


signals:
    void gotPath(QString);
};

#endif // MAINPROGRAM_H
