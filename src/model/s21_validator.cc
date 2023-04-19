#include "s21_extra_classes.h"
#include "s21_model.h"

std::vector<s21::Token> s21::Validator::CreateNotation() {
  return output_tokens_;
}

// void s21::Validator::CreateNotation() {
//   try {
//   } catch (std::invalid_argument& e) {
//     std::cerr << e.what() << std::endl;
//   }
// }
