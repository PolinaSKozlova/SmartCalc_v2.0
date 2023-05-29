#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(s21::Controller *controller, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller_(controller) {
  ui->setupUi(this);
  ui->main_frame->setFixedSize(321, 441);
  ui->result_show->setFixedSize(271, 81);
  credit_window = new CreditWindow(this->controller_, this);
  connect(ui->buttonNumbers, &QButtonGroup::buttonClicked, this,
          &MainWindow::numbers);
  connect(ui->buttonBrackets, &QButtonGroup::buttonClicked, this,
          &MainWindow::brackets);
  connect(ui->buttonOperations, &QButtonGroup::buttonClicked, this,
          &MainWindow::operations);
  connect(ui->buttonSign, &QButtonGroup::buttonClicked, this,
          &MainWindow::sign);
  connect(ui->buttonTrigonometry, &QButtonGroup::buttonClicked, this,
          &MainWindow::trigonometry);
  connect(credit_window, &CreditWindow::showParent, this,
          &MainWindow::on_actionMath_Calculator_triggered);
}

MainWindow::~MainWindow() {
  delete credit_window;
  delete ui;
}

void MainWindow::numbers(QAbstractButton *button) {
  if (ui->result_show->hasFocus()) {
    SetTextToResult(button);
  } else {
    SetTextToX(button);
  }
}

void MainWindow::operations(QAbstractButton *button) {
  if (ui->result_show->text() == "Start calculate" ||
      ui->result_show->text().toStdString() == controller_->GetOutputAnswer()) {
    ui->result_show->clear();
  }
  ui->result_show->insert(button->text());
}

void MainWindow::sign(QAbstractButton *button) {
  if (ui->result_show->hasFocus()) {
    SetTextToResult(button);
  } else {
    SetTextToX(button);
  }
}

void MainWindow::trigonometry(QAbstractButton *button) {
  SetTextToResult(button);
  ui->result_show->insert("()");
  ui->result_show->setCursorPosition(ui->result_show->cursorPosition() - 1);
}

void MainWindow::brackets(QAbstractButton *button) { SetTextToResult(button); }

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
  if (ui->result_show->hasFocus()) {
    ui->result_show->setText("0");
  } else {
    ui->get_x_value->setText("0.0");
  }
}

void MainWindow::on_equal_clicked() {
  std::string tmp_src = ui->result_show->text().toStdString();
  std::string x_value = ui->get_x_value->text().toStdString();
  controller_->ParceAndCalculateExpression(tmp_src, x_value);
  ui->result_show->setText(
      QString::fromStdString(controller_->GetOutputAnswer()));
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
    setFixedSize(2100, 895);
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
}

void MainWindow::on_actionCredit_Calc_triggered() {
  this->hide();
  credit_window->show();
}

void MainWindow::on_actionDeposit_calc_triggered() {
  QMessageBox::information(this, "Справка", "Раздел в разработке ¯| _(ツ)_ |¯");
  this->show();
}

void MainWindow::SetTextToResult(QAbstractButton *button) {
  if ((ui->result_show->text() == "Start calculate" ||
       ui->result_show->text().toStdString() ==
           controller_->GetOutputAnswer() ||
       ui->result_show->text() == "0") &&
      button->text() != ".") {
    ui->result_show->clear();
  }
  ui->result_show->insert(button->text());
}

void MainWindow::SetTextToX(QAbstractButton *button) {
  if (ui->get_x_value->text() == "0.0") {
    ui->get_x_value->clear();
  }
  ui->get_x_value->insert(button->text());
}

void MainWindow::on_clear_values_clicked() {
  ui->x_min->setValue(0.00);
  ui->x_max->setValue(0.00);
  ui->y_min->setValue(0.00);
  ui->y_max->setValue(0.00);
  ui->graph_widget->chart()->removeAllSeries();
  ui->graph_widget->SetDefaultAxis();
}

void MainWindow::on_print_graph_clicked() {
  double min_x = ui->x_min->value();
  double max_x = ui->x_max->value();
  double min_y = ui->y_min->value();
  double max_y = ui->y_max->value();
  std::vector<double> x_axes, y_axes;
  setMinimumSize(2100, 895);
  try {
    controller_->GetCoordinatesForChartArea(
        ui->result_show->text().toStdString(), min_x, max_x, min_y, max_y,
        x_axes, y_axes);
    ui->graph_widget->setFixedSize(1041, 801);
    ui->graph_widget->SetValues(min_x, max_x, min_y, max_y, x_axes, y_axes,
                                ui->result_show->text());
  } catch (std::invalid_argument &e) {
    QMessageBox::critical(this, "ERROR", e.what());
  }
}
