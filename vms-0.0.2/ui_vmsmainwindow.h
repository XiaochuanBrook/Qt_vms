/********************************************************************************
** Form generated from reading ui file 'vmsmainwindow.ui'
**
** Created: Thu May 21 18:16:15 2009
**      by: Qt User Interface Compiler version 4.4.0-rc1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_VMSMAINWINDOW_H
#define UI_VMSMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VMSMainWindowClass
{
public:
    QAction *action_Exit;
    QAction *action_About;
    QAction *action_Options;
    QAction *actionTake_Photo;
    QAction *action_Delete;
    QWidget *videoViewWidget;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Help;
    QMenu *menu_Setting;
    QMenu *menu_Capture;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VMSMainWindowClass)
    {
    if (VMSMainWindowClass->objectName().isEmpty())
        VMSMainWindowClass->setObjectName(QString::fromUtf8("VMSMainWindowClass"));
    VMSMainWindowClass->resize(600, 400);
    action_Exit = new QAction(VMSMainWindowClass);
    action_Exit->setObjectName(QString::fromUtf8("action_Exit"));
    action_About = new QAction(VMSMainWindowClass);
    action_About->setObjectName(QString::fromUtf8("action_About"));
    action_Options = new QAction(VMSMainWindowClass);
    action_Options->setObjectName(QString::fromUtf8("action_Options"));
    actionTake_Photo = new QAction(VMSMainWindowClass);
    actionTake_Photo->setObjectName(QString::fromUtf8("actionTake_Photo"));
    action_Delete = new QAction(VMSMainWindowClass);
    action_Delete->setObjectName(QString::fromUtf8("action_Delete"));
    videoViewWidget = new QWidget(VMSMainWindowClass);
    videoViewWidget->setObjectName(QString::fromUtf8("videoViewWidget"));
    VMSMainWindowClass->setCentralWidget(videoViewWidget);
    menuBar = new QMenuBar(VMSMainWindowClass);
    menuBar->setObjectName(QString::fromUtf8("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 600, 20));
    menu_File = new QMenu(menuBar);
    menu_File->setObjectName(QString::fromUtf8("menu_File"));
    menu_Help = new QMenu(menuBar);
    menu_Help->setObjectName(QString::fromUtf8("menu_Help"));
    menu_Setting = new QMenu(menuBar);
    menu_Setting->setObjectName(QString::fromUtf8("menu_Setting"));
    menu_Capture = new QMenu(menuBar);
    menu_Capture->setObjectName(QString::fromUtf8("menu_Capture"));
    VMSMainWindowClass->setMenuBar(menuBar);
    mainToolBar = new QToolBar(VMSMainWindowClass);
    mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
    VMSMainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(VMSMainWindowClass);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    VMSMainWindowClass->setStatusBar(statusBar);

    menuBar->addAction(menu_File->menuAction());
    menuBar->addAction(menu_Setting->menuAction());
    menuBar->addAction(menu_Capture->menuAction());
    menuBar->addAction(menu_Help->menuAction());
    menu_File->addAction(action_Exit);
    menu_Help->addAction(action_About);
    menu_Setting->addAction(action_Options);
    menu_Capture->addAction(actionTake_Photo);
    menu_Capture->addAction(action_Delete);

    retranslateUi(VMSMainWindowClass);

    QMetaObject::connectSlotsByName(VMSMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *VMSMainWindowClass)
    {
    VMSMainWindowClass->setWindowTitle(QApplication::translate("VMSMainWindowClass", "VMSMainWindow", 0, QApplication::UnicodeUTF8));
    action_Exit->setText(QApplication::translate("VMSMainWindowClass", "&Exit", 0, QApplication::UnicodeUTF8));
    action_About->setText(QApplication::translate("VMSMainWindowClass", "&About", 0, QApplication::UnicodeUTF8));
    action_Options->setText(QApplication::translate("VMSMainWindowClass", "&Options", 0, QApplication::UnicodeUTF8));
    actionTake_Photo->setText(QApplication::translate("VMSMainWindowClass", "Take &Photo", 0, QApplication::UnicodeUTF8));
    action_Delete->setText(QApplication::translate("VMSMainWindowClass", "&Delete", 0, QApplication::UnicodeUTF8));
    menu_File->setTitle(QApplication::translate("VMSMainWindowClass", "&File", 0, QApplication::UnicodeUTF8));
    menu_Help->setTitle(QApplication::translate("VMSMainWindowClass", "&Help", 0, QApplication::UnicodeUTF8));
    menu_Setting->setTitle(QApplication::translate("VMSMainWindowClass", "&Setting", 0, QApplication::UnicodeUTF8));
    menu_Capture->setTitle(QApplication::translate("VMSMainWindowClass", "&Capture", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VMSMainWindowClass: public Ui_VMSMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VMSMAINWINDOW_H
