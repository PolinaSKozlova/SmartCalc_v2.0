#include "s21_model.h"

void s21::Model::ClearStack() {
  while (input_.size()) {
    input_.pop();
  }
}
