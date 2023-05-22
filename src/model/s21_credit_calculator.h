#ifndef SMARTCALC_SRC_S21_CREDIT_CALCULATOR_H_
#define SMARTCALC_SRC_S21_CREDIT_CALCULATOR_H_

#include <cmath>
#include <string>
#include <vector>

namespace s21 {
class CreditInformation {
 public:
  CreditInformation() = default;
  // CreditInformation(
  //     double credit_sum, int credit_term, double interest_rate,
  //     double payble_percents, double total_sum,
  //     const std::vector<double>& monthly_payment = std::vector<double>(1),
  //     bool is_differntiated = false, bool term_in_years = false)
  //     : credit_sum_(credit_sum),
  //       credit_term_(credit_term),
  //       interest_rate_(interest_rate),
  //       monthly_payment_(monthly_payment),
  //       payble_percents_(payble_percents),
  //       total_sum_(total_sum),
  //       is_differntiated(is_differntiated),
  //       term_in_years_(term_in_years) {}
  // CreditInformation(const CreditInformation& other) { *this = other; }
  // CreditInformation& operator=(const CreditInformation& other) {
  //   credit_sum_ = other.credit_sum_;
  //   credit_term_ = other.credit_term_;
  //   interest_rate_ = other.interest_rate_;
  //   monthly_payment_ = other.monthly_payment_;
  //   payble_percents_ = other.payble_percents_;
  //   total_sum_ = other.total_sum_;
  //   is_differntiated = other.is_differntiated;
  //   term_in_years_ = other.term_in_years_;
  //   return *this;
  // }
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