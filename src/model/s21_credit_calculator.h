#ifndef SRC_S21_CREDIT_CALCULATOR_H_
#define SRC_S21_CREDIT_CALCULATOR_H_

#include <cmath>

namespace s21 {
class CreditInformation {
 public:
  CreditInformation(double credit_sum, int credit_term, double interest_rate,
                    double monthly_payment, double payble_percents,
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
  double credit_sum_;
  int credit_term_;
  double interest_rate_;
  double monthly_payment_;
  double payble_percents_;
  double total_sum_;
  bool term_in_years_;
};

class CreditCalculator {
 public:
  CreditCalculator() {}
  ~CreditCalculator() = default;

 private:
  CreditInformation data_;
};
};  // namespace s21

#endif  // SRC_S21_CREDIT_CALCULATOR_H_