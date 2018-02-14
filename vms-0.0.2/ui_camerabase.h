/********************************************************************************
** Form generated from reading ui file 'camerabase.ui'
**
** Created: Thu May 21 18:16:15 2009
**      by: Qt User Interface Compiler version 4.4.0-rc1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CAMERABASE_H
#define UI_CAMERABASE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "thumbbutton.h"
#include "videocaptureview.h"

QT_BEGIN_NAMESPACE

class Ui_CameraBase
{
public:
    QGridLayout *gridLayout;
    QFrame *videocapturecontainer;
    QVBoxLayout *vboxLayout;
    VideoCaptureView *videocaptureview;
    QPushButton *photo;
    QPushButton *video;
    QFrame *thumbs;
    QHBoxLayout *hboxLayout;
    ThumbButton *thumb1;
    ThumbButton *thumb2;
    ThumbButton *thumb3;
    ThumbButton *thumb4;
    ThumbButton *thumb5;

    void setupUi(QWidget *CameraBase)
    {
    if (CameraBase->objectName().isEmpty())
        CameraBase->setObjectName(QString::fromUtf8("CameraBase"));
    CameraBase->resize(311, 381);
    gridLayout = new QGridLayout(CameraBase);
    gridLayout->setSpacing(0);
    gridLayout->setMargin(0);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    videocapturecontainer = new QFrame(CameraBase);
    videocapturecontainer->setObjectName(QString::fromUtf8("videocapturecontainer"));
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(videocapturecontainer->sizePolicy().hasHeightForWidth());
    videocapturecontainer->setSizePolicy(sizePolicy);
    videocapturecontainer->setFrameShape(QFrame::Panel);
    videocapturecontainer->setFrameShadow(QFrame::Sunken);
    videocapturecontainer->setLineWidth(4);
    videocapturecontainer->setMidLineWidth(3);
    vboxLayout = new QVBoxLayout(videocapturecontainer);
#ifndef Q_OS_MAC
    vboxLayout->setSpacing(6);
#endif
    vboxLayout->setMargin(4);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    videocaptureview = new VideoCaptureView(videocapturecontainer);
    videocaptureview->setObjectName(QString::fromUtf8("videocaptureview"));
    sizePolicy.setHeightForWidth(videocaptureview->sizePolicy().hasHeightForWidth());
    videocaptureview->setSizePolicy(sizePolicy);

    vboxLayout->addWidget(videocaptureview);


    gridLayout->addWidget(videocapturecontainer, 0, 0, 1, 2);

    photo = new QPushButton(CameraBase);
    photo->setObjectName(QString::fromUtf8("photo"));

    gridLayout->addWidget(photo, 1, 0, 1, 1);

    video = new QPushButton(CameraBase);
    video->setObjectName(QString::fromUtf8("video"));

    gridLayout->addWidget(video, 1, 1, 1, 1);

    thumbs = new QFrame(CameraBase);
    thumbs->setObjectName(QString::fromUtf8("thumbs"));
    thumbs->setFrameShape(QFrame::NoFrame);
    thumbs->setFrameShadow(QFrame::Plain);
    hboxLayout = new QHBoxLayout(thumbs);
    hboxLayout->setSpacing(0);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    thumb1 = new ThumbButton(thumbs);
    thumb1->setObjectName(QString::fromUtf8("thumb1"));
    sizePolicy.setHeightForWidth(thumb1->sizePolicy().hasHeightForWidth());
    thumb1->setSizePolicy(sizePolicy);

    hboxLayout->addWidget(thumb1);

    thumb2 = new ThumbButton(thumbs);
    thumb2->setObjectName(QString::fromUtf8("thumb2"));
    sizePolicy.setHeightForWidth(thumb2->sizePolicy().hasHeightForWidth());
    thumb2->setSizePolicy(sizePolicy);

    hboxLayout->addWidget(thumb2);

    thumb3 = new ThumbButton(thumbs);
    thumb3->setObjectName(QString::fromUtf8("thumb3"));
    sizePolicy.setHeightForWidth(thumb3->sizePolicy().hasHeightForWidth());
    thumb3->setSizePolicy(sizePolicy);

    hboxLayout->addWidget(thumb3);

    thumb4 = new ThumbButton(thumbs);
    thumb4->setObjectName(QString::fromUtf8("thumb4"));
    sizePolicy.setHeightForWidth(thumb4->sizePolicy().hasHeightForWidth());
    thumb4->setSizePolicy(sizePolicy);

    hboxLayout->addWidget(thumb4);

    thumb5 = new ThumbButton(thumbs);
    thumb5->setObjectName(QString::fromUtf8("thumb5"));
    sizePolicy.setHeightForWidth(thumb5->sizePolicy().hasHeightForWidth());
    thumb5->setSizePolicy(sizePolicy);

    hboxLayout->addWidget(thumb5);


    gridLayout->addWidget(thumbs, 2, 0, 1, 2);


    retranslateUi(CameraBase);

    QMetaObject::connectSlotsByName(CameraBase);
    } // setupUi

    void retranslateUi(QWidget *CameraBase)
    {
    CameraBase->setWindowTitle(QApplication::translate("CameraBase", "Camera", 0, QApplication::UnicodeUTF8));
    photo->setText(QApplication::translate("CameraBase", "Photo", 0, QApplication::UnicodeUTF8));
    video->setText(QApplication::translate("CameraBase", "Video", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(CameraBase);
    } // retranslateUi

};

namespace Ui {
    class CameraBase: public Ui_CameraBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERABASE_H
