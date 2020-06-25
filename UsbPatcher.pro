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
        Functionality/copyupdate.cpp \
        Functionality/driveswitcher.cpp \
        Log/Logger.cpp \
        Screens/progressbarwindow.cpp \
        Screens/versionwindow.cpp \
        Functionality/copierthread.cpp \
        Functionality/filecopier.cpp \
        Usb/pathdetails.cpp \
        Usb/usbnotifications.cpp \
        main.cpp \
        mainprogram.cpp \
        mainwindow.cpp \
        Functionality/readconfig.cpp \
        Functionality/scriptexecutor.cpp \
        Usb/usbreader.cpp \
        Functionality/versionchecker.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


HEADERS += \
    Constants/Constants.h \
    Functionality/copyupdate.h \
    Functionality/driveswitcher.h \
    Log/Logger.h \
    Screens/progressbarwindow.h \
    Screens/versionwindow.h \
    Functionality/copierthread.h \
    Functionality/filecopier.h \
    Usb/pathdetails.h \
    Usb/usbnotifications.h \
    mainprogram.h \
    mainwindow.h \
    Usb/mountingpoint.h \
    Functionality/programkiller.h \
    Functionality/readconfig.h \
    Functionality/scriptexecutor.h \
    Usb/usbreader.h \
    Functionality/versionchecker.h

FORMS += \
    Screens/progressbarwindow.ui \
    Screens/versionwindow.ui \
    mainwindow.ui




include(QtUsb/src/usb/files.pri)



