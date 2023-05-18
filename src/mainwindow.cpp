#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(s21::Controller* controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), controller_(controller)
{
    ui->setupUi(this);
//    creditWind = new CreditWindow(this);
//        ui->graph_window->setInteraction(QCP::iRangeDrag, true);
        connect(ui->zero, SIGNAL(clicked()),this,SLOT(numbers()));
        connect(ui->one, SIGNAL(clicked()),this,SLOT(numbers()));
        connect(ui->two, SIGNAL(clicked()),this,SLOT(numbers()));
        connect(ui->three, SIGNAL(clicked()),this,SLOT(numbers()));
        connect(ui->four, SIGNAL(clicked()),this,SLOT(numbers()));
        connect(ui->five, SIGNAL(clicked()),this,SLOT(numbers()));
        connect(ui->six, SIGNAL(clicked()),this,SLOT(numbers()));
        connect(ui->seven, SIGNAL(clicked()),this,SLOT(numbers()));
        connect(ui->eight, SIGNAL(clicked()),this,SLOT(numbers()));
        connect(ui->nine, SIGNAL(clicked()),this,SLOT(numbers()));
        connect(ui->variable_x, SIGNAL(clicked()),this,SLOT(numbers()));
        connect(ui->dot, SIGNAL(clicked()),this,SLOT(numbers()));
        connect(ui->sum, SIGNAL(clicked()),this,SLOT(operations()));
        connect(ui->sub, SIGNAL(clicked()),this,SLOT(operations()));
        connect(ui->div, SIGNAL(clicked()),this,SLOT(operations()));
        connect(ui->mult, SIGNAL(clicked()),this,SLOT(operations()));
        connect(ui->mod, SIGNAL(clicked()),this,SLOT(operations()));
        connect(ui->square_root, SIGNAL(clicked()),this,SLOT(trigonometry()));
        connect(ui->pow, SIGNAL(clicked()),this,SLOT(trigonometry()));
        connect(ui->open_bracket, SIGNAL(clicked()),this,SLOT(trigonometry()));
        connect(ui->close_bracket, SIGNAL(clicked()),this,SLOT(trigonometry()));
        connect(ui->cosinus, SIGNAL(clicked()),this,SLOT(trigonometry()));
        connect(ui->sinus, SIGNAL(clicked()),this,SLOT(trigonometry()));
        connect(ui->tangens, SIGNAL(clicked()),this,SLOT(trigonometry()));
        connect(ui->arcosinus, SIGNAL(clicked()),this,SLOT(trigonometry()));
        connect(ui->arcsinus, SIGNAL(clicked()),this,SLOT(trigonometry()));
        connect(ui->arctangens, SIGNAL(clicked()),this,SLOT(trigonometry()));
        connect(ui->natural_log, SIGNAL(clicked()),this,SLOT(trigonometry()));
        connect(ui->decimal_log, SIGNAL(clicked()),this,SLOT(trigonometry()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numbers()
{
    QPushButton *button =(QPushButton *)sender();
    if (ui->result_show->text() == "Start calculate" || ui->result_show->text() == "ERROR" || ui->result_show->text() == "INCORRECT X") {
        ui->result_show->setText("0");
    }
    if(ui->result_show->text().length() < 255) {
        if((ui->result_show->text() == "0" || ui->result_show->text() == "nan" || ui->result_show->text() == "inf" || ui->result_show->text() == "-inf")&& button->text() != "." ){
            ui->result_show->setText(button->text());
        }else {
            ui->result_show->setText(ui->result_show->text() + button->text());
        }
    }
}

void MainWindow::operations(){
    QPushButton *button =(QPushButton *)sender();
    if (ui->result_show->text() == "Start calculate" || ui->result_show->text() == "ERROR" || ui->result_show->text() == "INCORRECT X") {
        ui->result_show->setText("");
    }
    if(ui->result_show->text().length() < 255) {
        ui->result_show->setText(ui->result_show->text() + button->text());
    }

}

void MainWindow::trigonometry(){
    QPushButton *button =(QPushButton *)sender();
    if (ui->result_show->text() == "Start calculate" || ui->result_show->text() == "ERROR" || ui->result_show->text() == "INCORRECT X"){
        ui->result_show->setText("0");
    }
    if(ui->result_show->text().length() < 255) {
        if ((ui->result_show->text() == "0" || ui->result_show->text() == "nan" || ui->result_show->text() == "inf" || ui->result_show->text() == "-inf")){
            ui->result_show->setText(button->text());
        } else{
              ui->result_show->setText(ui->result_show->text() + button->text()); 
        }
    }
}


void MainWindow::on_backspace_clicked()
{
    QString text = ui->result_show->text();
       text.chop(1);
       if (text.isEmpty())
            {
                text = "0";
            }
       ui->result_show->setText(text);
}


void MainWindow::on_clear_all_clicked()
{
    ui->result_show->setText("0");
}


void MainWindow::on_equal_clicked()
{
    std::string tmp_src = ui->result_show->text().toStdString();
    std::string x_value = ui->get_x_value->text().toStdString();
    try{
     controller_->ParceAndCalculateExpression(tmp_src,x_value);
     ui->result_show->setText(QString::fromStdString(controller_->GetOutputAnswer()));
    } catch(std::invalid_argument &e){
         ui->result_show->setText(QString::fromStdString(e.what()));
    }

}

