QT += gui core network widgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 console
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
        main.cpp \
        mainwindow.cpp \
        usbdevicediscover.cpp \
        usbreader.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Wideo/lib/release/ -lusb-1.0
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Wideo/lib/debug/ -lusb-1.0
else:unix: LIBS += -L$$PWD/../Wideo/lib/ -lusb-1.0

INCLUDEPATH += $$PWD/../Wideo/include
DEPENDPATH += $$PWD/../Wideo/include

HEADERS += \
    mainwindow.h \
    usbdevicediscover.h \
    usbreader.h

FORMS += \
    mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Obrazy/libusbp/build/release/ -lusbp-1
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Obrazy/libusbp/build/debug/ -lusbp-1
else:unix: LIBS += -L$$PWD/../Obrazy/libusbp/build/ -lusbp-1

INCLUDEPATH += $$PWD/../Obrazy/libusbp/include
DEPENDPATH += $$PWD/../Obrazy/libusbp/include
