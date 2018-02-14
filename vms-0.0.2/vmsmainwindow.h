

#ifndef VMSMAINWINDOW_H
#define VMSMAINWINDOW_H

#include <QtGui>
#include "ui_vmsmainwindow.h"
#include "ui_camerabase.h"

class CameraSettings;
class VideoCaptureView;

class VMSMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    VMSMainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~VMSMainWindow();

private slots:
    void on_action_Exit_triggered();
    void on_action_About_triggered();
    void on_action_Options_triggered();
    void on_actionTake_Photo_triggered();
    void on_action_Delete_triggered();
    void selectThumb(int i);
    void delThumb(int th);
    void thumbClicked(int i);
    void toggleVideo();
    void takePhoto();
private:
    void resizeEvent(QResizeEvent*);
    bool event(QEvent* e);
    void takePhotoNow();
    void loadThumbs();
    void pushThumb(const QString file, const QImage& img);

    Ui::VMSMainWindowClass ui;
    Ui::CameraBase* camera;
    CameraSettings* settings;
    QString storagePath;
    QString photoext;

    QList<QSize> photo_size;

    static const int nthumb = 5;
    QToolButton* thumb[nthumb];
    QString picturefile[nthumb];

    int cur_thumb;
    int thumbw;
    int thumbh;
    int psize;
    int pquality;

    bool isViewingPhoto;
};

#endif // VMSMAINWINDOW_H
