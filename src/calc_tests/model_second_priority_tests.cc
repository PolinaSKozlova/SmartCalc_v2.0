#include <gtest/gtest.h>

#include "../model/s21_model.h"

TEST(validation_src_test_correct_second_priority, test_1) {
  std::string src = "4565*326/7.8";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_second_priority, test_2) {
  std::string src = "1000000/5678*(67.298*213.094)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_second_priority, test_3) {
  std::string src = "-43567.98*-100000/(3657*13.5697)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_second_priority, test_4) {
  std::string src = "x*(-x*(1/20))";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_second_priority, test_5) {
  std::string src = "0.0/0.0";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_second_priority, test_6) {
  std::string src = "-1.0/0.0*(0.0/0.0)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_second_priority, test_7) {
  std::string src = "569/3901/(199.237*23678.6785)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_second_priority, test_8) {
  std::string src = ".983169*(-1000000)/(24789.39*4691.5690)*100000";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_second_priority, test_9) {
  std::string src = "64769.4*57/(123*10000.001)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_second_priority, test_10) {
  std::string src = "64769.4*x/(123*x)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_second_priority, test_10) {
  std::string src = "1e+4*0.8743";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_incorrect_second_priority, test_1) {
  std::string src = "*569/3901/(199.237*23678.6785)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_incorrect_second_priority, test_2) {
  std::string src = "10000000-*-478.23472/381389";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_incorrect_second_priority, test_3) {
  std::string src = ".*367/3782";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_incorrect_second_priority, test_4) {
  std::string src = "x-0.0001*xx-890317/x";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_incorrect_second_priority, test_5) {
  std::string src = "x-0.0001*x-890317//x";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_incorrect_second_priority, test_6) {
  std::string src = "100000.00/478.23472*..381389";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}
