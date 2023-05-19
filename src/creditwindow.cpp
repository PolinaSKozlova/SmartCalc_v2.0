#include "creditwindow.h"
#include "ui_creditwindow.h"


CreditWindow::CreditWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreditWindow)
{
    ui->setupUi(this);
}

CreditWindow::~CreditWindow()
{
    delete ui;
}


