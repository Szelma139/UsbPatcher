#ifndef USBNOTIFICATIONS_H
#define USBNOTIFICATIONS_H

#include <QObject>
#include "qusbdevice.h"

class QUsbInfo;
class UsbNotifications: public QObject
{
    Q_OBJECT
public:
    UsbNotifications(QObject * parent);


public slots:
    void onDeviceInserted(QUsbDevice::Id id);
    void onDeviceRemoved(QUsbDevice::Id id);

private:
    QUsbInfo * m_usb_info;

    signals:
    void insertedUsbDevice();
    void removedUsbDevice();
};

#endif // USBNOTIFICATIONS_H
