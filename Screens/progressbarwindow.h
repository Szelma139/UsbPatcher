#ifndef PROGRESSBARWINDOW_H
#define PROGRESSBARWINDOW_H

#include <QMainWindow>
#include <QFileSystemWatcher>


class UsbReader;
namespace Ui {
class ProgressBarWindow;
}

class ProgressBarWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProgressBarWindow(QWidget *parent = nullptr);
    ~ProgressBarWindow();


private:
    Ui::ProgressBarWindow *ui;

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

#endif // PROGRESSBARWINDOW_H
