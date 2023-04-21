#include <gtest/gtest.h>

#include "../model/s21_model.h"

TEST(validation_src_test_incorrect_first_priority, test_1) {
  std::string src = "10000000-478.23472-381389+.";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_first_priority, test_2) {
  std::string src = "10000000-+-478.23472-381389";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_first_priority, test_3) {
  std::string src = "10000000-sgh-478.23472-381389";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_first_priority, test_4) {
  std::string src = "x-0.0001+xx-890317+x";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_first_priority, test_5) {
  std::string src = "10000000-+478.23472-381389(x)";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_first_priority, test_6) {
  std::string src = "100000.00--478.23472-..381389";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}