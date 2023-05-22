#ifndef SMARTCALC_SRC_S21_CREDIT_CALCULATOR_H_
#define SMARTCALC_SRC_S21_CREDIT_CALCULATOR_H_

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace s21 {
class CreditInformation {
 public:
  CreditInformation() = default;
  ~CreditInformation() = default;
  int FromYearsToMonths() {
    return term_in_years_ ? (credit_term_ * 12) : credit_term_;
  }
  double credit_sum_{};
  int credit_term_{};
  double interest_rate_{};
  double payble_percents_{};
  double total_sum_{};
  std::vector<double> monthly_payment_;
  bool is_differntiated = false;
  bool term_in_years_ = false;
};

class CreditCalculator {
 public:
  CreditCalculator() = default;
  explicit CreditCalculator(const CreditInformation& data) : data_(data) {}
  ~CreditCalculator() = default;
  CreditInformation GetData() const noexcept { return data_; }
  void SetTermInYears(bool value) noexcept;
  void SetCreditType(bool value) noexcept;
  void CheckCreditValues(const std::string& sum, const std::string& term,
                         const std::string& range);
  void AnnuitetMethod() noexcept;
  void DifferntiatedMethod() noexcept;

 private:
  CreditInformation data_{};
};
};  // namespace s21

#endif  // SMARTCALC_SRC_S21_CREDIT_CALCULATOR_H_