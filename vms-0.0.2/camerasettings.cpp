
#include "camerasettings.h"

CameraSettings::CameraSettings(QWidget* parent, Qt::WindowFlags f) :
        QDialog(parent, f)
{
    setModal( true );
    CMPstate=false;
    setupUi();
}

CameraSettings::~CameraSettings()
{
}

QString CameraSettings::getStoragePath() const
{
    return storagePath->text();
}

void CameraSettings::setStoragePath()
{
    QString path = QFileDialog::getExistingDirectory( this, tr("Open Directory"),
                storagePath->text() );
    if ( !path.isEmpty() )
        storagePath->setText( path );
}

void CameraSettings::CMDchange()
{
CMPstate=!CMPstate;
qWarning("CMP was changed");
}


void CameraSettings::setupUi()
{
    QVBoxLayout *vboxLayout;
    QGroupBox *photo;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *storageLayout;
    QHBoxLayout *hboxLayout;
    QLabel *TextLabel1;
    QLabel *pathLabel;
    QHBoxLayout *hboxLayout1;
    QLabel *TextLabel2;
    QLabel *photo_quality_n;
    QSpacerItem *Spacer1;
    QDialogButtonBox *buttonBox;

    resize(320, 240);

    vboxLayout = new QVBoxLayout(this);
#ifndef Q_OS_MAC
    vboxLayout->setSpacing(6);
#endif
    vboxLayout->setMargin(11);

    storageLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
    storageLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    storageLayout->setMargin(0);
#endif
    pathLabel = new QLabel( tr("Storage Path ") );
    storageLayout->addWidget( pathLabel );
    storagePath = new QLineEdit( QDir::currentPath() );
    storageLayout->addWidget( storagePath );
    browseButton = new QToolButton;
    browseButton->setText( "..." );
    storageLayout->addWidget( browseButton );
    vboxLayout->addLayout( storageLayout );

    photo = new QGroupBox(this);
    photo->setTitle( tr( "Photo" ) );

    vboxLayout1 = new QVBoxLayout(photo);
    vboxLayout1->setSpacing(2);
    vboxLayout1->setMargin(4);
    hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
    hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    hboxLayout->setMargin(0);
#endif
    TextLabel1 = new QLabel(photo);
    TextLabel1->setText( tr( "EXT" ) );
    hboxLayout->addWidget(TextLabel1);

/*    photo_size = new QComboBox(photo);
  QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(0));
//    sizePolicy.setHorizontalStretch(0);
 //   sizePolicy.setVerticalStretch(0);
  //  sizePolicy.setHeightForWidth(photo_size->sizePolicy().hasHeightForWidth());
    photo_size->insertItem(0,"BMP");
    photo_size->insertItem(1,"JPG");
    photo_size->insertItem(2,"PNG"); 
//  photo_size->setSizePolicy(sizePolicy);

    //hboxLayout->addWidget(photo_ext);
*/
    vboxLayout1->addLayout(hboxLayout);
    
    hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
    hboxLayout1->setSpacing(6);
#endif
    hboxLayout1->setMargin(0);
    TextLabel2 = new QLabel(photo);
    TextLabel2->setText( tr( "Quality" ) );
    hboxLayout1->addWidget(TextLabel2);

    photo_quality = new QSlider(photo);
    photo_quality->setMinimum(0);
    photo_quality->setMaximum(100);
    photo_quality->setValue(75);
    photo_quality->setOrientation(Qt::Horizontal);
    hboxLayout1->addWidget(photo_quality);
    photo_quality_n = new QLabel(photo);
    photo_quality_n->setText( tr( "75" ) );
    hboxLayout1->addWidget(photo_quality_n);

    vboxLayout1->addLayout(hboxLayout1);
hboxLayout2 = new QHBoxLayout();
    DW_quality = new QSlider(photo);
    DW_quality->setMinimum(1);
    DW_quality->setMaximum(100);
    DW_quality->setValue(10);
    DW_quality->setOrientation(Qt::Horizontal);
    photo_quality_D = new QLabel(photo);
    photo_quality_D->setText( tr( "10" ) );    TextLabel3 = new QLabel(photo);
    TextLabel3->setText( tr( "DW" ) );
    hboxLayout2->addWidget(TextLabel3);
    hboxLayout2->addWidget(DW_quality);
    hboxLayout2->addWidget(photo_quality_D);

vboxLayout1->addLayout(hboxLayout2);

hboxLayout3 = new QHBoxLayout();
    DH_quality = new QSlider(photo);
    DH_quality->setMinimum(0);
    DH_quality->setMaximum(100);
    DH_quality->setValue(10);
    DH_quality->setOrientation(Qt::Horizontal);
          TextLabel4 = new QLabel(photo);
    TextLabel4->setText( tr( "DH" ) );
    hboxLayout3->addWidget(TextLabel4);
    hboxLayout3->addWidget(DH_quality);
	 photo_quality_H = new QLabel(photo);
    photo_quality_H->setText( tr( "10" ) );
    hboxLayout3->addWidget(photo_quality_H);
vboxLayout1->addLayout(hboxLayout3);

hboxLayout4 = new QHBoxLayout();

    TAL_quality = new QSlider(photo);
    TAL_quality->setMinimum(10);
    TAL_quality->setMaximum(10000);
    TAL_quality->setValue(10);
    TAL_quality->setOrientation(Qt::Horizontal);
   TextLabel5 = new QLabel(photo);
    TextLabel5->setText( tr( "TAL" ) );
    hboxLayout4->addWidget(TextLabel5);
    hboxLayout4->addWidget(TAL_quality);
photo_quality_T = new QLabel(photo);
    photo_quality_T->setText( tr( "10" ) );
    hboxLayout4->addWidget(photo_quality_T);

vboxLayout1->addLayout(hboxLayout4);
hboxLayout5 = new QHBoxLayout();
    SQA = new QSlider(photo);
    SQA->setMinimum(1);
    SQA->setMaximum(4);
    SQA->setValue(2);
    SQA->setOrientation(Qt::Horizontal);
TextLabel6 = new QLabel(photo);
    TextLabel6->setText( tr( "SQA" ) );
    hboxLayout5->addWidget(TextLabel6);

    hboxLayout5->addWidget(SQA);
photo_quality_S = new QLabel(photo);
    photo_quality_T->setText( tr( "2" ) );
    hboxLayout5->addWidget(photo_quality_S);

vboxLayout1->addLayout(hboxLayout5);

    vboxLayout->addWidget(photo);

    check_one = new QCheckBox ("check_one");
    check_one->setText (tr ("AUTO"));
    check_one->setChecked (FALSE);
    vboxLayout->addWidget(check_one);
    
  photo_ext = new QComboBox(photo);
/*  QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(0));
//    sizePolicy.setHorizontalStretch(0);
 //   sizePolicy.setVerticalStretch(0);
  //  sizePolicy.setHeightForWidth(photo_size->sizePolicy().hasHeightForWidth());
*/
    photo_ext->insertItem(0,"BMP");
    photo_ext->insertItem(1,"JPG");
    photo_ext->insertItem(2,"PNG");
//  photo_size->setSizePolicy(sizePolicy);

    hboxLayout->addWidget(photo_ext);

    vboxLayout1->addLayout(hboxLayout);


    Spacer1 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    vboxLayout->addItem(Spacer1);

    buttonBox = new QDialogButtonBox( this );
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

    vboxLayout->addWidget( buttonBox );   


    connect( browseButton, SIGNAL(clicked()), this, SLOT(setStoragePath()) );
    connect( photo_quality, SIGNAL(valueChanged(int)),
             photo_quality_n, SLOT(setNum(int)) );
          connect( DW_quality, SIGNAL(valueChanged(int)),
             photo_quality_D, SLOT(setNum(int)) );
connect( DH_quality, SIGNAL(valueChanged(int)),
             photo_quality_H, SLOT(setNum(int)) );
connect( TAL_quality, SIGNAL(valueChanged(int)),
             photo_quality_T, SLOT(setNum(int)) );
connect( SQA, SIGNAL(valueChanged(int)),
             photo_quality_S, SLOT(setNum(int)) );
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
    connect(check_one,SIGNAL(stateChanged),this,SLOT(CMDchange()));
    setWindowTitle( tr( "Settings" ) );
}
