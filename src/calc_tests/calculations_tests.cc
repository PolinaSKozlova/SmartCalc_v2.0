#include <gtest/gtest.h>

#include "../model/s21_model.h"

#define ACCURACY 1e-07

TEST(calculation_src_test, test_1) {
  s21::MathCalculator m;
  double result = 1087.2641095702704976;
  m.CalculateResultFromInput("sqrt(5647*(9-(-78)))+46^3/250-log(1000)");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_2) {
  s21::MathCalculator m;
  double result = -0.9999014;
  m.CalculateResultFromInput("+986*0.0000001-(91mod3)^3");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
  m.CalculateResultFromInput("+986*x-(91mod3)^3", "1e-7");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_3) {
  s21::MathCalculator m;
  double result = 10000011.2028204;
  m.CalculateResultFromInput("10000000+98/100000-cos(90)*(sqrt(625))");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_4) {
  s21::MathCalculator m;
  m.CalculateResultFromInput("log(-178)+634/2/0.5");
  EXPECT_TRUE(std::isnan(m.GetAnswer()));
}

TEST(calculation_src_test, test_5) {
  s21::MathCalculator m;
  double result = 2538.250420002308894;
  m.CalculateResultFromInput("log(178)+634/2/0.5^3");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_6) {
  s21::MathCalculator m;
  double result = -1.582661488475988;
  m.CalculateResultFromInput("atan(0)^3-155.87633/098.49mod(356-42)");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_7) {
  s21::MathCalculator m;
  double result = 4247.389013;
  m.CalculateResultFromInput("3958-sqrt(567^3-567)*ln(1)+289.389013");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_8) {
  s21::MathCalculator m;
  double result = 10000007.962414428;
  m.CalculateResultFromInput("100010001/3794*0.00034+9999999");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_9) {
  s21::MathCalculator m;
  m.CalculateResultFromInput("1.0/0.0+cos(180)-1.0/0.0");
  EXPECT_TRUE(std::isnan(m.GetAnswer()));
}

TEST(calculation_src_test, test_10) {
  s21::MathCalculator m;
  m.CalculateResultFromInput("cos(180)-1.0/0.0");
  EXPECT_TRUE(std::isinf(m.GetAnswer()));
}

TEST(calculation_src_test, test_11) {
  s21::MathCalculator m;
  m.CalculateResultFromInput("tan(50)/3+1.0/0.0");
  EXPECT_TRUE(std::isinf(m.GetAnswer()));
}
TEST(calculation_src_test, test_12) {
  s21::MathCalculator m;
  double result = -12.046197928264263;
  m.CalculateResultFromInput("150-cos(180)*150/5+(-180)");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_13) {
  s21::MathCalculator m;
  double result = 1.413056357344486;
  m.CalculateResultFromInput("(x+76.3-cos(x*4))/100", "66");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_14) {
  s21::MathCalculator m;
  double result = -0.55193482688;
  m.CalculateResultFromInput("cos(76-60)*(35mod7)-542/982");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_15) {
  s21::MathCalculator m;
  double result = 3.85919608528;
  m.CalculateResultFromInput("log(1000*ln(200*ln(1000)))");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
  result = 1;
  m.CalculateResultFromInput("10000*x", "1e-4");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_16) {
  s21::MathCalculator m;
  double result = -12.046197928264263;
  m.CalculateResultFromInput("150-cos(x)*150/5+(-x)", "180");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_17) {
  s21::MathCalculator m;
  double result = 439615.5;
  m.CalculateResultFromInput("879231*(1/2)+atan(0)/(sqrt(982-237*0.34))");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
  result = 5000.56237908;
  m.CalculateResultFromInput("cos(x)-x*(-5)", "1E3");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_18) {
  s21::MathCalculator m;
  double result = 1055077.2;
  m.CalculateResultFromInput("879231*(x)+atan(0)/(sqrt(982-x*0.34))", "1.2");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_19) {
  s21::MathCalculator m;
  m.CalculateResultFromInput("ln(100000)-78361+asin(2)-(645mod82)^7");
  EXPECT_TRUE(std::isnan(m.GetAnswer()));
}

TEST(calculation_src_test, test_20) {
  s21::MathCalculator m;
  double result = 0;
  m.CalculateResultFromInput("879231*(x)+atan(0)/(sqrt(982-x*0.34))");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_21) {
  s21::MathCalculator m;
  double result = 3.4785444;
  m.CalculateResultFromInput("8-cos(x^9)*7", "8");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_22) {
  s21::MathCalculator m;
  double result = 204.1237307;
  m.CalculateResultFromInput("187/5+9*(ln(10)^3.5)");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_23) {
  s21::MathCalculator m;
  double result = 2339.424035906;
  m.CalculateResultFromInput("46/3+5^2*(89+4)-sin(2)");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_24) {
  s21::MathCalculator m;
  double result = 2129.4498507030432;
  m.CalculateResultFromInput("46/3+5^2*(89+4)*sin(2)");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_25) {
  s21::MathCalculator m;
  double result = 29.3898559;
  m.CalculateResultFromInput("987.65^(1/2)+7*tan(3/0.5)");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_26) {
  s21::MathCalculator m;
  double result = 2.0044135;
  m.CalculateResultFromInput("2+tan(45)/(7-90*(-4))");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_27) {
  s21::MathCalculator m;
  double result = -49;
  m.CalculateResultFromInput("96mod2-98*(1/2)");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
  result = 9896;
  m.CalculateResultFromInput("96mod(x)-98*x", "-1e+2");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_28) {
  s21::MathCalculator m;
  double result = -93.0218387;
  m.CalculateResultFromInput("87.9/456+atan(1)-94");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_29) {
  s21::MathCalculator m;
  double result = 8.99808109;
  m.CalculateResultFromInput("sqrt(x)-cos(90+x)/log(10)", "64");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_30) {
  s21::MathCalculator m;
  double result = 1406.78106838;
  m.CalculateResultFromInput("46/3+5^2*(89+4)*sin(2.5)");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_31) {
  s21::MathCalculator m;
  double result = 0.0;
  m.CalculateResultFromInput("");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
  m.CalculateResultFromInput("cos(1-0)");
  result = 0.54030230586;
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_32) {
  s21::MathCalculator m;
  double result = 5764801;
  m.CalculateResultFromInput("x*x^x", "7");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_33) {
  s21::MathCalculator m;
  double result = 0.25;
  m.CalculateResultFromInput("x/x^(sqrt(x))", "4");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_34) {
  s21::MathCalculator m;
  double result = 0.25;
  m.CalculateResultFromInput("x/x^(sqrt(x))", "+4");
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
  m.CalculateResultFromInput("x/x^(sqrt(x))");
  result = 0.0;
  EXPECT_NEAR(result, m.GetAnswer(), ACCURACY);
}

TEST(calculation_src_test, test_35) {
  s21::MathCalculator m;
  m.CalculateResultFromInput("100/400");
  EXPECT_EQ(m.GetStringAnswer(), "0.25");
}
