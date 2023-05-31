#ifndef SMARTCALC_S21_CONTROLLER_H_
#define SMARTCALC_S21_CONTROLLER_H_

#include "../model/s21_credit_calculator.h"
#include "../model/s21_model.h"

namespace s21 {
class Controller {
 public:
  Controller() = default;
  explicit Controller(s21::MathCalculator *other, s21::CreditCalculator *credit)
      : model_(other), credit_(credit) {}
  ~Controller() = default;
  void ParceAndCalculateExpression(const std::string &src,
                                   const std::string &x_value = "0.0") {
    try {
      model_->CalculateResultFromInput(src, x_value);
      output_ = model_->GetStringAnswer();
      has_exception = false;
    } catch (std::invalid_argument &e) {
      output_ = e.what();
      has_exception = true;
    }
  }
  std::string GetOutputAnswer() const { return output_; }
  bool GetHasException() const { return has_exception; }
  std::pair<std::vector<double>, std::vector<double>>
  GetCoordinatesForChartArea(const std::string &src,
                             MaxMinValues max_min_values) {
    return model_->CountCoordinatesForChartArea(src, max_min_values);
  }
  void CountCredit(const std::string &sum, const std::string &term,
                   const std::string &range) {
    try {
      credit_->FillData(sum, term, range);
      has_exception = false;
    } catch (std::invalid_argument &e) {
      throw e;
      output_ = e.what();
      has_exception = true;
    }
    if (credit_->GetData().is_differntiated) {
      credit_->DifferntiatedMethod();
    } else {
      credit_->AnnuitetMethod();
    }
  }
  void SetTermInYears(bool term_in_years) {
    credit_->SetTermInYears(term_in_years);
  }
  void SetCreditType(bool is_differntiated) {
    credit_->SetCreditType(is_differntiated);
  }
  s21::CreditInformation GetCreditData() const { return credit_->GetData(); }

 private:
  s21::MathCalculator *model_;
  s21::CreditCalculator *credit_;
  std::string output_{};
  bool has_exception = false;
};
};  // namespace s21

#endif  // SMARTCALC_S21_CONTROLLER_H_
