
// source code from: Qtopia-opensource-4.2.4

#include <QImage>
#include <QPainter>
#include <QPaintEvent>
#include <QEvent>

#include <QDebug>

#include "videocaptureview.h"
#include "videocapturedevice.h"
#include "videocapturedevicefactory.h"

VideoCaptureView::VideoCaptureView(QWidget *parent, Qt::WFlags fl):
    QWidget(parent, fl),
    m_cleared(false),
    m_tidUpdate(0)
{
    m_capture = camera::VideoCaptureDeviceFactory::createVideoCaptureDevice();

    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    resize(319,194);

    // Optimize paint event
    setAttribute(Qt::WA_NoSystemBackground);

    QPalette    pal(palette());
    pal.setBrush(QPalette::Window, Qt::black);
    setPalette(pal);
    pixSumlast=0;
    pixelNow=0;
    Difret=0;
    CMP=0;
    setLive();
 flag=0;
 drawFlag=1;
 Diflim=10;
PointX=120;
PointY=90;
CpeW=120;
CpeH=90;
DW=10;
DH=10;
}

VideoCaptureView::~VideoCaptureView()
{
    delete m_capture;
}

void VideoCaptureView::setLive(int period)
{


    if (m_tidUpdate)
        killTimer(m_tidUpdate);
    if (period == 0)
        m_tidUpdate = startTimer(m_capture->minimumFramePeriod());
    else if ( period > 0 )
        m_tidUpdate = startTimer(period);
    else
        m_tidUpdate = 0;

}

void VideoCaptureView::setStill(const QImage& i)
{
    setLive(-1);
    m_image = i;
  repaint();
}

QList<QSize> VideoCaptureView::photoSizes() const
{
    return m_capture->photoSizes();
}

QList<QSize> VideoCaptureView::videoSizes() const
{
    return m_capture->videoSizes();
}

QSize VideoCaptureView::recommendedPhotoSize() const
{
    return m_capture->recommendedPhotoSize();
}

QSize VideoCaptureView::recommendedVideoSize() const
{
    return m_capture->recommendedVideoSize();
}

QSize VideoCaptureView::recommendedPreviewSize() const
{
    return m_capture->recommendedPreviewSize();
}

QSize VideoCaptureView::captureSize() const
{
    return m_capture->captureSize();
}

void VideoCaptureView::setCaptureSize( QSize size )
{
    m_capture->setCaptureSize(size);
}

uint VideoCaptureView::refocusDelay() const
{
    return m_capture->refocusDelay();
}

bool VideoCaptureView::available() const
{
    return m_capture->hasCamera();
}

void VideoCaptureView::moveEvent(QMoveEvent*)
{
    m_cleared = false;
}

void VideoCaptureView::resizeEvent(QResizeEvent*)
{
    m_cleared = false;
}

void VideoCaptureView::paintEvent(QPaintEvent* paintEvent)
{
    QPainter    painter(this);

    if (!m_cleared)
    {
        QPoint      brushOrigin = painter.brushOrigin();

        // Paint window background
        painter.setBrushOrigin(-mapToGlobal(QPoint(0, 0)));
        painter.fillRect(paintEvent->rect(), window()->palette().brush(QPalette::Window));

        // Reset origin
        painter.setBrushOrigin(brushOrigin);

        m_cleared = true;
    }

    if (m_tidUpdate && !available()) {

        painter.drawText(rect(), Qt::AlignCenter | Qt::TextWordWrap, tr("No Camera"));

        killTimer(m_tidUpdate);
    }
    else
     { 
        if (m_tidUpdate > 0){img=QImage(m_image);
            m_capture->getCameraImage(m_image);}

        int w = m_image.width();
        int h = m_image.height();

	if(f&&CMP){
	// qWarning( "begin to compare");
	
//	pixSumlast=pixelNow;
  //     // qWarning( "pixSumlast=%d so we set it",pixSumlast);
//	if(pixSumlast==0){for(int ii = 0; ii < 32; ++ii)
//			{  for(int jj = 0; jj < 24; ++jj){pixSumlast=pixSumlast+(img.pixel(ii,jj)&0x00FFFFFF);}
//   		}qWarning( "pixSumlast is setting%d %d",w,h);}
//	else
//	pixSumlast=pixelNow;
 DifSum=0;//---
        pix=0;
	 pixelNow=0;
	for(int ii = PointX; ii < CpeW; ii=ii+DW)
	{       
	for(int jj = PointY; jj < CpeH; jj=jj+DH)
		{	
		   	//pixSumlast=(img.pixel(ii,jj)&0x00FFFFFF);
     		pix=m_image.pixel(ii,jj);
		Rpix=qRed(pix);
		Gpix=qGreen(pix);
		Bpix=qBlue(pix);
                pixm=img.pixel(ii,jj);
                Rpixm=qRed(pixm);
                Gpixm=qGreen(pixm);
                Bpixm=qBlue(pixm);
                
	    
		DifSum=DifSum+(qAbs(Rpix-Rpixm)+qAbs(Gpix-Gpixm)+qAbs(Rpix-Rpixm));

		}
	}
     int p=(CpeW*CpeH)/(DH*DW);
       DifSum=DifSum/p;
 
        if(DifSum>Diflim){emit imgChanged();qWarning("w:%d,h:%d",CpeW,CpeH);}
	qWarning( "%d:TotalAVG", DifSum);
  
	}//finish compared
        if (!(w == 0 || h == 0))
        {
            if (width() * w > height() * h) {
                w = w * height() / h;
                h = height();
            }
            else {
                h = h * width() / w;
                w = width();
            }

            painter.drawImage(QRect((width() - w) / 2, (height() - h) / 2, w, h),
                                     m_image,
                                     QRect(0, 0, m_image.width(), m_image.height()));
        }
    }
}

void VideoCaptureView::timerEvent(QTimerEvent*)
{
    repaint();
}




