#include <gtest/gtest.h>

#include "../model/s21_credit_calculator.h"

#define ACCURACY 1e-02

TEST(credit_annuitet_test, test_1) {
  std::vector<double> mp;
  s21::CreditInformation info(150000, 12, 15, mp);
  s21::CreditCalculator cr(info);
  cr.AnnuitetMethod();
  EXPECT_NEAR(cr.GetData().total_sum_, 162465, ACCURACY);
  EXPECT_NEAR(cr.GetData().payble_percents_, 12465, ACCURACY);
  EXPECT_NEAR(cr.GetData().monthly_payment_.front(), 13538.75, ACCURACY);
}

TEST(credit_annuitet_test, test_2) {
  std::vector<double> mp;
  s21::CreditInformation info(2000000, 2, 12.5, mp, 0.0, 0.0, false, true);
  s21::CreditCalculator cr(info);
  cr.AnnuitetMethod();
  EXPECT_NEAR(cr.GetData().total_sum_, 2270750.88, ACCURACY);
  EXPECT_NEAR(cr.GetData().payble_percents_, 270750.88, ACCURACY);
  EXPECT_NEAR(cr.GetData().monthly_payment_.front(), 94614.62, ACCURACY);
}

TEST(credit_different_test, test_1) {
  std::vector<double> mp;
  s21::CreditInformation info(150000, 12, 13, mp, 0.0, 0.0, true);
  s21::CreditCalculator cr(info);
  cr.DifferntiatedMethod();
  EXPECT_NEAR(cr.GetData().total_sum_, 160562.50, ACCURACY);
  EXPECT_NEAR(cr.GetData().payble_percents_, 10562.50, ACCURACY);
  EXPECT_NEAR(cr.GetData().monthly_payment_.front(), 14125, ACCURACY);
  EXPECT_NEAR(cr.GetData().monthly_payment_.back(), 12635.42, ACCURACY);
}

TEST(credit_different_test, test_2) {
  std::vector<double> mp;
  s21::CreditInformation info(2000000, 2, 12.5, mp, 0.0, 0.0, true, true);
  s21::CreditCalculator cr(info);
  cr.DifferntiatedMethod();
  EXPECT_NEAR(cr.GetData().total_sum_, 2260416.67, ACCURACY);
  EXPECT_NEAR(cr.GetData().payble_percents_, 260416.67, ACCURACY);
  EXPECT_NEAR(cr.GetData().monthly_payment_.front(), 104166.67, ACCURACY);
  EXPECT_NEAR(cr.GetData().monthly_payment_.back(), 84201.39, ACCURACY);
}

TEST(credit_incorrect_test, test_1) {
  try {
    std::vector<double> mp;
    s21::CreditInformation info(0, 0, 0, mp, 0.0, 0.0, true, true);
    s21::CreditCalculator cr(info);
    cr.CheckCreditValues("2000000", "1201", "12");
  } catch (...) {
  }
}

TEST(credit_incorrect_test, test_2) {
  try {
    s21::CreditCalculator cr;
    cr.CheckCreditValues("-100000", "2", "12");
  } catch (...) {
  }
}

TEST(credit_incorrect_test, test_3) {
  try {
    s21::CreditCalculator cr;
    cr.CheckCreditValues("100000", "2", "1..2");
  } catch (...) {
  }
}

TEST(credit_incorrect_test, test_4) {
  try {
    s21::CreditCalculator cr;
    cr.CheckCreditValues("100000", "2.6", "12");
  } catch (...) {
  }
}

TEST(credit_incorrect_test, test_5) {
  try {
    std::vector<double> mp;
    s21::CreditInformation info(0, 0, 0, mp, 0.0, 0.0, false, true);
    s21::CreditCalculator cr(info);
    cr.CheckCreditValues("2000000", "101", "12");
  } catch (...) {
  }
}
