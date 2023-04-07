#include "s21_view.h"

bool s21::View::CheckHooks(std::string src) {}

bool s21::View::CheckDots(std::string src) {}

bool s21::View::IsFunction(std::string src) {}

bool s21::View::IsOperator(std::string src) {}

bool s21::View::IsHooks(std::string src) {}

void s21::View::ClearStack() {
  while (calc_notation_.size()) {
    calc_notation_.pop();
  }
}