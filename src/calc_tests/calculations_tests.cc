#include <gtest/gtest.h>

#include "../model/s21_model.h"

TEST(calculation_src_test, test_1) {
  std::string src = "sqrt(5647*(9-(-78)))+46^3/250-log(1000)";
  s21::Model m(src);
  double result = 1087.2641095702704976;
  EXPECT_EQ(m.CalculateExpression(), result);
}

TEST(calculation_src_test, test_2) {
  std::string src = "+986*0.0000001-(91mod3)^3";
  s21::Model m(src);
  double result = -0.9999014;
  EXPECT_EQ(m.CalculateExpression(), result);
}
