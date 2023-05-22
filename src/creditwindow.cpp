#include "creditwindow.h"
#include "ui_creditwindow.h"
#include <QErrorMessage>
#include <QMessageBox>

CreditWindow::CreditWindow(s21::Controller *controller, QWidget *parent)
    :
        controller_credit_(controller), QMainWindow(parent),
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
    controller_credit_->SetTermInYears(false);

}


void CreditWindow::on_years_clicked()
{
    controller_credit_->SetTermInYears(true);

}


void CreditWindow::on_count_clicked()
{
   try {
        controller_credit_->CountCredit(ui->credit_sum->text().toStdString(),ui->credit_term->text().toStdString(), ui->credit_range->text().toStdString());
        ui->result_total->setText(QString::number(controller_credit_->GetCreditData().total_sum_));
        ui->result_percents->setText(QString::number(controller_credit_->GetCreditData().payble_percents_));
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
    controller_credit_->SetCreditType(false);

}


void CreditWindow::on_d_type_clicked()
{
     controller_credit_->SetCreditType(true);
}

