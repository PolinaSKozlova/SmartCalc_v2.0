#include <cstdlib>
#include <cstring>
#include <iostream>
// #include "controller/s21_controller.h"
#include "model/s21_model.h"
// #include "view/s21_view.h"

int main() {
  std::string src = "567--2";
  s21::Model m(src);
  auto res = m.ValidationSrc();
  std::cout << "result validation " << res.first << " " << res.second
            << std::endl;
  // m.print();
  return 0;
}
