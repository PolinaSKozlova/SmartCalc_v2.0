#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    s21::MathCalculator model;
    s21::CreditCalculator credit;
    s21::Controller controller(&model, &credit);
    MainWindow view(&controller);
    view.setFixedSize(325, 590);
    view.show();
    return a.exec();
}
