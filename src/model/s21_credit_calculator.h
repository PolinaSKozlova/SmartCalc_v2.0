#ifndef SMARTCALC_SRC_S21_CREDIT_CALCULATOR_H_
#define SMARTCALC_SRC_S21_CREDIT_CALCULATOR_H_

#include <cmath>
#include <vector>

namespace s21 {
class CreditInformation {
 public:
  CreditInformation() = default;
  CreditInformation(double credit_sum, int credit_term, double interest_rate,
                    const std::vector<double>& monthly_payment,
                    double payble_percents, double total_sum,
                    bool credit_type = false, bool term_in_years = false)
      : credit_sum_(credit_sum),
        credit_term_(credit_term),
        interest_rate_(interest_rate),
        monthly_payment_(monthly_payment),
        payble_percents_(payble_percents),
        total_sum_(total_sum),
        credit_type_(credit_type),
        term_in_years_(term_in_years) {}
  CreditInformation(const CreditInformation& other) { *this = other; }
  CreditInformation& operator=(const CreditInformation& other) {
    credit_sum_ = other.credit_sum_;
    credit_term_ = other.credit_term_;
    interest_rate_ = other.interest_rate_;
    monthly_payment_ = other.monthly_payment_;
    payble_percents_ = other.payble_percents_;
    total_sum_ = other.total_sum_;
    credit_type_ = other.credit_type_;
    term_in_years_ = other.term_in_years_;
    return *this;
  }
  ~CreditInformation() = default;
  CreditInformation GetInformation() const noexcept { return *this; }
  void CheckCreditValues(const std::string& sum, const std::string& term,
                         const std::string& range);
  int FromYearsToMonths();

  double credit_sum_;
  int credit_term_;
  double interest_rate_;
  std::vector<double> monthly_payment_;
  double payble_percents_;
  double total_sum_;
  bool credit_type_;
  bool term_in_years_;
};

class CreditCalculator {
 public:
  CreditCalculator() = default;
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