#include "s21_credit_calculator.h"

#include <regex>

namespace s21 {
static double RoundNumber(double value) { return round(value * 100) / 100; }

void CreditCalculator::SetTermInYears(bool value) noexcept {
  data_.term_in_years_ = value;
}

void CreditCalculator::SetCreditType(bool value) noexcept {
  data_.is_differntiated = value;
}

void CreditCalculator::FillData(const std::string& sum, const std::string& term,
                                const std::string& range) {
  CheckCreditValues(sum, term, range);
  data_.credit_term_ = std::stoi(term);
  data_.credit_term_ = data_.FromYearsToMonths();
  CheckTerms();
  data_.credit_sum_ = std::stod(sum);
  data_.interest_rate_ = std::stod(range);
}

void CreditCalculator::AnnuitetMethod() noexcept {
  if (!data_.monthly_payment_.empty()) data_.monthly_payment_.clear();
  data_.interest_rate_ = data_.interest_rate_ / 100 / 12;
  data_.monthly_payment_.push_back(RoundNumber(
      data_.credit_sum_ *
      (data_.interest_rate_ /
       (1 - pow((1 + data_.interest_rate_), (data_.credit_term_ * -1))))));
  data_.total_sum_ = data_.monthly_payment_.front() * data_.credit_term_;
  data_.payble_percents_ = data_.total_sum_ - data_.credit_sum_;
}

void CreditCalculator::DifferntiatedMethod() noexcept {
  if (!data_.monthly_payment_.empty()) data_.monthly_payment_.clear();
  data_.interest_rate_ = data_.interest_rate_ / 100;
  double pay = 0;
  double perc_sum = 0;
  pay = data_.credit_sum_ / data_.credit_term_;
  data_.total_sum_ = data_.credit_sum_;
  int i = 0;
  while (i++ < data_.credit_term_) {
    data_.payble_percents_ = (data_.credit_sum_ * data_.interest_rate_) / 12;
    data_.payble_percents_ = RoundNumber(data_.payble_percents_);
    data_.monthly_payment_.push_back(data_.payble_percents_ + pay);
    perc_sum += data_.payble_percents_;
    data_.credit_sum_ -= pay;
  }
  data_.total_sum_ += perc_sum;
  data_.payble_percents_ = perc_sum;
}

void CreditCalculator::CheckCreditValues(const std::string& sum,
                                         const std::string& term,
                                         const std::string& range) const {
  if (!std::regex_match(sum, std::regex("(\\d*[.]?\\d*)")))
    throw std::invalid_argument("Incorrect sum value");
  if (!std::regex_match(term, std::regex("\\d*")))
    throw std::invalid_argument("Incorrect terms");
  if (!std::regex_match(range, std::regex("(\\d*[.]?\\d*)")))
    throw std::invalid_argument("Incorrect interest range");
  if (sum == "" || term == "" || range == "")
    throw std::invalid_argument("Empty values");
}

void CreditCalculator::CheckTerms() const {
  if ((data_.credit_term_ > 100 && data_.term_in_years_) ||
      (data_.credit_term_ > 1200 && !data_.term_in_years_))
    throw std::invalid_argument("Too long term");
}

};  // namespace s21
