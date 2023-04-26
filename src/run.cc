#include <cstdlib>
#include <cstring>
#include <iostream>

#include "controller/s21_controller.h"
#include "model/s21_model.h"
// #include "view/s21_view.h"
// #include "model/s21_extra_classes.h"

int main() {
  const std::string src = "";
  // std::string src = "sqrt(5647*(9-(-78)))+46^3/250-log(1000)";
  // std::string src = "log(178)+634/2/0.5^3";
  s21::MathCalculator mc(src);
  mc.CalculateResultFromInput();
  std::cout << "result " << mc.GetAnswer() << std::endl;
  // s21::Controller c(src);
  // std::cout << "result " << c.ParceAndCalculateExpression() << std::endl;

  // double res = 987.65 ^ (1 / 2) + 7 * tan(3 / 0.5);
  // std::cout << "res " << res << std::endl;
  return 0;
}
