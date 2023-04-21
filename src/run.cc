#include <cstdlib>
#include <cstring>
#include <iostream>
// #include "controller/s21_controller.h"
#include "model/s21_model.h"
// #include "view/s21_view.h"
// #include "model/s21_extra_classes.h"

int main() {
  const std::string src = "+986*0.0000001-(91mod3)^3";
  // const std::string src = "x*0.0001";
  // s21::Tokenizer tokenizer(src, "6.");
  // tokenizer.CreateTokenOutput();
  s21::MathCalculator mc(src);
  mc.CalculateResultFromInput();
  mc.print();

  // auto res = m.StartSmartCalc();
  // std::cout << "result " << res.first << " " << res.second << std::endl;
  // if (res.first) {
  //   double ans = m.CalculateExpression();
  //   std::cout << "number " << ans << std::endl;
  // }
  // m.print();
  return 0;
}
