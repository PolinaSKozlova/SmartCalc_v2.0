#include <gtest/gtest.h>

#include <cmath>

#include "../old_model/s21_model_old.h"

#define ACCURACY 1e-07

TEST(calculation_src_test, test_1) {
  std::string src = "sqrt(5647*(9-(-78)))+46^3/250-log(1000)";
  s21::Model m(src);
  double result = 1087.2641095702704976;
  EXPECT_EQ(m.StartSmartCalc(), result, ACCURACY)
  // m.ValidationSrc();
  // EXPECT_NEAR(m.CalculateResultFromInput(), result, ACCURACY);
}

TEST(calculation_src_test, test_2) {
  std::string src = "+986*0.0000001-(91mod3)^3";
  s21::Model m(src);
  double result = -0.9999014;
  m.ValidationSrc();
  EXPECT_NEAR(m.CalculateResultFromInput(), result, ACCURACY);
}

TEST(calculation_src_test, test_3) {
  std::string src = "10000000+98/100000-cos(90)*(sqrt(625))";
  s21::Model m(src);
  double result = 10000011.2028204;
  m.ValidationSrc();
  EXPECT_NEAR(m.CalculateResultFromInput(), result, ACCURACY);
}

TEST(calculation_src_test, test_4) {
  std::string src = "log(-178)+634/2/0.5";
  s21::Model m(src);
  m.ValidationSrc();
  EXPECT_TRUE(std::isnan(m.CalculateResultFromInput()));
}

TEST(calculation_src_test, test_5) {
  std::string src = "log(178)+634/2/0.5^3";
  s21::Model m(src);
  double result = 2538.250420002308894;
  m.ValidationSrc();
  EXPECT_NEAR(m.CalculateResultFromInput(), result, ACCURACY);
}

TEST(calculation_src_test, test_6) {
  std::string src = "atan(0)^3-155.87633/098.49mod(356-42)";
  s21::Model m(src);
  double result = -1.582661488475988;
  m.ValidationSrc();
  EXPECT_NEAR(m.CalculateResultFromInput(), result, ACCURACY);
}

TEST(calculation_src_test, test_7) {
  std::string src = "3958-sqrt(567^3-567)*ln(1)+289.389013";
  s21::Model m(src);
  double result = 4247.389013;
  m.ValidationSrc();
  EXPECT_NEAR(m.CalculateResultFromInput(), result, ACCURACY);
}

TEST(calculation_src_test, test_8) {
  std::string src = "100010001/3794*0.00034+9999999";
  s21::Model m(src);
  double result = 10000007.962414428;
  m.ValidationSrc();
  EXPECT_NEAR(m.CalculateResultFromInput(), result, ACCURACY);
}

TEST(calculation_src_test, test_9) {
  std::string src = "1.0/0.0+cos(180)-1.0/0.0";
  s21::Model m(src);
  m.ValidationSrc();
  EXPECT_TRUE(std::isnan(m.CalculateResultFromInput()));
}

TEST(calculation_src_test, test_10) {
  std::string src = "cos(180)-1.0/0.0";
  s21::Model m(src);
  m.ValidationSrc();
  EXPECT_TRUE(std::isinf(m.CalculateResultFromInput()));
}

TEST(calculation_src_test, test_11) {
  std::string src = "tan(50)/3+1.0/0.0";
  s21::Model m(src);
  m.ValidationSrc();
  EXPECT_TRUE(std::isinf(m.CalculateResultFromInput()));
}

TEST(calculation_src_test, test_12) {
  std::string src = "150-cos(180)*150/5+(-180)";
  s21::Model m(src);
  double result = -12.046197928264263;
  m.ValidationSrc();
  EXPECT_NEAR(m.CalculateResultFromInput(), result, ACCURACY);
}

// TEST(calculation_src_test, test_13) {
//   std::string src = "(x+76.3-cos(x*4))/100";
//   s21::Model m(src);
//   double result = 1.413056357344486;
//   double x = 66;
//   m.ValidationSrc();
//   EXPECT_NEAR(m.CalculateResultFromInput(), result, ACCURACY);
// }
