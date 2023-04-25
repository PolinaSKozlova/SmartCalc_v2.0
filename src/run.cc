#include <cstdlib>
#include <cstring>
#include <iostream>
// #include "controller/s21_controller.h"
#include "model/s21_model.h"
// #include "view/s21_view.h"
// #include "model/s21_extra_classes.h"

int main() {
  const std::string src = "187/5+9*(ln(10)^3.5)";
  // std::string src = "sqrt(5647*(9-(-78)))+46^3/250-log(1000)";
  // std::string src = "log(178)+634/2/0.5^3";
  s21::MathCalculator mc(src);
  mc.CalculateResultFromInput();
  std::cout << "result " << mc.GetAnswer() << std::endl;
  mc.print();
  // double res = 987.65 ^ (1 / 2) + 7 * tan(3 / 0.5);
  // std::cout << "res " << res << std::endl;
  return 0;
}
