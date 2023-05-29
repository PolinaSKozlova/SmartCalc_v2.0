#include <cstdlib>
#include <cstring>
#include <iostream>

#include "controller/s21_controller.h"
#include "model/s21_model.h"
// #include "view/s21_view.h"
// #include "model/s21_extra_classes.h"

int main() {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("+986*x-(91mod3)^3");
    std::cout << m.GetAnswer() << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  // s21::CreditCalculator cr;
  // s21::Controller c(&m, &cr);
  // std::vector<double> mp;
  // s21::CreditInformation info(2000000, 2, 12.5, mp);
  // s21::CreditCalculator cr(info);
  // cr.SetTermInYears(true);

  // cr.AnnuitetMethod();

  // std::cout << cr.GetData().credit_sum_ << " " << cr.GetData().credit_term_
  //           << " " << cr.GetData().term_in_years_ << " "
  //           << cr.GetData().interest_rate_ << " " << std::endl;
  // std::cout << cr.GetData().total_sum_ << " "
  //           << cr.GetData().monthly_payment_.front() << " "
  //           << cr.GetData().payble_percents_ << std::endl;
  return 0;
}
