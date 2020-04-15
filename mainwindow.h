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
    UsbReader * reader;


private slots:
    void showPort(QString path);

    void showChanges(QString changes);


};

#endif // MAINWINDOW_H
