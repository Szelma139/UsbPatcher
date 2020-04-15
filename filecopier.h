#ifndef FILECOPIER_H
#define FILECOPIER_H

#include <QObject>

class FileCopier
{
public:
    FileCopier(QString sourcePath, QString targetPath);
    void restartDevice();


private:
    QString m_sourcePath;
    QString m_targetPath;


    bool m_isFile;
    bool m_isFolder;

private:
    bool checkIfSourceDevExists();
    bool checkIfSourceFileExists(QString filepath)




};

#endif // FILECOPIER_H
