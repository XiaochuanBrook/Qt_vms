 

#ifndef CAMERASETTINGS_H
#define CAMERASETTINGS_H

#include <QtGui>

class CameraSettings : public QDialog
{
    Q_OBJECT

public:
    CameraSettings(QWidget* parent = 0, Qt::WindowFlags f = 0);
    ~CameraSettings();
    QString getStoragePath() const;
    bool CMPstate;
    friend class VMSMainWindow;

private slots:
    void setStoragePath();
    void CMDchange();

private:
    void setupUi();
    QCheckBox* check_one;
    QLineEdit* storagePath;
    QToolButton* browseButton;
//    QComboBox *photo_size;
    QComboBox *photo_ext;
    QSlider *photo_quality;
 QSlider *DW_quality;
 QSlider *DH_quality;
 QSlider *TAL_quality;
 QSlider *SQA;
QHBoxLayout *hboxLayout2;
QHBoxLayout *hboxLayout3;
QHBoxLayout *hboxLayout4;
QHBoxLayout *hboxLayout5;
QLabel *photo_quality_D;
QLabel *photo_quality_H;
QLabel *photo_quality_T;
QLabel *photo_quality_S;
QLabel *TextLabel3;
QLabel *TextLabel4;
QLabel *TextLabel5;
QLabel *TextLabel6;

};

#endif // CAMERASETTINGS_H
