

#include <QtGui/QApplication>
#include "vmsmainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VMSMainWindow w;
    w.showFullScreen();
    return a.exec();
}
