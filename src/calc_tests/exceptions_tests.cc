#include <gtest/gtest.h>

#include "../model/s21_model.h"

TEST(validation_src_test_incorrect_first_priority, test_1) {
  std::string src = "10000000-478.23472-381389+.";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
  // catch (std::invalid_argument& e) {
  //   EXPECT_EQ(e, "");
  // }
}

TEST(validation_src_test_incorrect_first_priority, test_2) {
  std::string src = "10000000-+-478.23472-381389";
  s21::MathCalculator m(src);
  // try {
  m.CalculateResultFromInput();
  // } catch (...) {
  // }
  ASSERT_ANY_THROW(m.CalculateResultFromInput());
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

TEST(validation_src_test_incorrect, test_1) {
  std::string src = "46/3+5^2*.(89+4)*sin(2)";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_2) {
  std::string src = "sin(-30)+()-34.5";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_3) {
  std::string src = "46/3+5^2*(89+4)*san(2)";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_4) {
  std::string src = "46/3+5^2*(89+)*sin(2)";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_5) {
  std::string src = "46/3+5^2*(89+4)*sin2";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_6) {
  std::string src = "56.-90(cos(3))";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_7) {
  std::string src = "56.-90*cos(3))^";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_8) {
  std::string src = "57+[-9]*(46-24/3)";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_9) {
  std::string src = ".*567.98*(-cos(x))";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_10) {
  std::string src = "567.98*(-cos(x))mod";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_11) {
  std::string src = "mod5-90/7";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_12) {
  std::string src = "5467.43.290+327-cos(0)";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_13) {
  std::string src = "x456-cos(3)";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_14) {
  std::string src = "76sin(4)-9823";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_15) {
  std::string src = "76*sin(4)-9823+";
  s21::MathCalculator m(src);
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}