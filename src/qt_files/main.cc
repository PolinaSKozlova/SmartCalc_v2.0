#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  using namespace smartcalc;
  QApplication a(argc, argv);
  MathCalculator model;
  CreditCalculator credit;
  Controller controller(&model, &credit);
  MainWindow view(&controller);
  view.setFixedSize(325, 590);
  view.show();
  return a.exec();
}
