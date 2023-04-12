#include <gtest/gtest.h>

#include "../model/s21_model.h"

TEST(calculation_src_test, test_1) {
  std::string src = "sqrt(5647*(9-(-78)))+46^3/250-log(1000)";
  s21::Model m(src);
  double result = 1087.2641095702704976;
  m.ValidationSrc();
  EXPECT_NEAR(m.CalculateExpression(), result, 1e-07);
}

TEST(calculation_src_test, test_2) {
  std::string src = "+986*0.0000001-(91mod3)^3";
  s21::Model m(src);
  double result = -0.9999014;
  m.ValidationSrc();
  EXPECT_EQ(m.CalculateExpression(), result);
}

TEST(calculation_src_test, test_3) {
  std::string src = "10000000+98/100000-cos(90)*(sqrt(625)";
  s21::Model m(src);
  double result = 0.0;
  m.ValidationSrc();
  EXPECT_NEAR(m.CalculateExpression(), result, 1e-07);
}