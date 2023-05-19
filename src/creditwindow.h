#ifndef CREDITWINDOW_H
#define CREDITWINDOW_H

#include <QMainWindow>
#include "model/s21_credit_calculator.h"
#include "controller/s21_controller.h"

namespace Ui {
class CreditWindow;
}

class CreditWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreditWindow(QWidget *parent = nullptr);
    ~CreditWindow();

private slots:
    void on_months_clicked();
    void on_years_clicked();
    void on_count_clicked();
    void on_clear_clicked();
    void on_a_type_clicked();
    void on_d_type_clicked();

private:
    Ui::CreditWindow *ui;
    s21::CreditInformation credit_data_;
    s21::Controller *controller_credit_;
};

#endif // CREDITWINDOW_H
