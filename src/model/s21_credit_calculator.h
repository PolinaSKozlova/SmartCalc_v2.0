#ifndef SMARTCALC_SRC_S21_CREDIT_CALCULATOR_H_
#define SMARTCALC_SRC_S21_CREDIT_CALCULATOR_H_

#include <cmath>
#include <vector>

namespace s21 {
class CreditInformation {
 public:
  CreditInformation(double credit_sum, int credit_term, double interest_rate,
                    std::vector<double> monthly_payment, double payble_percents,
                    double total_sum, bool term_in_years)
      : credit_sum_(credit_sum),
        credit_term_(credit_term),
        interest_rate_(interest_rate),
        monthly_payment_(monthly_payment),
        payble_percents_(payble_percents),
        total_sum_(total_sum),
        term_in_years_(term_in_years) {}
  ~CreditInformation() = default;
  CreditInformation GetInformation() const noexcept { return *this; }
  int FromYearsToMonths();
  double credit_sum_;
  int credit_term_;
  double interest_rate_;
  std::vector<double> monthly_payment_;
  double payble_percents_;
  double total_sum_;
  bool term_in_years_;
};

class CreditCalculator {
 public:
  explicit CreditCalculator(const CreditInformation& data) : data_(data) {}
  ~CreditCalculator() = default;
  CreditInformation GetData() const noexcept { return data_.GetInformation(); }
  void AnnuitetMethod() noexcept;
  void DifferntiatedMethod() noexcept;

 private:
  CreditInformation data_;
};
};  // namespace s21

#endif  // SMARTCALC_SRC_S21_CREDIT_CALCULATOR_H_