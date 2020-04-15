#include "usbdevicediscover.h"
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>
#include <linux/limits.h>
#include <glob.h>
#include <unistd.h>
#include <cstdlib>
#include <QList>


#define PROC_USB_DEV "/proc/scsi/usb-storage"
#define SYS_SCSI_HOST "/sys/class/scsi_host/host%s/device"
#define SYS_SCSI_DEV "/sys/class/scsi_disk/%s:*"
#define SYS_SCSI_TGT "%s/device/block/*"

UsbDeviceDiscover::UsbDeviceDiscover()
{

}

QString UsbDeviceDiscover::getDevice_name() const
{
    return m_device_name;
}

void UsbDeviceDiscover::setDevice_name(const QString &device_name)
{
    m_device_name = device_name;
}


void UsbDeviceDiscover::getUsbDevice(){

    QList<QString> deviceList;
    DIR *dp = NULL;
    struct dirent *dt = NULL;

    if((dp = opendir(PROC_USB_DEV)) == NULL) {
        fprintf(stderr, "Can not open %s: %s", PROC_USB_DEV, strerror(errno));
      return;
    }

    /* find usb storage device hosts which appear as scsi hosts */
    /* for the sake of example this one hasn't been done with glob(3) */
    while((dt = readdir(dp)) != NULL) {
      int scsi_dev = 0;
      /* skip '.' and '..', possibly others too */
      if((scsi_dev = atoi(basename(dt->d_name))) < 1) continue;

      char buf[PATH_MAX];
      char pat[PATH_MAX];

      snprintf(buf, PATH_MAX, SYS_SCSI_HOST, basename(dt->d_name));
      snprintf(pat, PATH_MAX, SYS_SCSI_DEV, basename(dt->d_name));

      glob_t hosts;
      size_t count;

      /* find SCSI host device paths */
      glob(pat, 0, 0, &hosts);
      if(hosts.gl_pathc > 0) {
        char **p;
        int n;
        for(p = hosts.gl_pathv, n = hosts.gl_pathc; n; p++, n--) {
          char tgtbuf[PATH_MAX + NAME_MAX];

          snprintf(tgtbuf, PATH_MAX + NAME_MAX, SYS_SCSI_TGT, *p);

          /* find SCSI disk device paths */
          glob_t devs;
          glob(tgtbuf, 0, 0, &devs);
          if(devs.gl_pathc > 0) {
            char **ptr;
            int c;
            for(ptr = devs.gl_pathv, c = devs.gl_pathc; c; ptr++, c--) {
              printf("We would now call mount(2) for /dev/%s.\n",
                     basename(*ptr));
              deviceList.append(QString::fromUtf8(basename(*ptr)));


            }
          }
          globfree(&devs);
        }
        globfree(&hosts);
      }
    }
            if(!deviceList.isEmpty())

                setDevice_name(deviceList.last());
                //emit newUsbDevice(deviceList.last());
  }




