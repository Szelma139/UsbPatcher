#ifndef FILECOPIER_H
#define FILECOPIER_H

#include <QObject>

class FileCopier
{
public:
    FileCopier(QString sourcePath);
    void restartDevice();
    void copyFilesTo(QString targetPath);

private:
    QString m_sourcePath;
    QString targetFolder;




    bool m_isFile;
    bool m_isFolder;

private:
    bool checkIfSourceDevExists();
    bool checkIfSourceFileExists(QString filepath);




};

#endif // FILECOPIER_H
