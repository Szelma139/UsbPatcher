#ifndef VERSIONWINDOW_H
#define VERSIONWINDOW_H

#include <QMainWindow>

namespace Ui {
class VersionWindow;
}
class ProgressBarWindow;
class CopierThread;
class CopyUpdate;
class VersionChecker;

class VersionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit VersionWindow(QWidget *parent = nullptr);
    ~VersionWindow();

    QString getConfigFilePath() const;
    void setConfigFilePath(QString value);

    void initLabels(QString source);

private:
    Ui::VersionWindow *ui;
    VersionChecker * v;
    CopyUpdate * vncCopyUpdate;
    CopyUpdate * hybrydaCopyUpdate;
    CopierThread * folderCopier;
    ProgressBarWindow * windowProgress;




private:
    QString installedVncVersion;
    QString USBVncVersion;
    QString installedHybrydaVersion;
    QString USBHybrydaVersion;
    QString configFilePath;
};

#endif // VERSIONWINDOW_H
