

// source code from: Qtopia-opensource-4.2.4

#ifndef V4L1VIDEOCAPTUREDEVICE_H
#define V4L1VIDEOCAPTUREDEVICE_H

#ifdef Q_OS_LINUX

#include "videocapturedevice.h"

// Lihux C headers
#include <sys/types.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>

#include <linux/videodev.h>

#endif // Q_OS_LINUX

namespace camera
{

#ifdef Q_OS_LINUX

class V4L1VideoCaptureDevice : public VideoCaptureDevice
{
public:

    V4L1VideoCaptureDevice();
    ~V4L1VideoCaptureDevice();

    bool hasCamera() const;
    void getCameraImage( QImage& img, bool copy = false );

    QList<QSize> photoSizes() const;
    QList<QSize> videoSizes() const;

    QSize recommendedPhotoSize() const;
    QSize recommendedVideoSize() const;
    QSize recommendedPreviewSize() const;

    QSize captureSize() const;
    void setCaptureSize( QSize size );

    uint refocusDelay() const;
    int minimumFramePeriod() const;

private:

    int                 fd;
    int                 width, height;
    video_capability    caps;
    video_mbuf          mbuf;
    unsigned char       *frames;
    int                 currentFrame;

    void setupCamera( QSize size );
    void shutdown();
};

#endif // Q_OS_LINUX

}   // ns camera

#endif // V4L1VIDEOCAPTUREDEVICE_H
