#include "smartcalcwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SmartCalcWindow w;
    w.show();
    return a.exec();
}
