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
    void trigonometry();
    void on_clear_all_clicked();
    void on_backspace_clicked();

    void on_clear_x_mode_clicked();

private:
    Ui::MainWindow *ui;
    s21::Controller *controller_;

};
#endif // MAINWINDOW_H
