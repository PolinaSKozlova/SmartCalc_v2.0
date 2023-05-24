#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(s21::Controller *controller, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller_(controller) {
  ui->setupUi(this);
  ui->main_frame->setFixedSize(321, 441);
  ui->result_show->setFixedSize(271, 81);
  credit_window = new CreditWindow(this->controller_, this);
  connect(ui->zero, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->one, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->two, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->three, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->four, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->five, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->six, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->seven, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->eight, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->nine, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->exp, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->variable_x, SIGNAL(clicked()), this, SLOT(trigonometry()));
  connect(ui->dot, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->sum, SIGNAL(clicked()), this, SLOT(sign()));
  connect(ui->sub, SIGNAL(clicked()), this, SLOT(sign()));
  connect(ui->div, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->mult, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->mod, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->square_root, SIGNAL(clicked()), this, SLOT(trigonometry()));
  connect(ui->pow, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->open_bracket, SIGNAL(clicked()), this, SLOT(brackets()));
  connect(ui->close_bracket, SIGNAL(clicked()), this, SLOT(brackets()));
  connect(ui->cosinus, SIGNAL(clicked()), this, SLOT(trigonometry()));
  connect(ui->sinus, SIGNAL(clicked()), this, SLOT(trigonometry()));
  connect(ui->tangens, SIGNAL(clicked()), this, SLOT(trigonometry()));
  connect(ui->arcosinus, SIGNAL(clicked()), this, SLOT(trigonometry()));
  connect(ui->arcsinus, SIGNAL(clicked()), this, SLOT(trigonometry()));
  connect(ui->arctangens, SIGNAL(clicked()), this, SLOT(trigonometry()));
  connect(ui->natural_log, SIGNAL(clicked()), this, SLOT(trigonometry()));
  connect(ui->decimal_log, SIGNAL(clicked()), this, SLOT(trigonometry()));
}

MainWindow::~MainWindow() {
  delete credit_window;
  delete ui;
}

void MainWindow::numbers() {
  QPushButton *button = (QPushButton *)sender();
    if(ui->result_show->hasFocus()){
        if (ui->result_show->text() == "Start calculate" ||
            ui->result_show->text().toStdString() ==
                controller_->GetOutputAnswer()) {
          ui->result_show->setText("0");
        }
        if (ui->result_show->text().length() < 255) {
          if ((ui->result_show->text() == "0" || ui->result_show->text() == "nan" ||
               ui->result_show->text() == "inf" ||
               ui->result_show->text() == "-inf") &&
              button->text() != ".") {
            ui->result_show->setText(button->text());
          } else {
            ui->result_show->setText(ui->result_show->text() + button->text());
          }
        }
      } else {
        if (ui->get_x_value->text() == "0.0" ||
            ui->get_x_value->text() == "Incorrect x value" ||
            ui->get_x_value->text() == "X value can't be only dot") {
          ui->get_x_value->setText(button->text());
        } else {
          ui->get_x_value->setText(ui->get_x_value->text() + button->text());
        }
      }
}

void MainWindow::operations() {
  QPushButton *button = (QPushButton *)sender();
  if (ui->result_show->text() == "Start calculate" ||
      ui->result_show->text().toStdString() == controller_->GetOutputAnswer()) {
    ui->result_show->setText(ui->result_show->text());
  }
  if (ui->result_show->text().length() < 255) {
    ui->result_show->setText(ui->result_show->text() + button->text());
  }
}

void MainWindow::sign() {
  QPushButton *button = (QPushButton *)sender();
   if (ui->result_show->hasFocus()) {
        if (ui->result_show->text() == "Start calculate" ||
            ui->result_show->text().toStdString() ==
                controller_->GetOutputAnswer()) {
          ui->result_show->setText(ui->result_show->text());
        }
        if (ui->result_show->text().length() < 255) {
          ui->result_show->setText(ui->result_show->text() + button->text());
        }
      } else {
        if (ui->get_x_value->text() == "Enter x value" ||
            ui->get_x_value->text() == "0.0" ||
            ui->get_x_value->text() == "Incorrect x value" ||
            ui->get_x_value->text() == "X value can't be only dot") {
          ui->get_x_value->setText(button->text());
        } else {
          ui->get_x_value->setText(ui->get_x_value->text() + button->text());
        }
      }
}

