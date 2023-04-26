#include "smartcalcwindow.h"
#include "./ui_smartcalcwindow.h"

SmartCalcWindow::SmartCalcWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SmartCalcWindow)
{
    ui->setupUi(this);
}

SmartCalcWindow::~SmartCalcWindow()
{
    delete ui;
}

