#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemWatcher>


class UsbReader;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

    QFileSystemWatcher * watcher;

    void runCopyMechanism(QString src, QString dst);

public slots:

    void setProgressBarValue(double value);
    void setProgressBarMin(double min);
    void setProgressBarMax(double max);
    void warnAndReboot();


signals:
void timeToUmountDevice();
};

#endif // MAINWINDOW_H
