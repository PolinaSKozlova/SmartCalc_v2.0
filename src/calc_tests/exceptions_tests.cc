#include <gtest/gtest.h>

#include "../model/s21_model.h"

TEST(validation_src_test_incorrect_first_priority, test_1) {
  s21::MathCalculator m("10000000-478.23472-381389+.");
  try {
    m.CalculateResultFromInput();
    // } catch (...) {
    // }
  } catch (std::invalid_argument& e) {
    std::invalid_argument s("Dots error: dot without number");
    EXPECT_EQ(*e.what(), *s.what());
  }
}

TEST(validation_src_test_incorrect_first_priority, test_2) {
  s21::MathCalculator m("10000000-+-478.23472-381389");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_first_priority, test_3) {
  s21::MathCalculator m("10000000-sgh-478.23472-381389");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_first_priority, test_4) {
  s21::MathCalculator m("x-0.0001+xx-890317+x");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_first_priority, test_5) {
  s21::MathCalculator m("10000000-+478.23472-381389(x)");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_first_priority, test_6) {
  s21::MathCalculator m("100000.00--478.23472-..381389");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_second_priority, test_1) {
  s21::MathCalculator m("*569/3901/(199.237*23678.6785)");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_second_priority, test_2) {
  s21::MathCalculator m("10000000-*-478.23472/381389");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_second_priority, test_3) {
  s21::MathCalculator m(".*367/3782");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_second_priority, test_4) {
  s21::MathCalculator m("x-0.0001*xx-890317/x");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_second_priority, test_5) {
  s21::MathCalculator m("x-0.0001*x-890317//x");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_second_priority, test_6) {
  s21::MathCalculator m("100000.00/478.23472*..381389");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_third_priority, test_1) {
  s21::MathCalculator m("^247^(0.4379)");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_third_priority, test_2) {
  s21::MathCalculator m("4269+478=48");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_third_priority, test_3) {
  s21::MathCalculator m(".367^..3782");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_third_priority, test_4) {
  s21::MathCalculator m("x*(0.0001*x)x-890317/x");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_third_priority, test_5) {
  s21::MathCalculator m("x-0.0001*x-890317/()-x");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_third_priority, test_6) {
  s21::MathCalculator m("100000.00/478.23472(381389)");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_third_priority, test_7) {
  s21::MathCalculator m("1ee-7+cos(4)*1e+3");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_fourth_priority, test_1) {
  s21::MathCalculator m("sin65)-cos()3");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_fourth_priority, test_2) {
  s21::MathCalculator m("sin(45)+cas(37)-456*log(0)");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_fourth_priority, test_3) {
  s21::MathCalculator m("32849-log(()");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_fourth_priority, test_4) {
  s21::MathCalculator m("lg(2.75)/log(100)");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_fourth_priority, test_5) {
  s21::MathCalculator m("ln(2)-atan(0x)*cos(30)");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_fourth_priority, test_6) {
  s21::MathCalculator m("sqrt(389*389)/tan(5)+log(100x0000)");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_fourth_priority, test_7) {
  s21::MathCalculator m("tan(439-274)*cos(29) ");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_1) {
  s21::MathCalculator m("46/3+5^2*.(89+4)*sin(2)");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_2) {
  s21::MathCalculator m("sin(-30)+()-34.5");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_3) {
  s21::MathCalculator m("46/3+5^2*(89+4)*san(2)");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_4) {
  s21::MathCalculator m("46/3+5^2*(89+)*sin(2)");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_5) {
  s21::MathCalculator m("46/3+5^2*(89+4)*sin2");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_6) {
  s21::MathCalculator m("56.-90(cos(3))");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_7) {
  s21::MathCalculator m("56.-90*cos(3))^");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_8) {
  s21::MathCalculator m("57+[-9]*(46-24/3)");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_9) {
  s21::MathCalculator m(".*567.98*(-cos(x))");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

// TEST(validation_src_test_incorrect, test_10) {
//   s21::MathCalculator m("567.98*(-cos(x))mod", "0");
//   try {
//     m.CalculateResultFromInput();
//   } catch (...) {
//   }
// }

TEST(validation_src_test_incorrect, test_11) {
  s21::MathCalculator m("mod5-90/7");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_12) {
  s21::MathCalculator m("5467.43.290+327-cos(0)");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_13) {
  s21::MathCalculator m("x456-cos(3)");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_14) {
  s21::MathCalculator m("76sin(4)-9823");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

// TEST(validation_src_test_incorrect, test_15) {
//   s21::MathCalculator m("76*sin(4)-9823+");
//   try {
//     m.CalculateResultFromInput();
//   } catch (...) {
//   }
// }

TEST(validation_src_test_incorrect, test_16) {
  s21::MathCalculator m("7.9-gd(x)+652-cos(3)");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_17) {
  s21::MathCalculator m("901/67*1-546+coscos(984)");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_18) {
  s21::MathCalculator m("tan(50)/3+./0.0");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_19) {
  s21::MathCalculator m("(x+76.3-cos(x*4))/100x");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_20) {
  s21::MathCalculator m("10000..000+98/100000-cos(90)*(sqrt(625))");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_21) {
  s21::MathCalculator m("10000.000+98/10.00.00-cos(90)*(sqrt(625))");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_22) {
  s21::MathCalculator m("10000000+98/10.0000-cos(90)**(sqrt(625))");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_23) {
  s21::MathCalculator m("10000000+98/10.0000-c-os(90)*(sqrt(625))");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_24) {
  s21::MathCalculator m("10000000+98/100000-cos(90)*(sqrt(625),)");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_25) {
  s21::MathCalculator m("sqrt(5647*(9-(-78)+))+46^3/250-log(1000)-783*-1.0");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_26) {
  s21::MathCalculator m("++78-cos(3)");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_27) {
  s21::MathCalculator m("+67*(asan(-2)/5)");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_28) {
  s21::MathCalculator m("96mod^2-98*(1/2)");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_29) {
  s21::MathCalculator m("46/3+5^2*(89+4)*sin.(2)");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_30) {
  s21::MathCalculator m(".");
  try {
    m.CalculateResultFromInput();
  } catch (...) {
  }
}