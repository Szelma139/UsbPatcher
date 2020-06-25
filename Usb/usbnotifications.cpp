#include "usbnotifications.h"

#include <qusbdevice.h>
#include <qusbinfo.h>

UsbNotifications::UsbNotifications(QObject * parent)
    :QObject(parent)
{
    m_usb_info = new QUsbInfo(this);
    connect(m_usb_info, &QUsbInfo::deviceInserted,
            this, &UsbNotifications::onDeviceInserted);
    connect(m_usb_info, &QUsbInfo::deviceRemoved,
            this, &UsbNotifications::onDeviceRemoved);

}

void UsbNotifications::onDeviceInserted(QUsbDevice::Id id){

    qInfo("Device inserted: %04x:$04x", id.vid, id.pid);
    qDebug()<<id.bus<<id.port;
    qDebug()<<id.vid<<id.pid;
    emit insertedUsbDevice();
}

void UsbNotifications::onDeviceRemoved(QUsbDevice::Id id){

    qInfo("Device removed: %04x:$04x", id.vid, id.pid);
    emit removedUsbDevice();

}

