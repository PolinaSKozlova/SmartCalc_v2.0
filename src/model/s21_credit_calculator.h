#ifndef SMARTCALC_SRC_S21_CREDIT_CALCULATOR_H_
#define SMARTCALC_SRC_S21_CREDIT_CALCULATOR_H_

#include <cmath>
#include <string>
#include <vector>

namespace s21 {
class CreditInformation {
 public:
  CreditInformation() = default;
  ~CreditInformation() = default;
  CreditInformation GetInformation() noexcept { return *this; }
  void CheckCreditValues(const std::string& sum, const std::string& term,
                         const std::string& range);
  int FromYearsToMonths();
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
  CreditInformation GetData() noexcept { return data_.GetInformation(); }
  void CheckCreditValues(const std::string& sum, const std::string& term,
                         const std::string& range);
  void AnnuitetMethod() noexcept;
  void DifferntiatedMethod() noexcept;

 private:
  CreditInformation data_{};
};
};  // namespace s21

#endif  // SMARTCALC_SRC_S21_CREDIT_CALCULATOR_H_