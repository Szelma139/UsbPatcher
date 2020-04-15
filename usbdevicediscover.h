#ifndef USBDEVICEDISCOVER_H
#define USBDEVICEDISCOVER_H

#include <QObject>

class UsbDeviceDiscover
{
public:
    UsbDeviceDiscover();
     void getUsbDevice();

     QString getDevice_name() const;
     void setDevice_name(const QString &device_name);

private:
     QString m_device_name;

signals:
     void newUsbDevice(QString device);

};

#endif // USBDEVICEDISCOVER_H
