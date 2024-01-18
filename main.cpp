#include "vgribbonwindow.h"

#include <QApplication>




#include "QRibbon.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VGRibbonWindow w;
    w.show();
    return a.exec();
}
