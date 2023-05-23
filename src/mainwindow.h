#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <iostream>
#include <cctype>

#include "model/s21_model.h"
#include "model/s21_credit_calculator.h"
#include "controller/s21_controller.h"
#include "creditwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(s21::Controller* controller, QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_equal_clicked();
    void numbers();
    void operations();
    void sign();
    void trigonometry();
    void brackets();
    void on_clear_all_clicked();
    void on_backspace_clicked();
    void on_open_extra_mode_clicked();
    void on_open_graph_clicked();
    void on_actionMath_Calculator_triggered();
    void on_actionCredit_Calc_triggered();
    void on_pushButton_clicked();
    void on_print_graph_clicked();

    void on_actionDeposit_calc_triggered();

private:
    Ui::MainWindow *ui;
    CreditWindow *credit_window;
    s21::Controller *controller_;
    bool open_extra_mode = false;
    bool open_graph_mode = false;

};
#endif // MAINWINDOW_H
