#ifndef CREDITWINDOW_H
#define CREDITWINDOW_H

#include <QMainWindow>

namespace Ui {
class CreditWindow;
}

class CreditWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreditWindow(QWidget *parent = nullptr);
    ~CreditWindow();

private:
    Ui::CreditWindow *ui;
};

#endif // CREDITWINDOW_H
