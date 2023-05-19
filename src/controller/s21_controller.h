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
    } catch (std::invalid_argument &e) {
      output_ = e.what();
    }
  }
  std::string GetOutputAnswer() const { return output_; }
  void GetCoordinates(const std::vector<double> &x_axes,
                      std::vector<double> &y_axes){

  };
  void CountCredit() {
    if (credit_->GetData().credit_type_) {
      credit_->DifferntiatedMethod();
    } else {
      credit_->AnnuitetMethod();
    }
  };
  s21::CreditInformation GetCreditData() const { return credit_->GetData(); }

 private:
  s21::MathCalculator *model_;
  s21::CreditCalculator *credit_;
  std::string output_{};
};
};  // namespace s21

#endif  // SMARTCALC_S21_CONTROLLER_H_
