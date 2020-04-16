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

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QFileSystemWatcher * watcher;

public slots:

    void setProgressBarValue(double value);
    void setProgressBarMin(double min);
    void setProgressBarMax(double max);

    void warnAndReboot();
};

#endif // MAINWINDOW_H
