

#ifndef VIDEOCAPTUREDEVICE_H
#define VIDEOCAPTUREDEVICE_H

#include <QImage>

namespace camera
{

class VideoCaptureDevice
{
public:

    virtual ~VideoCaptureDevice() {}

    virtual bool hasCamera() const = 0;
    virtual void getCameraImage(QImage& img, bool copy = false) = 0;

    virtual QList<QSize> photoSizes() const = 0;
    virtual QList<QSize> videoSizes() const = 0;

    virtual QSize recommendedPhotoSize() const = 0;
    virtual QSize recommendedVideoSize() const = 0;
    virtual QSize recommendedPreviewSize() const = 0;

    virtual QSize captureSize() const = 0;
    virtual void setCaptureSize(QSize size) = 0;

    virtual uint refocusDelay() const = 0;
    virtual int minimumFramePeriod() const = 0;
};

}   // ns camera

#endif // VIDEOCAPTUREDEVICE_H
