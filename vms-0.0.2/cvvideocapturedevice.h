

#ifndef CVVIDEOCAPTUREDEVICE_H
#define CVVIDEOCAPTUREDEVICE_H

#ifdef Q_OS_WIN32
#include "videocapturedevice.h"
#include "cxcore.h"
#include "highgui.h"
#endif // Q_OS_WIN32

namespace camera
{

#ifdef Q_OS_WIN32

class CvVideoCaptureDevice : public VideoCaptureDevice
{
public:

    CvVideoCaptureDevice();
    ~CvVideoCaptureDevice();

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

    CvCapture           *capture;
    int                 width, height;
    int                 nChannels;
    IplImage            *frame, *frame_copy;

    void setupCamera( QSize size );
    void shutdown();
};

#endif // Q_OS_WIN32

}   // ns camera

#endif // CVVIDEOCAPTUREDEVICE_H
