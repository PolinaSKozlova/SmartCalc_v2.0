#include "mainwindow.h"

#include "../plot/qcustomplot.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(smartcalc::Controller *controller, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller_(controller) {
  ui->setupUi(this);
  ui->main_frame->setFixedSize(321, 441);
  ui->result_show->setFixedSize(271, 81);
  credit_window = new CreditWindow(this->controller_, this);
  plot_window = new PlotWindow(this);
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
  delete plot_window;
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
  SetOperationsOrSign(button);
}

void MainWindow::sign(QAbstractButton *button) {
  if (ui->result_show->hasFocus()) {
    SetOperationsOrSign(button);
  } else {
    SetTextToX(button);
  }
}

void MainWindow::trigonometry(QAbstractButton *button) {
  SetTextToResult(button);
  ui->result_show->insert("()");
  ui->result_show->setCursorPosition(ui->result_show->cursorPosition() - 1);
}

void MainWindow::brackets(QAbstractButton *button) {
  SetTextToResult(button);
  if (button->text() == "(") {
    ui->result_show->insert(")");
    ui->result_show->setCursorPosition(ui->result_show->cursorPosition() - 1);
  }
}

void MainWindow::on_backspace_clicked() {
  if (ui->result_show->hasFocus()) {
    DeleteOneValue(ui->result_show);
  } else {
    DeleteOneValue(ui->get_x_value);
  }
}

void MainWindow::on_clear_all_clicked() {
  if (ui->result_show->hasFocus()) {
    ui->result_show->setText("0");
  } else {
    ui->get_x_value->setText("0");
  }
}

void MainWindow::on_equal_clicked() {
  std::string tmp_src = ui->result_show->text().replace(" ", "").toStdString();
  std::string x_value = ui->get_x_value->text().replace(" ", "").toStdString();
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
    open_graph_mode = false;
    ui->open_graph->setText(">");
    ui->main_frame->setFixedSize(321, 441);
    ui->result_show->setFixedSize(271, 81);
    setFixedSize(325, 590);
  }
}

void MainWindow::on_open_graph_clicked() {
  if (!open_graph_mode) {
    open_graph_mode = true;
    ui->open_graph->setText("<");
    setFixedSize(1015, 621);
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
  if (ui->get_x_value->text() == "0") {
    ui->get_x_value->clear();
  }
  ui->get_x_value->insert(button->text());
}

void MainWindow::SetOperationsOrSign(QAbstractButton *button) {
  if (ui->result_show->text() == "Start calculate" ||
      (ui->result_show->text().toStdString() ==
           controller_->GetOutputAnswer() &&
       controller_->GetHasException())) {
    ui->result_show->clear();
  }
  ui->result_show->insert(button->text());
}

void MainWindow::DeleteOneValue(QLineEdit *line) {
  QString text = line->text();
  text.chop(1);
  if (text.isEmpty()) {
    text = "0";
  }
  line->setText(text);
}

void MainWindow::on_clear_values_clicked() {
  ui->x_min->setValue(0.00);
  ui->x_max->setValue(0.00);
  ui->y_min->setValue(0.00);
  ui->y_max->setValue(0.00);
  plot_window->ClearPlot();
}

void MainWindow::on_print_graph_clicked() {
  mmv.min_x_ = ui->x_min->value();
  mmv.max_x_ = ui->x_max->value();
  mmv.min_y_ = ui->y_min->value();
  mmv.max_y_ = ui->y_max->value();
  try {
    std::pair<std::vector<double>, std::vector<double>> vector_of_xy_pairs;
    controller_->GetCoordinatesForChartArea(
        ui->result_show->text().toStdString(), mmv, vector_of_xy_pairs);
    plot_window->ClearPlot();
    plot_window->MakePlotArea(mmv, vector_of_xy_pairs, ui->result_show->text());
    plot_window->setWindowFlag(Qt::WindowStaysOnTopHint);
    plot_window->show();
  } catch (std::invalid_argument &e) {
    QMessageBox::critical(this, "ERROR", e.what());
  }
}
