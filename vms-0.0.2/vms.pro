# -------------------------------------------------
# Project created by QtCreator 2008-12-16T16:17:29
# -------------------------------------------------
TARGET = vms
TEMPLATE = app
CONFIG += console
win32:LIBS += opencv/lib/cxcore.lib \
    opencv/lib/highgui.lib
INCLUDEPATH = opencv/include
SOURCES += main.cpp \
    vmsmainwindow.cpp \
    v4l1videocapturedevice.cpp \
    videocapturedevicefactory.cpp \
    videocaptureview.cpp \
    cvvideocapturedevice.cpp \
    camerasettings.cpp
HEADERS += vmsmainwindow.h \
    videocapturedevice.h \
    v4l1videocapturedevice.h \
    videocapturedevicefactory.h \
    videocaptureview.h \
    cvvideocapturedevice.h \
    camerasettings.h \
    thumbbutton.h
FORMS += vmsmainwindow.ui \
    camerabase.ui

# install
target.path = bin
INSTALLS += target
