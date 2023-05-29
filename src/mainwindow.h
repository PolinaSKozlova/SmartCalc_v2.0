#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/qlayout.h>

#include <QMainWindow>
#include <QValueAxis>
#include <QVector>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <cctype>
#include <iostream>

#include "chartarea.h"
#include "controller/s21_controller.h"
#include "creditwindow.h"
#include "model/s21_credit_calculator.h"
#include "model/s21_model.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(s21::Controller *controller, QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_equal_clicked();
  void numbers(QAbstractButton *button);
  void operations(QAbstractButton *button);
  void sign(QAbstractButton *button);
  void trigonometry(QAbstractButton *button);
  void brackets(QAbstractButton *button);
  void on_clear_all_clicked();
  void on_backspace_clicked();
  void on_open_extra_mode_clicked();
  void on_open_graph_clicked();
  void on_clear_values_clicked();
  void on_actionMath_Calculator_triggered();
  void on_actionCredit_Calc_triggered();
  void on_print_graph_clicked();
  void on_actionDeposit_calc_triggered();

 private:
  void SetTextToResult(QAbstractButton *button);
  Ui::MainWindow *ui;
  CreditWindow *credit_window;
  s21::Controller *controller_;
  ChartArea *chart_window;
  bool open_extra_mode = false;
  bool open_graph_mode = false;
};
#endif  // MAINWINDOW_H
