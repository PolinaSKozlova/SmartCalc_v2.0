#ifndef SMARTCALC_CREDIT_CALCULATOR_H_
#define SMARTCALC_CREDIT_CALCULATOR_H_

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace smartcalc {
class CreditInformation {
 public:
  CreditInformation() = default;
  CreditInformation(double credit_sum, int credit_term, double interest_rate,
                    const std::vector<double>& monthly_payment,
                    double payble_percents = 0.0, double total_sum = 0.0,
                    bool is_differntiated = false, bool term_in_years = false)
      : credit_sum_(credit_sum),
        credit_term_(credit_term),
        interest_rate_(interest_rate),
        monthly_payment_(monthly_payment),
        payble_percents_(payble_percents),
        total_sum_(total_sum),
        is_differntiated(is_differntiated),
        term_in_years_(term_in_years) {
    credit_term = FromYearsToMonths();
  }
  ~CreditInformation() = default;
  int FromYearsToMonths() {
    return term_in_years_ ? (credit_term_ * 12) : credit_term_;
  }
  double credit_sum_{};
  int credit_term_{};
  double interest_rate_{};
  std::vector<double> monthly_payment_;
  double payble_percents_{};
  double total_sum_{};
  bool is_differntiated = false;
  bool term_in_years_ = false;
};

class CreditCalculator {
 public:
  CreditCalculator() = default;
  explicit CreditCalculator(const CreditInformation& data) : data_(data) {}
  ~CreditCalculator() = default;
  CreditInformation GetData() const noexcept { return data_; }
  void CalculateCredit(const std::string& sum, const std::string& term,
                       const std::string& range);
  void SetTermInYears(bool value) noexcept;
  void SetCreditType(bool value) noexcept;
  void FillData(const std::string& sum, const std::string& term,
                const std::string& range);

 private:
  void AnnuitetMethod() noexcept;
  void DifferntiatedMethod() noexcept;
  void CheckCreditValues(const std::string& sum, const std::string& term,
                         const std::string& range) const;
  void CheckTerms() const;
  void CheckSum() const;
  void CheckRange() const;
  CreditInformation data_{};
};
};  // namespace smartcalc

#endif  // SMARTCALC_CREDIT_CALCULATOR_H_