void MainWindow::trigonometry() {
  QPushButton *button = (QPushButton *)sender();
  if (ui->result_show->text() == "Start calculate" ||
      ui->result_show->text().toStdString() == controller_->GetOutputAnswer()) {
    ui->result_show->setText("0");
  }
  if (ui->result_show->text().length() < 255) {
    if ((ui->result_show->text() == "0" || ui->result_show->text() == "nan" ||
         ui->result_show->text() == "inf" ||
         ui->result_show->text() == "-inf")) {
        if (button->text() == "x"){
            ui->result_show->setText(button->text());
        } else {
            ui->result_show->setText(button->text() + "(");
        }
    } else {
        if (button->text() == "x"){
             ui->result_show->setText(ui->result_show->text() + button->text());
        } else {
             ui->result_show->setText(ui->result_show->text() + button->text() + "(");
        }
    }
  }
}

void MainWindow::brackets() {
  QPushButton *button = (QPushButton *)sender();
  if (ui->result_show->text() == "Start calculate" ||
      ui->result_show->text().toStdString() == controller_->GetOutputAnswer()) {
    ui->result_show->setText("0");
  }
  if ((ui->result_show->text() == "0" || ui->result_show->text() == "nan" ||
       ui->result_show->text() == "inf" || ui->result_show->text() == "-inf")) {
    ui->result_show->setText(button->text());
  } else {
    ui->result_show->setText(ui->result_show->text() + button->text());
  }
}

void MainWindow::on_backspace_clicked() {
    if (ui->result_show->hasFocus()) {
       QString text = ui->result_show->text();
       text.chop(1);
       if (text.isEmpty()) {
         text = "0";
       }
       ui->result_show->setText(text);
   } else {
       QString text = ui->get_x_value->text();
       text.chop(1);
       if (text.isEmpty()) {
         text = "0";
       }
       ui->get_x_value->setText(text);
   }
}

void MainWindow::on_clear_all_clicked() {
    if(ui->result_show->hasFocus()){
        ui->result_show->setText("0");
      } else {
        ui->get_x_value->setText("0.0");
      }
}

void MainWindow::on_equal_clicked() {
    std::string tmp_src = ui->result_show->text().toStdString();
    std::string x_value = ui->get_x_value->text().toStdString();
    controller_->ParceAndCalculateExpression(tmp_src, x_value);
    ui->result_show->setText(QString::fromStdString(controller_->GetOutputAnswer()));
}

void MainWindow::on_open_extra_mode_clicked() {
  if (!open_extra_mode) {
    open_extra_mode = true;
    ui->open_extra_mode->setText("<");
    ui->main_frame->setFixedSize(631, 441);
    ui->result_show->setFixedSize(582, 81);
    setFixedSize(635, 590);
  } else {
    open_extra_mode = false;
    ui->open_extra_mode->setText(">");
    ui->main_frame->setFixedSize(321, 441);
    ui->result_show->setFixedSize(271, 81);
    setFixedSize(325, 590);
  }
}


void MainWindow::on_open_graph_clicked() {
  if (!open_graph_mode) {
    open_graph_mode = true;
    ui->open_graph->setText("<");
    setFixedSize(1025, 590);
    ui->main_frame->setFixedSize(1001, 441);
  } else {
    open_graph_mode = false;
    ui->open_graph->setText(">");
    setFixedSize(635, 590);
    ui->main_frame->setFixedSize(631, 441);
  }
}

void MainWindow::on_actionMath_Calculator_triggered() {
  credit_window->hide();
  this->show();
  setFixedSize(325, 590);
}

void MainWindow::on_actionCredit_Calc_triggered() {
  this->hide();
  credit_window->show();
}

void MainWindow::on_clear_values_clicked() {
  ui->x_min->setValue(0.00);
  ui->x_max->setValue(0.00);
  ui->y_min->setValue(0.00);
  ui->y_max->setValue(0.00);
}

void MainWindow::on_print_graph_clicked() {
  double min_x = ui->x_min->value();
  double max_x = ui->x_max->value();
  double min_y = ui->y_min->value();
  double max_y = ui->y_max->value();
  std::vector<double> x_axes, y_axes;
  try{
    controller_->GetCoordinates(ui->result_show->text().toStdString(),min_x, max_x, min_y, max_y, x_axes, y_axes);
  } catch (std::invalid_argument &e){
    QMessageBox::critical(this, "ERROR", e.what());
  }
}

void MainWindow::on_actionDeposit_calc_triggered()
{
    QMessageBox::information(this,"Справка", "Раздел в разработке ¯| _(ツ)_ |¯");
    credit_window->hide();
    this->show();
}

