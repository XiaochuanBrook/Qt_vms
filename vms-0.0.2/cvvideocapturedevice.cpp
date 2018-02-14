
/*
 * We use some OpenCV libs provided by intel for the video capture from camera
 * on Windows operating system.
 */

#include <QList>

#include "cvvideocapturedevice.h"

namespace camera
{

#ifdef Q_OS_WIN32

bool CvVideoCaptureDevice::hasCamera() const
{
    return (capture != 0);
}

QSize CvVideoCaptureDevice::captureSize() const
{
    return QSize( width, height );
}

uint CvVideoCaptureDevice::refocusDelay() const
{
    return 250;
}

int CvVideoCaptureDevice::minimumFramePeriod() const
{
    return 40; // milliseconds
}

CvVideoCaptureDevice::CvVideoCaptureDevice()
{
    width = 0;
    height = 0;
    capture = 0;
    frame = 0;
    frame_copy = 0;

    setupCamera( QSize( 0, 0) );
}

CvVideoCaptureDevice::~CvVideoCaptureDevice()
{
    shutdown();
}

void CvVideoCaptureDevice::setupCamera( QSize size )
{
    // we don't change the size now
    size = size;

    // start capturing frames from camera.
    capture = cvCaptureFromCAM( 0 ); // capture video from camera
    if ( !capture ) {
        qWarning( "can not oppen video capture device." );
        return;
    }

    // grab a frame, return 1 on success, 0 on fail.
    if ( !cvGrabFrame( capture ) ) {
        qWarning( "capture failed." );
        shutdown();
        return;
    }
    // get the frame grabbed with cvGrabFrame(..)
    frame = cvRetrieveFrame( capture );
    if ( !frame ) {
        qWarning( "capture failed." );
        shutdown();
        return;
    }

    // retrive camera info
    width = frame->width;
    height = frame->height;
    nChannels = frame->nChannels;
    // Allocates and initializes IplImage header
    frame_copy = cvCreateImage( cvSize( width, height ),
                                IPL_DEPTH_8U, nChannels );
}

void CvVideoCaptureDevice::getCameraImage( QImage& img, bool copy )
{
    if ( !capture ) {
        if ( img.isNull() )
            img = QImage( width, height, QImage::Format_RGB32 );
        return;
    }

    // Just a combination of cvGrabFrame and cvRetrieveFrame
    frame = cvQueryFrame( capture ); // get image frame
    if ( frame->origin == IPL_ORIGIN_TL )
        cvCopy( frame, frame_copy, 0 );
    else
        cvFlip( frame, frame_copy, 0 );

    copy = copy;
    // Format_RGB32 is '0xFFRRGGBB'
    img = QImage( width, height, QImage::Format_RGB32 );
    if ( nChannels == 3 ) {
        uchar* imgPtr = img.bits();
        uchar* srcImgPtr = (uchar*)frame_copy->imageDataOrigin;

        for ( int i = 0; i < width*height; ++i) {
            *imgPtr++ = *srcImgPtr++;
            *imgPtr++ = *srcImgPtr++;
            *imgPtr++ = *srcImgPtr++;
            *imgPtr++ = 0xff;
        }
    }
}

void CvVideoCaptureDevice::shutdown()
{
    // stop capturing/reading and free resources
    if ( capture ) {
        cvReleaseCapture( &capture );
        capture = 0;
    }
}

QList<QSize> CvVideoCaptureDevice::photoSizes() const
{
    QList<QSize> list;
    list.append( QSize( width, height ) );
    return list;
}

QList<QSize> CvVideoCaptureDevice::videoSizes() const
{
    // We use the same sizes for both.
    return photoSizes();
}

QSize CvVideoCaptureDevice::recommendedPhotoSize() const
{
    return QSize( width, height );
}

QSize CvVideoCaptureDevice::recommendedVideoSize() const
{
    return QSize( width, height );
}

QSize CvVideoCaptureDevice::recommendedPreviewSize() const
{
    return QSize( width, height );
}

void CvVideoCaptureDevice::setCaptureSize( QSize size )
{
    // not changed.
    size = size;
}

#endif // Q_OS_WIN32

} // ns camera
