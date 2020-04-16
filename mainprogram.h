#ifndef MAINPROGRAM_H
#define MAINPROGRAM_H

#include <QObject>


#include <mainwindow.h>


class CopierThread;
class UsbReader;
class MainProgram : public QObject
{

    Q_OBJECT

public:
    MainProgram(QObject * parent = nullptr);


    QString getFolderToCopy() const;
    void setFolderToCopy(const QString &value);
    void copyFilesFromUsb();

   private:
    void showWindow();
    void getPathToFiles(QString);




private:
    MainWindow * windowProgress;

    QString path;
    QString folderToCopy = "duzyfolder";
    UsbReader * usbReader;
    CopierThread * folderCopier;
};

#endif // MAINPROGRAM_H
