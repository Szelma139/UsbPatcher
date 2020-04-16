QT += gui core network widgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG -= c++11 console
CONFIG -= app_bundlele

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS QT_DISABLE_DEPRECATED_BEFORE

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        drivewatcher.cpp \
        filecopier.cpp \
        filesmanage.cpp \
        main.cpp \
        mainwindow.cpp \
        mountingpoint.cpp \
        usbdevicediscover.cpp \
        usbreader.cpp \
        utilitytools.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


HEADERS += \
    drivewatcher.h \
    filecopier.h \
    filesmanage.h \
    mainwindow.h \
    mountingpoint.h \
    usbdevicediscover.h \
    usbreader.h \
    utilitytools.h

FORMS += \
    mainwindow.ui
