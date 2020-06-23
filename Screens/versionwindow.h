#ifndef VERSIONWINDOW_H
#define VERSIONWINDOW_H

#include <QMainWindow>

namespace Ui {
class VersionWindow;
}


class CopyUpdate;
class VersionChecker;
class VersionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit VersionWindow(QWidget *parent = nullptr);
    ~VersionWindow();

    QString getConfigFilePath() const;
    void setConfigFilePath(const QString &value);

    void initLabels();

private:
    Ui::VersionWindow *ui;
    VersionChecker * v;
    CopyUpdate * vncCopyUpdate;
    CopyUpdate * hybrydaCopyUpdate;




private:
    QString installedVncVersion;
    QString USBVncVersion;
    QString installedHybrydaVersion;
    QString USBHybrydaVersion;

    QString configFilePath;
};

#endif // VERSIONWINDOW_H
