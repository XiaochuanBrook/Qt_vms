

// source code from: Qtopia-opensource-4.2.4

#ifndef VIDEOCAPTUREDEVICEFACTORY_H
#define VIDEOCAPTUREDEVICEFACTORY_H

namespace camera
{

class VideoCaptureDevice;

class VideoCaptureDeviceFactory
{
public:

    static VideoCaptureDevice* createVideoCaptureDevice();
};

}   // ns camera

#endif // VIDEOCAPTUREDEVICEFACTORY_H
