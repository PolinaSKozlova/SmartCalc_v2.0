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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void numbers();
    void operations();
    void trigonometry();
    void on_clear_all_clicked();
    void on_backspace_clicked();

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
