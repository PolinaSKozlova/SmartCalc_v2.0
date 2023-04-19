#include "s21_extra_classes.h"
#include "s21_model.h"

void s21::Tokenizer::CreateTokenOutput() {
  try {
    CheckHooksInInput();
    CheckDotsInInput();
    CheckXValue();
    CreateTokens();
    FindUnarySign();
    CheckHooksAfterFunctions();
    print();
  } catch (std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
  }
}

void s21::Tokenizer::CreateTokens() {
  auto current = input_src_.cbegin();
  while (current != input_src_.cend()) {
    if (std::isdigit(*current) || *current == '.') {
      size_t shift = 0;
      tokens_.emplace_back(std::stod(&(*current), &shift), s21::Priority::kZero,
                           "number");
      current += shift;
    } else if (std::isalpha(*current)) {
      std::regex base_regex("([a-z]+)");
      std::sregex_iterator regex_it =
          std::sregex_iterator(current, input_src_.cend(), base_regex);
      std::smatch base_match = *regex_it;
      FillRecievedToken(base_match.str());
      current += base_match.length();
    } else {
      const std::string tmp{*current++};
      FillRecievedToken(tmp);
    }
  }
}

void s21::Tokenizer::CheckHooksInInput() const {
  int count_hooks = 0;
  for (auto current_sym = input_src_.cbegin(); current_sym != input_src_.cend();
       ++current_sym) {
    if (*current_sym == '(') ++count_hooks;
    if (*current_sym == ')') --count_hooks;
    if (*current_sym == '(' && *(current_sym + 1) == ')') {
      throw std::invalid_argument("Empty hooks");
      break;
    }
  }
  if (count_hooks) throw std::invalid_argument("Hooks error");
}

void s21::Tokenizer::CheckDotsInInput() const {
  for (auto current_sym = ++input_src_.cbegin();
       current_sym != input_src_.cend(); ++current_sym) {
    if (*current_sym == '.' && *(current_sym - 1) == '.')
      throw std::invalid_argument("Dots error: two dots in input");
    if (*current_sym == '.' && !std::isdigit(*(current_sym - 1)) &&
        !std::isdigit(*(current_sym + 1))) {
      throw std::invalid_argument("Dots error: dot without number");
    }
  }
}

void s21::Tokenizer::FillRecievedToken(const std::string& key) {
  auto search_token = valid_tokens.find(key);
  if (search_token == valid_tokens.cend())
    throw std::invalid_argument("Invalid token");
  tokens_.emplace_back(search_token->second);
  if (key == "x") {
    tokens_.back().value_ = std::stod(token_x_value_, nullptr);
  }
}

void s21::Tokenizer::FindUnarySign() noexcept {
  if (tokens_.front().priority_ == s21::Priority::kFirst) {
    tokens_.front().priority_ = s21::Priority::kThird;
    if (tokens_.front().type_ == "sum") tokens_.front().type_ = "u_plus";
    if (tokens_.front().type_ == "sub") tokens_.front().type_ = "u_minus";
  }
  for (auto current = tokens_.begin(); current != tokens_.end(); ++current) {
    if ((current->priority_ == s21::Priority::kFirst ||
         current->priority_ == s21::Priority::kSecond ||
         current->priority_ == s21::Priority::kFourth ||
         current->type_ == "(" || current->type_ == "^") &&
        (current + 1)->priority_ == s21::Priority::kFirst) {
      (current + 1)->priority_ = s21::Priority::kThird;
      if ((current + 1)->type_ == "sum") (current + 1)->type_ = "u_plus";
      if ((current + 1)->type_ == "sub") (current + 1)->type_ = "u_minus";
    }
  }
}

void s21::Tokenizer::CheckHooksAfterFunctions() const {
  for (auto current = tokens_.cbegin(); current != tokens_.cend(); ++current) {
    if (current->priority_ == s21::Priority::kFourth &&
        (current + 1)->type_ != "(")
      throw std::invalid_argument("Function without hooks");
  }
}

void s21::Tokenizer::CheckXValue() const {
  for (auto iterator_to_num = token_x_value_.cbegin();
       iterator_to_num != token_x_value_.cend(); ++iterator_to_num) {
    if ((!std::isdigit(*iterator_to_num) && *iterator_to_num != '.') ||
        (*iterator_to_num == '.' && *(iterator_to_num + 1) == '.') ||
        (*iterator_to_num == '.' && token_x_value_.length() == 1)) {
      throw std::invalid_argument("Incorrect x value");
    }
  }
}
