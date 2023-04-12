#include <gtest/gtest.h>

#include "../model/s21_model.h"

TEST(validation_src_test_correct_fourth_priority, test_1) {
  std::string src = "cos(49)+sin(345.9)*cos(1)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_fourth_priority, test_2) {
  std::string src = "cos(1)+sin(-1)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_fourth_priority, test_3) {
  std::string src = "tan(439-274)*cos(29)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_fourth_priority, test_4) {
  std::string src = "atan(39+39)+acos(457)-asin(678)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_fourth_priority, test_5) {
  std::string src = "atan(1)-acos(0.5)+asin(-0.5)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_fourth_priority, test_6) {
  std::string src = "log(625)-ln(255)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_fourth_priority, test_7) {
  std::string src = "ln(89*.5)+log(1000000)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_fourth_priority, test_8) {
  std::string src = "x-ln(x*sqrt(x))";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_fourth_priority, test_9) {
  std::string src = "sqrt(64)-log(4000)+cos(20)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_fourth_priority, test_10) {
  std::string src = "acos(34)-sqrt(sin(78)+34)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_fourth_priority, test_11) {
  std::string src = "sqrt(389*389)/tan(5)+log(1000000)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_fourth_priority, test_12) {
  std::string src = "ln(2)-atan(0)*cos(30)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_fourth_priority, test_13) {
  std::string src = "x-ln(x)*sqrt(x)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_incorrect_fourth_priority, test_1) {
  std::string src = "sin65)-cos()3";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_incorrect_fourth_priority, test_2) {
  std::string src = "sin(45)+cas(37)-456*log(0)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_incorrect_fourth_priority, test_3) {
  std::string src = "32849-log(()";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_incorrect_fourth_priority, test_4) {
  std::string src = "lg(2.75)/log(100)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_incorrect_fourth_priority, test_5) {
  std::string src = "ln(2)-atan(0x)*cos(30)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_incorrect_fourth_priority, test_6) {
  std::string src = "sqrt(389*389)/tan(5)+log(100x0000)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_incorrect_fourth_priority, test_7) {
  std::string src = "tan(439-274)*cos(29) ";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}
