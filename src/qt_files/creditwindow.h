#ifndef CREDITWINDOW_H
#define CREDITWINDOW_H

#include <QErrorMessage>
#include <QMainWindow>
#include <QMessageBox>

#include "../controller/controller.h"
#include "../model/credit_calculator.h"

namespace Ui {
class CreditWindow;
}

class CreditWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit CreditWindow(smartcalc::Controller *controller = nullptr,
                        QWidget *parent = nullptr);
  ~CreditWindow();

 signals:
  void showParent();

 private slots:
  void on_months_clicked();
  void on_years_clicked();
  void on_count_clicked();
  void on_clear_clicked();
  void on_a_type_clicked();
  void on_d_type_clicked();
  void on_actionMathCalc_triggered();
  void on_actionDepositCalc_triggered();

 private:
  Ui::CreditWindow *ui;
  smartcalc::Controller *controller_credit_;
};

#endif  // CREDITWINDOW_H
