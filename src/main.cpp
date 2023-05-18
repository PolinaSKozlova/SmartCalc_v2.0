#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow view;
    view.setFixedSize(650, 575);
    view.show();
    s21::MathCalculator model;
    s21::CreditCalculator credit;
    s21::Controller controller;
    return a.exec();
}
