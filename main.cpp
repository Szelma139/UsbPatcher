#include <QCoreApplication>
#include <usbdevicediscover.h>
#include <QApplication>
#include <mainwindow.h>
#include <libusbp-1/libusbp.hpp>
#include <iostream>
#include <iomanip>
#include "libusb-1.0/libusb.h"
#include <usbreader.h>
#include <QApplication>



/*

std::string serial_number_or_default(const libusbp::device & device,
    const std::string & def)
{
    try
    {
        return device.get_seriQCoreApplicational_number();
    }
    catch (const libusbp::error & error)
    {
        if (error.has_code(LIBUSBP_ERROR_NO_SERIAL_NUMBER))
        {
            return def;
        }
        throw;
    }
}

void print_device(libusbp::device & device)
{
    uint16_t vendor_id = device.get_vendor_id();
    uint16_t product_id = device.get_product_id();
    uint16_t revision = device.get_revision();
    std::string serial_number = serial_number_or_default(device, "-");
    std::string os_id = device.get_os_id();

    // Note: The serial number might have spaces in it, so it should be the last
    // field to avoid confusing programs that are looking for a field after the
    // serial number.

    std::ios::fmtflags flags(std::cout.flags());
    std::cout
        << std::hex << std::setfill('0') << std::right
        << std::setw(4) << vendor_id
        << ':'
        << std::setw(4) << product_id
        << ' '
        << std::setfill(' ') << std::setw(2) << (revision >> 8)
        << '.'
        << std::setfill('0') << std::setw(2) << (revision & 0xFF)
        << ' '
        << os_id
        << ' '
        << std::setfill(' ') << std::left << serial_number
        << std::endl;
    std::cout.flags(flags);
}

int main_with_exceptions()
{
    std::vector<libusbp::device> list = libusbp::list_connected_devices();
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        print_device(*it);
    }
    return 0;
}

int main(int argc, char ** argv)
{
    // Suppress unused parameter warnings.
    (void)argc;
    (void)argv;

    try
    {
        return main_with_exceptions();
    }
    catch(const std::exception & error)
    {
        std::cerr << "Error: " << error.what() << std::endl;
    }
    return 1;
}

*/



/*
int main(int argc, char **argv) {


    QApplication a(argc, argv);




    MainWindow w;
    w.show();
    return a.exec();
}
*/



/*
mount point znajduje sie w /dev/disk/by-id

jesli folder zawiera usb w nazwie to jest pendrivem
*/



/*
 *
 * libusb_contUsbReader * r = new UsbReader();
r->start();ext * context = NULL;
    libusb_device ** list = NULL;
    int rc = 0;
    ssize_t count = 0;

    rc = libusb_init(&context);QCoreApplication
    assert(rc == 0); //assert gdy warunek przyjmie blad wypisywany jest
    //komunikaat z argumentem makra czyli rc.

    count = libusb_get_device_list(context, &list);
    assert(count > 0);

    for (size_t idx = 0;idx < count; ++idx){
        libusb_device * device = list[idx];
        libusb_device_descriptor desc = {0};

        rc = libusb_get_device_descriptor(device, &desc);

        printf("Vendor:Device = %04x:$04x\n", desc.idVendor, desc.idProduct);
    }QCoreApplicationQCoreAQCoreApplicationpplication
    */



int main(int argc, char ** argv){

    QApplication a(argc,argv);
MainWindow w;
//w.show();

    return a.exec();
}
