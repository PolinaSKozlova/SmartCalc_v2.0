#include <gtest/gtest.h>

#include "../model/s21_model.h"

#define ACCURACY 1e-07

TEST(calculation_src_test, test_1) {
  std::string src = "sqrt(5647*(9-(-78)))+46^3/250-log(1000)";
  s21::MathCalculator m(src);
  double result = 1087.2641095702704976;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_2) {
  std::string src = "+986*0.0000001-(91mod3)^3";
  s21::MathCalculator m(src);
  double result = -0.9999014;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_3) {
  std::string src = "10000000+98/100000-cos(90)*(sqrt(625))";
  s21::MathCalculator m(src);
  double result = 10000011.2028204;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_4) {
  std::string src = "log(-178)+634/2/0.5";
  s21::MathCalculator m(src);
  m.CalculateResultFromInput();
  EXPECT_TRUE(std::isnan(m.GetAnswer()));
}

TEST(calculation_src_test, test_5) {
  std::string src = "log(178)+634/2/0.5^3";
  s21::MathCalculator m(src);
  double result = 2538.250420002308894;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_6) {
  std::string src = "atan(0)^3-155.87633/098.49mod(356-42)";
  s21::MathCalculator m(src);
  double result = -1.582661488475988;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_7) {
  std::string src = "3958-sqrt(567^3-567)*ln(1)+289.389013";
  s21::MathCalculator m(src);
  double result = 4247.389013;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_8) {
  std::string src = "100010001/3794*0.00034+9999999";
  s21::MathCalculator m(src);
  double result = 10000007.962414428;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_9) {
  std::string src = "1.0/0.0+cos(180)-1.0/0.0";
  s21::MathCalculator m(src);
  m.CalculateResultFromInput();
  EXPECT_TRUE(std::isnan(m.GetAnswer()));
}

TEST(calculation_src_test, test_10) {
  std::string src = "cos(180)-1.0/0.0";
  s21::MathCalculator m(src);
  m.CalculateResultFromInput();
  EXPECT_TRUE(std::isinf(m.GetAnswer()));
}

TEST(calculation_src_test, test_11) {
  std::string src = "tan(50)/3+1.0/0.0";
  s21::MathCalculator m(src);
  m.CalculateResultFromInput();
  EXPECT_TRUE(std::isinf(m.GetAnswer()));
}
TEST(calculation_src_test, test_12) {
  std::string src = "150-cos(180)*150/5+(-180)";
  s21::MathCalculator m(src);
  double result = -12.046197928264263;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_13) {
  std::string src = "(x+76.3-cos(x*4))/100";
  s21::MathCalculator m(src, "66");
  double result = 1.413056357344486;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_14) {
  std::string src = "cos(76-60)*35mod7-542/982";
  s21::MathCalculator m(src);
  double result = -0.55193482688;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_15) {
  std::string src = "log(1000*ln(200*ln(1000)))";
  s21::MathCalculator m(src);
  double result = 3.85919608528;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_16) {
  std::string src = "150-cos(x)*150/5+(-x)";
  s21::MathCalculator m(src, "180");
  double result = -12.046197928264263;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_17) {
  std::string src = "879231*(1/2)+atan(0)/(sqrt(982-237*0.34))";
  s21::MathCalculator m(src);
  double result = 439615.5;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_18) {
  std::string src = "879231*(x)+atan(0)/(sqrt(982-x*0.34))";
  s21::MathCalculator m(src, "1.2");
  double result = 1055077.2;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_19) {
  std::string src = "ln(100000)-78361+asin(2)-(645mod82)^7";
  s21::MathCalculator m(src);
  m.CalculateResultFromInput();
  EXPECT_TRUE(std::isnan(m.GetAnswer()));
}

TEST(calculation_src_test, test_20) {
  std::string src = "879231*(x)+atan(0)/(sqrt(982-x*0.34))";
  s21::MathCalculator m(src);
  double result = 0;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_21) {
  std::string src = "8-cos(x^9)*7";
  s21::MathCalculator m(src, "897");
  double result = 4.8220665018231;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_22) {
  std::string src = "187/5+9*(ln(10))^3.5)";
  s21::MathCalculator m(src);
  double result = 204.124;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_23) {
  std::string src = "46/3+5^2*(89+4)-sin(2)";
  s21::MathCalculator m(src);
  double result = 2339.424035906;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_24) {
  std::string src = "46/3+5^2*(89+4)*sin(2)";
  s21::MathCalculator m(src);
  double result = 2129.4498507030432;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_25) {
  std::string src = "987.65^1/2+7*tan(3/0.5)";
  s21::MathCalculator m(src);
  double result = 29.3899;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_26) {
  std::string src = "2+tan(45)/(7-90*(-4))";
  s21::MathCalculator m(src);
  double result = 2.0044135;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_27) {
  std::string src = "96mod2-98*(1/2)";
  s21::MathCalculator m(src);
  double result = -49;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_28) {
  std::string src = "87.9/456+atan(1)-94";
  s21::MathCalculator m(src);
  double result = -93.0218387;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_29) {
  std::string src = "sqrt(x)-cos(90+x)/log(10)";
  s21::MathCalculator m(src, "64");
  double result = 8.99808109;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_30) {
  std::string src = "46/3+5^2*(89+4)*sin(2.5)";
  s21::MathCalculator m(src);
  double result = 1406.78106838;
  m.CalculateResultFromInput();
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}