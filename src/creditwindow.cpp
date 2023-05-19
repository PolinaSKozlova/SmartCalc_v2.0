#include "creditwindow.h"
#include "ui_creditwindow.h"
#include <QErrorMessage>
#include <QMessageBox>


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


void CreditWindow::on_count_clicked()
{
   try {
        credit_data_.CheckCreditValues(ui->credit_sum->text().toStdString(),ui->credit_term->text().toStdString(), ui->credit_range->text().toStdString());
        controller_credit_->CountCredit();
        ui->result_monthly_pay->setText(QString::number(controller_credit_->GetCreditData().monthly_payment_.front()));
        ui->result_percents->setText(QString::number(controller_credit_->GetCreditData().payble_percents_));
        ui->result_total->setText(QString::number(controller_credit_->GetCreditData().total_sum_));
    } catch(std::invalid_argument &e) {
        QMessageBox::critical(this, "ERROR", e.what());
    }

}


void CreditWindow::on_clear_clicked()
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


void CreditWindow::on_a_type_clicked()
{
    credit_data_.credit_type_ = false;
}


void CreditWindow::on_d_type_clicked()
{
     credit_data_.credit_type_ = true;
}

