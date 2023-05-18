#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <iostream>
#include <cctype>

#include "model/s21_model.h"
#include "model/s21_credit_calculator.h"
#include "controller/s21_controller.h"


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
    void on_main_mode_button_clicked();
    void on_x_mode_button_clicked();
    void on_open_graph_clicked();

private:
    Ui::MainWindow *ui;
    s21::Controller *controller_;
    bool open_extra_mode = false;
    bool expression_mode = true;
    bool open_graph_mode = false;

};
#endif // MAINWINDOW_H
