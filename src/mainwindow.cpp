#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(s21::Controller* controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), controller_(controller)
{
    ui->setupUi(this);
    ui->main_frame->setFixedSize(321,441);
    ui->result_show->setFixedSize(271,81);
    ui->main_mode_button->setChecked(true);
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
    connect(ui->exp, SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->variable_x, SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->dot, SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->sum, SIGNAL(clicked()),this,SLOT(sign()));
    connect(ui->sub, SIGNAL(clicked()),this,SLOT(sign()));
    connect(ui->div, SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->mult, SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->mod, SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->square_root, SIGNAL(clicked()),this,SLOT(trigonometry()));
    connect(ui->pow, SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->open_bracket, SIGNAL(clicked()),this,SLOT(brackets()));
    connect(ui->close_bracket, SIGNAL(clicked()),this,SLOT(brackets()));
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
    if(expression_mode){
        if (ui->result_show->text() == "Start calculate" || ui->result_show->text().toStdString() == controller_->GetOutputAnswer()) {
            ui->result_show->setText("0");
        }
        if(ui->result_show->text().length() < 255) {
            if((ui->result_show->text() == "0" || ui->result_show->text() == "nan" || ui->result_show->text() == "inf" || ui->result_show->text() == "-inf")&& button->text() != "." ){
                ui->result_show->setText(button->text());
            }else {
                ui->result_show->setText(ui->result_show->text() + button->text());
            }
        }
    } else {
        if(ui->get_x_value->text() == "Enter x value" || ui->get_x_value->text() == "0.0" || ui->get_x_value->text() == "Incorrect x value" || ui->get_x_value->text() == "X value can't be only dot"){
            ui->get_x_value->setText(button->text());
        } else {
            ui->get_x_value->setText(ui->get_x_value->text() + button->text());
        }
    }
}

void MainWindow::operations()
{
    QPushButton *button =(QPushButton *)sender();
    if (ui->result_show->text() == "Start calculate" || ui->result_show->text().toStdString() == controller_->GetOutputAnswer()) {
        ui->result_show->setText(ui->result_show->text());
    }
    if(ui->result_show->text().length() < 255) {
        ui->result_show->setText(ui->result_show->text() + button->text());
    }

}

void MainWindow::sign()
{
    QPushButton *button =(QPushButton *)sender();
    if(expression_mode) {
        if (ui->result_show->text() == "Start calculate" || ui->result_show->text().toStdString() == controller_->GetOutputAnswer()) {
            ui->result_show->setText(ui->result_show->text());
        }
        if(ui->result_show->text().length() < 255) {
            ui->result_show->setText(ui->result_show->text() + button->text());
        }
    } else {
        if(ui->get_x_value->text() == "Enter x value" || ui->get_x_value->text() == "0.0" || ui->get_x_value->text() == "Incorrect x value" || ui->get_x_value->text() == "X value can't be only dot") {
            ui->get_x_value->setText(button->text());
        } else {
            ui->get_x_value->setText(ui->get_x_value->text() + button->text());
        }
    }

}

void MainWindow::trigonometry()
{
    QPushButton *button =(QPushButton *)sender();
    if (ui->result_show->text() == "Start calculate" || ui->result_show->text().toStdString() == controller_->GetOutputAnswer()){
        ui->result_show->setText("0");
    }
    if (ui->result_show->text().length() < 255) {
        if ((ui->result_show->text() == "0" || ui->result_show->text() == "nan" || ui->result_show->text() == "inf" || ui->result_show->text() == "-inf")){
            ui->result_show->setText(button->text() + "(");
        } else{
              ui->result_show->setText(ui->result_show->text() + button->text() + "(");
        }
    }
}

void MainWindow::brackets()
{
    QPushButton *button =(QPushButton *)sender();
    if (ui->result_show->text() == "Start calculate" || ui->result_show->text().toStdString() == controller_->GetOutputAnswer()){
        ui->result_show->setText("0");
    }
    if ((ui->result_show->text() == "0" || ui->result_show->text() == "nan" || ui->result_show->text() == "inf" || ui->result_show->text() == "-inf")){
        ui->result_show->setText(button->text());
    } else {
          ui->result_show->setText(ui->result_show->text() + button->text());
    }
}

void MainWindow::on_backspace_clicked()
{
    QString text = ui->result_show->text();
       text.chop(1);
       if (text.isEmpty()) {
            text = "0";
       }
       ui->result_show->setText(text);
}


void MainWindow::on_clear_all_clicked()
{
    if(expression_mode){
         ui->result_show->setText("0");
    } else {
        ui->get_x_value->setText("0.0");
    }

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


void MainWindow::on_open_extra_mode_clicked()
{
    if(!open_extra_mode){
        open_extra_mode = true;
        ui->open_extra_mode->setText("<");
        ui->main_frame->setFixedSize(631,441);
        ui->result_show->setFixedSize(582,81);
        setFixedSize(635, 590);
    } else {
        open_extra_mode = false;
        ui->open_extra_mode->setText(">");
        ui->main_frame->setFixedSize(321,441);
        ui->result_show->setFixedSize(271,81);
        setFixedSize(325, 590);
    }

}

void MainWindow::on_main_mode_button_clicked()
{
    expression_mode = true;
}

void MainWindow::on_x_mode_button_clicked()
{
    expression_mode = false;
}


void MainWindow::on_open_graph_clicked()
{
    if(!open_graph_mode){
        open_graph_mode = true;
        ui->open_graph->setText("<");
        setFixedSize(1500, 590);
    } else {
        open_graph_mode = false;
        ui->open_graph->setText(">");
        setFixedSize(635, 590);
    }
}

