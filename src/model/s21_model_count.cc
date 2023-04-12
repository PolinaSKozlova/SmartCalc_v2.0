#include "s21_model.h"

double s21::Model::CalculateExpression() const noexcept {
  double result = 0.0;
  return result;
}

bool s21::Model::TokenIsUnary(const s21::Token& sym) const noexcept {
  bool result = true;
  std::string cmp = "+-cstoiaqlg";
  if (cmp.find(sym.type_) == std::string::npos) result = false;
  return result;
}

bool s21::Model::TokenIsBinary(const s21::Token& sym) const noexcept {
  bool result = true;
  std::string cmp = "pm*/^%";
  if (cmp.find(sym.type_) == std::string::npos) result = false;
  return result;
}

bool s21::Model::TokenIsNumber(const s21::Token& sym) const noexcept {
  bool result = false;
  if (sym.type_ == 'n' || sym.type_ == 'x') result = true;
  return result;
}
