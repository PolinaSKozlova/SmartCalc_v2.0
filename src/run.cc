#include <cstdlib>
#include <cstring>
#include <iostream>

#include "controller/s21_controller.h"
#include "model/s21_model.h"
// #include "view/s21_view.h"
// #include "model/s21_extra_classes.h"

int main() {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("96mod(x)", "5");
    std::cout << m.GetAnswer() << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  // const std::string src = "10-(1-6)";
  // std::string src = "sqrt(5647*(9-(-78)))+46^3/250-log(1000)";
  // std::string src = "log(178)+634/2/0.5^3";
  // s21::MathCalculator mc(src);
  // mc.CalculateResultFromInput();
  // std::cout << "result " << mc.GetAnswer() << std::endl;

  // s21::Controller c(src);
  // c.ParceAndCalculateExpression();
  // std::cout << "result " << c.GetOutputAnswer() << std::endl;
  // double res = 987.65 ^ (1 / 2) + 7 * tan(3 / 0.5);
  // std::cout << "res " << res << std::endl;
  return 0;
}

// model/s21_model.h
// model/s21_model.cc
// model/s21_token.h
// model/s21_tokenizer.h
// model/s21_tokenizer.cc
// model/s21_polish_notation.h
// model/s21_polish_notation.cc
// controller/s21_controller.h