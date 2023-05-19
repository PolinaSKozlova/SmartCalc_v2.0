#include "creditwindow.h"
#include "ui_creditwindow.h"
#include <QErrorMessage>


CreditWindow::CreditWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreditWindow)
{
    ui->setupUi(this);
    setFixedSize(891,721);
    ui->months->setChecked(true);
    ui->a_type->setChecked(true);
}

CreditWindow::~CreditWindow()
{
    delete ui;
}



void CreditWindow::on_months_clicked()
{
    credit_data_.term_in_years_ = false;
}


void CreditWindow::on_years_clicked()
{
    credit_data_.term_in_years_ = true;
}


void CreditWindow::on_pushButton_clicked()
{
   try {
        credit_data_.CheckCreditValues(ui->credit_sum->text().toStdString(),ui->credit_term->text().toStdString(), ui->credit_range->text().toStdString());
    } catch(std::invalid_argument &e) {
        QString msg_error = e.what();
//        QMessageBox::critical(this, "ERROR", msg_error);
    }

}


void CreditWindow::on_pushButton_2_clicked()
{
    ui->credit_range->clear();
    ui->credit_sum->clear();
    ui->credit_term->clear();
    ui->result_monthly_pay->clear();
    ui->result_percents->clear();
    ui->result_total->clear();
    ui->list_of_payments->clear();
    ui->months->setChecked(true);
    ui->a_type->setChecked(true);
}
