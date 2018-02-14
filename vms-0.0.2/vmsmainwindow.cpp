
#include "vmsmainwindow.h"
#include "videocaptureview.h"
#include "camerasettings.h"
#include "thumbbutton.h"

static const int thmarg=2;

VMSMainWindow::VMSMainWindow(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags)
{
    ui.setupUi(this);
    isViewingPhoto = false;
    photoext="JPG";
    storagePath = "/tmp";
    settings = new CameraSettings( this );

    QWidget *cameraWidget = new QWidget(this);
    camera = new Ui::CameraBase();
    camera->setupUi(cameraWidget);
    setCentralWidget(cameraWidget);

    thumb[0] = camera->thumb1;
    thumb[1] = camera->thumb2;
    thumb[2] = camera->thumb3;
    thumb[3] = camera->thumb4;
    thumb[4] = camera->thumb5;
    cur_thumb = -1;

    QSignalMapper* sm = new QSignalMapper(this);
    for (int i=0; i<nthumb; i++) {
        sm->setMapping(thumb[i],i);
        connect(thumb[i],SIGNAL(clicked()),sm,SLOT(map()));
        thumb[i]->installEventFilter(this);
    }
    connect(sm,SIGNAL(mapped(int)),this,SLOT(thumbClicked(int)));

    photo_size = camera->videocaptureview->photoSizes();
    pquality = settings->photo_quality->value();
    for ( psize = 0; psize < (int)photo_size.count()-1; ++psize );
    for (int i=0; i<(int)photo_size.count(); i++) {
        QString s = QString("%1 x %2").arg(photo_size[i].width())
                    .arg(photo_size[i].height());
        //settings->photo_size->addItem( s );
    }

    if ( camera->videocaptureview->available() ) {
        camera->video->setEnabled( false );
    } else {
        // ui.action_Options->setEnabled( false );
        ui.actionTake_Photo->setEnabled( false );
        camera->photo->setEnabled( false );
        camera->video->setEnabled( false );
    }

    camera->photo->setFocus();
    connect( camera->photo, SIGNAL( clicked() ),
             this, SLOT( on_actionTake_Photo_triggered() ) );
    connect( camera->video, SIGNAL( clicked() ),
             this, SLOT( toggleVideo() ) );
    connect( camera->videocaptureview, SIGNAL(imgChanged()),
             this, SLOT( takePhoto() ) );
    setWindowTitle( tr( "Video Monitor System" ) );
}
VMSMainWindow::~VMSMainWindow()
{

}
void VMSMainWindow::resizeEvent(QResizeEvent*)
{
    thumbw = width()/5-4;
    thumbh = thumbw*3/4;
    qDebug() << "thumb width: " << thumbw << "\t thumb height: " << thumbh;
    camera->thumbs->setFixedHeight(thumbh+thmarg*2);

    loadThumbs();
}
void VMSMainWindow::takePhoto()
{
on_actionTake_Photo_triggered();
}


bool VMSMainWindow::event(QEvent* e)
{
    /*
    if ( e->type() == QEvent::WindowActivate ) {
        if ( cur_thumb < 0 ) {
            toggleVideo();
        }
    } else if ( e->type() == QEvent::WindowDeactivate ) {
        camera->videocaptureview->setLive(-1);
    }
    */
    return QMainWindow::event(e);
}

void VMSMainWindow::toggleVideo()
{
    if ( camera->videocaptureview->available() ) {
        isViewingPhoto = false;
        camera->video->setEnabled( false );
        camera->photo->setEnabled( true );
        camera->videocaptureview->setLive();
        camera->videocaptureview->CMP=1;
    }
}

