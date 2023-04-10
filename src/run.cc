#include <cstdlib>
#include <cstring>
#include <iostream>
// #include "controller/s21_controller.h"
#include "model/s21_model.h"
// #include "view/s21_view.h"

int main() {
  std::string src = "3+asin(x)";
  // std::cout << "compare " << src.compare(7, 6, "cos(x)");
  s21::Model m(src);
  std::cout << "is function " << m.IsFunction(src[2]) << std::endl;
  // std::cout << "is operator " << m.IsOperator(src[3]) << std::endl;
  // std::cout << "is hooks " << m.IsHooks(src[2]) << std::endl;
  //   size_t n = 0;
  //   static int i = 0;
  //   double num = std::stod(&src[i], &n);
  //   std::cout << "stod: " << num << std::endl;
  //   std::cout << n << std::endl;
  //   for (size_t j = n; j < 14; ++j) {
  //     std::cout << src[j];
  //   }
  //   i += n;
  //   num = std::stod(&src[i], &n);
  //   std::cout << std::endl << "stod: " << num << std::endl;
  //   std::cout << n << std::endl;
  //   for (size_t j = n + i; j < 14; ++j) {
  //     std::cout << src[j];
  //   }
  return 0;
}
