#ifndef SMARTCALCWINDOW_H
#define SMARTCALCWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SmartCalcWindow; }
QT_END_NAMESPACE

class SmartCalcWindow : public QMainWindow
{
    Q_OBJECT

public:
    SmartCalcWindow(QWidget *parent = nullptr);
    ~SmartCalcWindow();

private:
    Ui::SmartCalcWindow *ui;
};
#endif // SMARTCALCWINDOW_H
