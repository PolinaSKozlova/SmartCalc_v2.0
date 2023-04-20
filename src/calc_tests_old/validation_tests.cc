#include <gtest/gtest.h>

#include "../model/s21_model.h"

TEST(validation_src_test_correct, test_1) {
  std::string src = "8-cos(x^9)*7";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct, test_2) {
  std::string src = "187/5+9*(ln(10))^3.5";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct, test_3) {
  std::string src = "46/3+5^2*(89+4)-sin(2)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct, test_4) {
  std::string src = "46/3+5^2*(89+4)*sin(2)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct, test_5) {
  std::string src = "987.65^1/2+7*tan(3/0.5)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct, test_6) {
  std::string src = "2+tan(45)/(7-90*-4)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct, test_7) {
  std::string src = "+67*(asin(-2)/5)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct, test_8) {
  std::string src = "96mod2-98*(1/2)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct, test_9) {
  std::string src = "87.9/456+atan(1)-94";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct, test_10) {
  std::string src = "sqrt(64)-acos(90+3)/log(10)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct, test_11) {
  std::string src = "";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct, test_12) {
  std::string src = "46/3+5^2*.(89+4)*sin(2)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_correct, test_13) {
  std::string src = "sin(-30)+()-34.5";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_correct, test_14) {
  std::string src = "46/3+5^2*(89+4)*san(2)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_correct, test_15) {
  std::string src = "46/3+5^2*(89+)*sin(2)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_correct, test_16) {
  std::string src = "46/3+5^2*(89+4)*sin2";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_correct, test_17) {
  std::string src = "56.-90(cos(3))";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_correct, test_18) {
  std::string src = "56.-90*cos(3))^";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_correct, test_19) {
  std::string src = "57+[-9]*(46-24/3)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_correct, test_20) {
  std::string src = ".*567.98*(-cos(x))";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_correct, test_21) {
  std::string src = "567.98*(-cos(x))mod";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_correct, test_22) {
  std::string src = "mod5-90/7";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_correct, test_23) {
  std::string src = "5467.43.290+327-cos(0)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_correct, test_24) {
  std::string src = "xx+cos(45)+sin(x)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_correct, test_25) {
  std::string src = ".";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}