#include "s21_model.h"

// std::vector<s21::Token> s21::PolishNotation::CreateNotation() {
//   std::stack<Token> my_stack;
//   std::vector<Token> copy_input(output_tokens_);
//   output_tokens_.clear();
//   for (auto index = copy_input.cbegin(); index != copy_input.cend(); ++index)
//   {
//     if (index->priority_ == s21::Priority::kZero) {
//       output_tokens_.push_back(*index);
//     } else if (index->priority_ == s21::Priority::kFourth ||
//                index->type_ == "(") {
//       my_stack.push(*index);
//     } else if (index->type_ == ")") {
//       while (my_stack.top().type_ != "(") {
//         output_tokens_.push_back(my_stack.top());
//         my_stack.pop();
//       }
//     } else {
//       if (!my_stack.empty()) {
//         if (my_stack.top().priority_ < index->priority_) {
//           my_stack.push(*index);
//         } else {
//           if (index->type_ == "^") {
//             while (!my_stack.empty() &&
//                    my_stack.top().priority_ > index->priority_ &&
//                    my_stack.top().type_ != "(") {
//               output_tokens_.push_back(my_stack.top());
//               my_stack.pop();
//             }
//           } else {
//             while (!my_stack.empty() &&
//                    my_stack.top().priority_ >= index->priority_ &&
//                    my_stack.top().type_ != "(") {
//               output_tokens_.push_back(my_stack.top());
//               my_stack.pop();
//             }
//           }
//         }
//         my_stack.push(*index);
//       } else {
//         my_stack.push(*index);
//       }
//     }
//   }
//   while (!my_stack.empty()) {
//     output_tokens_.push_back(my_stack.top());
//     my_stack.pop();
//   }
//   return output_tokens_;
// }

std::vector<s21::Token> s21::PolishNotation::CreateNotation() {
  try {
    tokens_.CreateTokenOutput();
  } catch (std::invalid_argument &e) {
    std::cerr << e.what() << std::endl;
  }
  std::stack<Token> my_stack;
  std::vector<Token> copy_input(tokens_.GetTokens());
  for (auto &current_token : copy_input) {
    if (current_token.type_ == "number") {
      output_notation_.push_back(current_token);
    } else if (current_token.priority_ == s21::Priority::kFourth ||
               current_token.type_ == "(") {
      my_stack.push(current_token);
    } else if (current_token.type_ == ")") {
      while (my_stack.top().type_ != "(") {
        output_notation_.push_back(my_stack.top());
        my_stack.pop();
      }
    } else {
    }
  }
  while (!my_stack.empty()) {
    output_notation_.push_back(my_stack.top());
    my_stack.pop();
  }
  return output_notation_;
}
