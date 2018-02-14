
#include "videocapturedevicefactory.h"
#include "videocapturedevice.h"

#ifdef Q_OS_LINUX

#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/poll.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <linux/videodev.h>

#include "v4l1videocapturedevice.h"

#define V4L

#endif //Q_OS_LINUX

#ifdef Q_OS_WIN32
#include "cvvideocapturedevice.h"
#endif // Q_OS_WIN32

namespace camera
{

VideoCaptureDevice* VideoCaptureDeviceFactory::createVideoCaptureDevice()
{
    VideoCaptureDevice* rc;

#ifdef Q_OS_LINUX
#ifdef V4L
    rc = new V4L1VideoCaptureDevice;
#endif //V4L
#endif //Q_OS_LINUX

#ifdef Q_OS_WIN32
    rc = new CvVideoCaptureDevice;
#endif // Q_OS_WIN32

    return rc;
}

}   // ns camera
