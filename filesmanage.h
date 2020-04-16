#ifndef FILESMANAGE_H
#define FILESMANAGE_H

#include <QFileInfoList>

class FilesManage
{
public:
    FilesManage();
    void getListOfFilInDir(QString directoryRoot);
    void getListReadableForm(QFileInfoList list);


};

#endif // FILESMANAGE_H
