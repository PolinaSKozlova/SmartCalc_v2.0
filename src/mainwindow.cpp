#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    creditWind = new CreditWindow(this);
//        ui->graph_window->setInteraction(QCP::iRangeDrag, true);
//        connect(ui->zero, SIGNAL(clicked()),this,SLOT(numbers()));
//        connect(ui->one, SIGNAL(clicked()),this,SLOT(numbers()));
//        connect(ui->two, SIGNAL(clicked()),this,SLOT(numbers()));
//        connect(ui->three, SIGNAL(clicked()),this,SLOT(numbers()));
//        connect(ui->four, SIGNAL(clicked()),this,SLOT(numbers()));
//        connect(ui->five, SIGNAL(clicked()),this,SLOT(numbers()));
//        connect(ui->six, SIGNAL(clicked()),this,SLOT(numbers()));
//        connect(ui->seven, SIGNAL(clicked()),this,SLOT(numbers()));
//        connect(ui->eight, SIGNAL(clicked()),this,SLOT(numbers()));
//        connect(ui->nine, SIGNAL(clicked()),this,SLOT(numbers()));
//        connect(ui->variable_x, SIGNAL(clicked()),this,SLOT(numbers()));
//        connect(ui->dot, SIGNAL(clicked()),this,SLOT(numbers()));
//        connect(ui->sum, SIGNAL(clicked()),this,SLOT(operations()));
//        connect(ui->sub, SIGNAL(clicked()),this,SLOT(operations()));
//        connect(ui->div, SIGNAL(clicked()),this,SLOT(operations()));
//        connect(ui->mult, SIGNAL(clicked()),this,SLOT(operations()));
//        connect(ui->mod, SIGNAL(clicked()),this,SLOT(operations()));
//        connect(ui->square_root, SIGNAL(clicked()),this,SLOT(trigonometry()));
//        connect(ui->pow, SIGNAL(clicked()),this,SLOT(trigonometry()));
//        connect(ui->open_bracket, SIGNAL(clicked()),this,SLOT(trigonometry()));
//        connect(ui->close_bracket, SIGNAL(clicked()),this,SLOT(trigonometry()));
//        connect(ui->cosinus, SIGNAL(clicked()),this,SLOT(trigonometry()));
//        connect(ui->sinus, SIGNAL(clicked()),this,SLOT(trigonometry()));
//        connect(ui->tangens, SIGNAL(clicked()),this,SLOT(trigonometry()));
//        connect(ui->arcosinus, SIGNAL(clicked()),this,SLOT(trigonometry()));
//        connect(ui->arcsinus, SIGNAL(clicked()),this,SLOT(trigonometry()));
//        connect(ui->arctangens, SIGNAL(clicked()),this,SLOT(trigonometry()));
//        connect(ui->natural_log, SIGNAL(clicked()),this,SLOT(trigonometry()));
//        connect(ui->decimal_log, SIGNAL(clicked()),this,SLOT(trigonometry()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


