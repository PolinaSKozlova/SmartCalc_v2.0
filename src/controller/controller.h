#ifndef SMARTCALC_CONTROLLER_H_
#define SMARTCALC_CONTROLLER_H_

#include "../model/credit_calculator.h"
#include "../model/model.h"

namespace smartcalc {
class Controller {
 public:
  Controller() = default;
  explicit Controller(smartcalc::MathCalculator *other,
                      smartcalc::CreditCalculator *credit)
      : model_(other), credit_(credit) {}
  ~Controller() = default;
  void ParceAndCalculateExpression(const std::string &src,
                                   const std::string &x_value = "0.0") {
    try {
      model_->CalculateResultFromInput(src, x_value);
      output_ = model_->GetStringAnswer();
      has_exception = false;
    } catch (std::exception &e) {
      output_ = e.what();
      has_exception = true;
    }
  }
  void GetCoordinatesForChartArea(
      const std::string &src, MaxMinValues max_min_values,
      std::pair<std::vector<double>, std::vector<double>> &xy_pairs) {
    model_->CountCoordinatesForChartArea(src, max_min_values, xy_pairs);
  }
  void CountCredit(const std::string &sum, const std::string &term,
                   const std::string &range) {
    try {
      credit_->CalculateCredit(sum, term, range);
      has_exception = false;
    } catch (std::exception &e) {
      output_ = e.what();
      has_exception = true;
    }
  }
  void SetTermInYears(bool term_in_years) {
    credit_->SetTermInYears(term_in_years);
  }
  void SetCreditType(bool is_differntiated) {
    credit_->SetCreditType(is_differntiated);
  }
  std::string GetOutputAnswer() const { return output_; }
  bool GetHasException() const { return has_exception; }
  smartcalc::CreditInformation GetCreditData() const {
    return credit_->GetData();
  }

 private:
  smartcalc::MathCalculator *model_;
  smartcalc::CreditCalculator *credit_;
  std::string output_{};
  bool has_exception = false;
};
};  // namespace smartcalc

#endif  // SMARTCALC_CONTROLLER_H_
