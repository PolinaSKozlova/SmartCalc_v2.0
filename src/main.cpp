#include "mainwindow.h"

#include "model/s21_model.h"
#include "model/s21_credit_calculator.h"
#include "controller/s21_controller.h"


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
