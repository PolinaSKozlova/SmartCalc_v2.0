#include "creditwindow.h"

#include <QErrorMessage>
#include <QMessageBox>

#include "ui_creditwindow.h"

CreditWindow::CreditWindow(smartcalc::Controller *controller, QWidget *parent)
    : controller_credit_(controller),
      QMainWindow(parent),
      ui(new Ui::CreditWindow) {
  ui->setupUi(this);
  setFixedSize(891, 721);
  ui->months->setChecked(true);
  ui->a_type->setChecked(true);
  ui->result_frame->setFixedSize(851, 201);
}

CreditWindow::~CreditWindow() { delete ui; }

void CreditWindow::on_months_clicked() {
  controller_credit_->SetTermInYears(false);
}

void CreditWindow::on_years_clicked() {
  controller_credit_->SetTermInYears(true);
}

void CreditWindow::on_count_clicked() {
  controller_credit_->CountCredit(ui->credit_sum->text().toStdString(),
                                  ui->credit_term->text().toStdString(),
                                  ui->credit_range->text().toStdString());
  if (controller_credit_->GetHasException()) {
    QMessageBox::critical(
        this, "ERROR",
        QString::fromStdString(controller_credit_->GetOutputAnswer()));
  } else {
    ui->result_total->setText(QString::number(
        controller_credit_->GetCreditData().total_sum_, 'q', 2));
    ui->result_percents->setText(QString::number(
        controller_credit_->GetCreditData().payble_percents_, 'q', 2));
    if (controller_credit_->GetCreditData().is_differntiated) {
      ui->list_of_payments->clear();
      ui->result_monthly_pay->setText(
          QString::number(
              controller_credit_->GetCreditData().monthly_payment_.front(), 'q',
              2) +
          "..." +
          QString::number(
              controller_credit_->GetCreditData().monthly_payment_.back(), 'q',
              2));
      for (int i = 0;
           i < controller_credit_->GetCreditData().monthly_payment_.size();
           ++i) {
        ui->list_of_payments->insertPlainText(
            QString::number(i + 1) + ") " +
            QString::number(
                controller_credit_->GetCreditData().monthly_payment_[i]) +
            "\n");
      }
    } else {
      ui->result_monthly_pay->setText(QString::number(
          controller_credit_->GetCreditData().monthly_payment_.front(), 'q',
          2));
    }
  }
}

void CreditWindow::on_clear_clicked() {
  ui->credit_range->clear();
  ui->credit_sum->clear();
  ui->credit_term->clear();
  ui->result_monthly_pay->clear();
  ui->result_percents->clear();
  ui->result_total->clear();
  ui->list_of_payments->clear();
  ui->months->setChecked(true);
  ui->a_type->setChecked(true);
  ui->result_frame->setFixedSize(851, 201);
}

void CreditWindow::on_a_type_clicked() {
  controller_credit_->SetCreditType(false);
  ui->result_frame->setFixedSize(851, 201);
}

void CreditWindow::on_d_type_clicked() {
  controller_credit_->SetCreditType(true);
  ui->result_frame->setFixedSize(851, 331);
}

void CreditWindow::on_actionMathCalc_triggered() {
  hide();
  emit showParent();
}

void CreditWindow::on_actionDepositCalc_triggered() {
  QMessageBox::information(this, "Справка", "Раздел в разработке ¯| _(ツ)_ |¯");
  show();
}
