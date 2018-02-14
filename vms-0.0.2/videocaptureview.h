

// source code from: Qtopia-opensource-4.2.4

#ifndef VIDEOCAPTUREVIEW_H
#define VIDEOCAPTUREVIEW_H

#include <QWidget>
#include <QImage>
#include <QList>


namespace camera
{
class VideoCaptureDevice;
}


class VideoCaptureView : public QWidget
{
    Q_OBJECT

public:
    VideoCaptureView(QWidget *parent = 0, Qt::WFlags fl = 0);
    ~VideoCaptureView();

    bool available() const;

    QImage image() const { return m_image; }
    void setLive(int period = 0);
    void setStill(const QImage&);

    QList<QSize> photoSizes() const;
    QList<QSize> videoSizes() const;

    QSize recommendedPhotoSize() const;
    QSize recommendedVideoSize() const;
    QSize recommendedPreviewSize() const;

    QSize captureSize() const;
    void setCaptureSize( QSize size );
    bool CMP;
    uint refocusDelay() const;
    double      Difret ;
    int Diflim,DW,DH,PointX,PointY,CpeW,CpeH;
signals:

void imgChanged();
void drawFinish(QRect);

protected:
    void moveEvent(QMoveEvent* moveEvent);
    void resizeEvent(QResizeEvent* resizeEvent);
    void paintEvent(QPaintEvent* paintEvent);
    void timerEvent(QTimerEvent* timerEvent);
void mouseMoveEvent(QMouseEvent *event);
void mousePressEvent(QMouseEvent *event);
void mouseReleaseEvent(QMouseEvent *event);
void keyPressEvent(QKeyEvent *event);

private:
    
    bool                m_cleared,f,;
    int                 m_tidUpdate;
    QImage              m_image,img;
	quint64	DifSum,pixSumlast;
	quint64 	pixelNow,pixelLast;
        QRgb pix,pixm;
        int Rpix,Gpix,Bpix,Rpixm,Gpixm,Bpixm;
    camera::VideoCaptureDevice  *m_capture;
 QPoint startPoint,endPoint;
 QRect drawRect;
 int flag,drawFlag;

};

#endif // VIDEOCAPTUREVIEW_H
