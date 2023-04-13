#include <gtest/gtest.h>

#include "../model/s21_model.h"

TEST(validation_src_test_correct_third_priority, test_1) {
  std::string src = "(-459.29)^234";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_third_priority, test_2) {
  std::string src = "(5^7)^0.2";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_third_priority, test_3) {
  std::string src = "((47298-283))+97.321738";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_third_priority, test_4) {
  std::string src = "67^(4.5-4+(230491/4461846))";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_third_priority, test_5) {
  std::string src = "-5678+(36^2.45)-(-1000000)mod5";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_third_priority, test_6) {
  std::string src = "(-35^4.553)+567^-2";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_third_priority, test_7) {
  std::string src = "4^2^3^4";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_third_priority, test_8) {
  std::string src = "45*(80981/(7592+73389)*(47289-47289))/5";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_third_priority, test_9) {
  std::string src = "x+478-(x+(-2784))";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_third_priority, test_10) {
  std::string src = "x^x^x^(1/x)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_third_priority, test_11) {
  std::string src = "1e-7+cos(4)*1e+3";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_incorrect_third_priority, test_1) {
  std::string src = "^247^(0.4379)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_incorrect_third_priority, test_2) {
  std::string src = "4269+478=48";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_incorrect_third_priority, test_3) {
  std::string src = ".367^..3782";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_incorrect_third_priority, test_4) {
  std::string src = "x*(0.0001*x)x-890317/x";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_incorrect_third_priority, test_5) {
  std::string src = "x-0.0001*x-890317/()-x";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_incorrect_third_priority, test_6) {
  std::string src = "100000.00/478.23472(381389)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_incorrect_third_priority, test_7) {
  std::string src = "1ee-7+cos(4)*1e+3";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}