void VMSMainWindow::loadThumbs()
{
    QDir dir( storagePath, "*.jpg", QDir::Time );
    QStringList fileNameList = dir.entryList();
    qDebug() << "picture numbers: " << fileNameList.size();

    for ( int i = 0; i < nthumb; ++i) {
        QString file = storagePath;
        QPixmap pm;

        if (i < fileNameList.size() ) {
            file.append( fileNameList.at(i) );
            picturefile[i] = file;
            QImage img( file );
            pm = QPixmap::fromImage(img.scaled(QSize( thumbw, thumbh ),
                       Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }

        thumb[i]->setIcon( pm );
        thumb[i]->setEnabled( !pm.isNull() );
    }

    if ( isViewingPhoto ) {
        if ( cur_thumb < fileNameList.size() )
            selectThumb(cur_thumb);
        else
            selectThumb( fileNameList.size() - 1 );
    }

    ui.action_Delete->setVisible( fileNameList.size() > 0 );
}

void VMSMainWindow::selectThumb(int i)
{
    isViewingPhoto = true;
    cur_thumb = i;
    if ( i >= 0 ) {
          qWarning("set img");
        QImage img( picturefile[i] );
        camera->videocaptureview->setStill(img);
        thumb[i]->setFocus();
        camera->photo->setEnabled( false );
        if ( camera->videocaptureview->available() )
            camera->video->setEnabled( true );
    } else {
        toggleVideo();
    }
}

void VMSMainWindow::delThumb(int th)
{
    QString file = picturefile[th];
    file.replace(storagePath, "" );
    switch(QMessageBox::warning(0, tr("Confirmation"),
            tr("<qt>Delete '%1'?</qt>", "%1 = file name").arg( file ),
            QMessageBox::Yes,
            QMessageBox::No))
    {
        case QMessageBox::Yes:
            QFile::remove( picturefile[th] );
            loadThumbs();

            // Rhys Hack - if we have just deleted the last image and there
            // is no camera connected, then exit the application.  This
            // avoids a focus problem where it is impossible to exit with
            // the back button due to the focus being in a stupid place.
            if ( !camera->videocaptureview->available() &&
                 !(thumb[0]->isEnabled()) ) {
                close();
            }
            break;
        default:
            //nothing
            break;
    }
}

void VMSMainWindow::pushThumb(const QString file, const QImage& img)
{
    for (int i=nthumb; --i; ) {
        bool en = thumb[i-1]->isEnabled();
        thumb[i]->setEnabled(en);
        QIcon icon = thumb[i-1]->icon();
        if ( en && !icon.isNull() ) {
            thumb[i]->setIcon(icon);
            picturefile[i] = picturefile[i-1];
        } else {
            thumb[i]->setText("");
        }
    }
    thumb[0]->setIcon(QPixmap::fromImage(img.scaled(
            QSize( thumbw, thumbh ), Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    thumb[0]->setEnabled(true);
    picturefile[0] = file;
}

void VMSMainWindow::on_action_Exit_triggered()
{
    qApp->quit();
}

void VMSMainWindow::thumbClicked(int i)
{    camera->videocaptureview->CMP=0;
    selectThumb(i);
    qDebug() << "thumb " << i << " clicked.";
}

void VMSMainWindow::on_action_About_triggered()
{
    QMessageBox::about( this, tr( "About Video Monitor System" ),
                        tr( "<p><b>Video Monitor System</b></p><p></p>"
                            "<p>********4-7**********</p><p></p>"
                            "<p>Provided by Lin XiaoChuan</p><p></p>"
                            "<p></p>"
                            ) );
}

void VMSMainWindow::on_action_Options_triggered()
{   
camera->video->setEnabled( false );
    settings->show();

 //   settings->photo_size->setCurrentIndex( psize );
    settings->photo_quality->setValue( pquality );

    if ( settings->exec() ) {
        storagePath = settings->getStoragePath();
        storagePath.append( "/" );
        photoext = settings->photo_ext->currentIndex();
        pquality = settings->photo_quality->value();

        camera->videocaptureview->DW=settings->DW_quality->value();
	camera->videocaptureview->DH=settings->DH_quality->value();
	camera->videocaptureview->Diflim=settings->TAL_quality->value();
    if(settings->SQA_quality->value()==4)
	{
	camera->videocaptureview->PointX=0;
	camera->videocaptureview->PointY=0;
	camera->videocaptureview->CpeW=320;
	camera->videocaptureview->CpeH=240;
	}
    if(settings->SQA_quality->value()==3)
	{
	camera->videocaptureview->PointX=80;
	camera->videocaptureview->PointY=60;
	camera->videocaptureview->CpeW=160;
	camera->videocaptureview->CpeH=120;
	}
    if(settings->SQA_quality->value()==2)
	{
	camera->videocaptureview->PointX=120;
	camera->videocaptureview->PointY=90;
	camera->videocaptureview->CpeW=80;
	camera->videocaptureview->CpeH=60;
	}
    if(settings->SQA_quality->value()==1)
	{
	camera->videocaptureview->PointX=140;
	camera->videocaptureview->PointY=105;
	camera->videocaptureview->CpeW=40;
	camera->videocaptureview->CpeH=30;
	}
        qDebug() << "storage path" << storagePath;
        qDebug() << "psize: " << psize;
        qDebug() << "pquality: " << pquality;
//camera->video->setEnabled( ture );
        camera->videocaptureview->CMP=settings->check_one->isChecked();
        qWarning("%d",camera->videocaptureview->CMP);
 }

    loadThumbs();
}

void VMSMainWindow::on_actionTake_Photo_triggered()
{
    QSize size = photo_size[psize];
    //qWarning("Take Photo action is alive");
    // qWarning("%d, size.width");
   // qWarning("%d, size.height");
//    if ( size == camera->videocaptureview->captureSize() ) {
            qWarning("photo if passed");
        // We can grab the current image immediately.
        takePhotoNow();
  //  }
}

void VMSMainWindow::on_action_Delete_triggered()
{
    if ( cur_thumb >= 0 ) {
        delThumb(cur_thumb);
    }
}

void VMSMainWindow::takePhotoNow()
{
    /* set the filename to the current date and time,
     * such as "081231195001222.jpg" for "Dec 31, 2008. 19:50:01.222".
     */
    QString file = storagePath;
    file.append( QDateTime::currentDateTime().toString("yyMMddhhmmsszzz") );
    file.append( ".png" );
  //  file.append(photoext);
    QImage img = camera->videocaptureview->image();
  // qWarning("photo will be taked");
//    QByteArray k=photoext.toAscii();
   // char ext=k;
    img.save( file, "PNG", pquality );
    qWarning("photo is taked");
    pushThumb( file, img );
}

void ThumbButton::paintEvent( QPaintEvent* )
{
    // copy from 'qtoolbutton.cpp'
    // 这样做‘按钮特效’消失了，该怎么实现才好？
    QStylePainter p(this);
    QStyleOptionToolButton opt;
    initStyleOption(&opt);
    p.drawComplexControl(QStyle::CC_ToolButton, opt);

    // QPainter p(this);
    QIcon ic = icon();
    if ( !ic.isNull() ) {
        ic.paint( &p, rect() );
    }
}

ThumbButton::ThumbButton( QWidget *parent ) : QToolButton(parent)
{
}
