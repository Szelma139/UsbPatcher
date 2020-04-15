#ifndef MOUNTINGPOINT_H
#define MOUNTINGPOINT_H

#include <QString>

class MountingPoint
{
public:
    MountingPoint();


private:

    QString returnMountingPath(QString mountPointLine );
    void getMountPointLineFroFil(QString partitionName);

;

};

#endif // MOUNTINGPOINT_H
