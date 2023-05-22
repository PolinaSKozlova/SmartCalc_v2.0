#include "s21_credit_calculator.h"

#include <regex>

static double RoundNumber(double value) { return round(value * 100) / 100; }

void s21::CreditCalculator::AnnuitetMethod() noexcept {
  data_.FromYearsToMonths();
  data_.interest_rate_ = data_.interest_rate_ / 100 / 12;
  data_.monthly_payment_.push_back(RoundNumber(
      data_.credit_sum_ *
      (data_.interest_rate_ /
       (1 - pow((1 + data_.interest_rate_), (data_.credit_term_ * -1))))));
  data_.total_sum_ = data_.monthly_payment_.front() * data_.credit_term_;
  data_.payble_percents_ = data_.total_sum_ - data_.credit_sum_;
}

void s21::CreditCalculator::CheckCreditValues(const std::string& sum,
                                              const std::string& term,
                                              const std::string& range) {
  if (!std::regex_match(sum, std::regex("(\\d*[.]?\\d*)")))
    throw std::invalid_argument("Incorrect sum value");
  if (!std::regex_match(term, std::regex("\\d*")))
    throw std::invalid_argument("Incorrect terms");
  if (!std::regex_match(range, std::regex("(\\d*[.]?\\d*)")))
    throw std::invalid_argument("Incorrect interest range");
  data_.credit_sum_ = std::stod(sum);
  data_.credit_term_ = std::stoi(term);
  data_.interest_rate_ = std::stod(range);
}

void s21::CreditCalculator::DifferntiatedMethod() noexcept {
  data_.FromYearsToMonths();
  data_.interest_rate_ = data_.interest_rate_ / 100;
  double pay = 0;
  double perc_sum = 0;
  pay = data_.credit_sum_ / data_.credit_term_;
  data_.total_sum_ = data_.credit_sum_;
  for (int i = 0; i < data_.credit_term_; ++i) {
    data_.payble_percents_ = (data_.credit_sum_ * data_.interest_rate_) / 12;
    data_.payble_percents_ = RoundNumber(data_.payble_percents_);
    data_.monthly_payment_.push_back(data_.payble_percents_ + pay);
    perc_sum += data_.payble_percents_;
    data_.credit_sum_ -= pay;
  }
  data_.total_sum_ += perc_sum;
  data_.payble_percents_ = perc_sum;
}

int s21::CreditInformation::FromYearsToMonths() {
  return term_in_years_ ? credit_term_ * 12 : credit_term_;
}
