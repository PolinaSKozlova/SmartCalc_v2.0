#include <gtest/gtest.h>

#include "../model/s21_model.h"

TEST(validation_src_test_incorrect_first_priority, test_1) {
  std::string src = "10000000-478.23472-381389+.";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_first_priority, test_2) {
  std::string src = "10000000-+-478.23472-381389";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_first_priority, test_3) {
  std::string src = "10000000-sgh-478.23472-381389";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_first_priority, test_4) {
  std::string src = "x-0.0001+xx-890317+x";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_first_priority, test_5) {
  std::string src = "10000000-+478.23472-381389(x)";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_first_priority, test_6) {
  std::string src = "100000.00--478.23472-..381389";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_second_priority, test_1) {
  std::string src = "*569/3901/(199.237*23678.6785)";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_second_priority, test_2) {
  std::string src = "10000000-*-478.23472/381389";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_second_priority, test_3) {
  std::string src = ".*367/3782";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_second_priority, test_4) {
  std::string src = "x-0.0001*xx-890317/x";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_second_priority, test_5) {
  std::string src = "x-0.0001*x-890317//x";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_second_priority, test_6) {
  std::string src = "100000.00/478.23472*..381389";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_third_priority, test_1) {
  std::string src = "^247^(0.4379)";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_third_priority, test_2) {
  std::string src = "4269+478=48";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_third_priority, test_3) {
  std::string src = ".367^..3782";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_third_priority, test_4) {
  std::string src = "x*(0.0001*x)x-890317/x";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_third_priority, test_5) {
  std::string src = "x-0.0001*x-890317/()-x";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_third_priority, test_6) {
  std::string src = "100000.00/478.23472(381389)";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_third_priority, test_7) {
  std::string src = "1ee-7+cos(4)*1e+3";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_fourth_priority, test_1) {
  std::string src = "sin65)-cos()3";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_fourth_priority, test_2) {
  std::string src = "sin(45)+cas(37)-456*log(0)";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_fourth_priority, test_3) {
  std::string src = "32849-log(()";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_fourth_priority, test_4) {
  std::string src = "lg(2.75)/log(100)";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_fourth_priority, test_5) {
  std::string src = "ln(2)-atan(0x)*cos(30)";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_fourth_priority, test_6) {
  std::string src = "sqrt(389*389)/tan(5)+log(100x0000)";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_fourth_priority, test_7) {
  std::string src = "tan(439-274)*cos(29) ";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}
