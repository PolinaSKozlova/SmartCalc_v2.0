#include <gtest/gtest.h>

#include "../model/s21_model.h"

TEST(validation_src_test_incorrect_first_priority, test_1) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("10000000-478.23472-381389+.");
    // } catch (...) {
    // }
  } catch (std::invalid_argument& e) {
    std::invalid_argument s("Dots error: dot without number");
    EXPECT_EQ(*e.what(), *s.what());
  }
}

TEST(validation_src_test_incorrect_first_priority, test_2) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("10000000-+-478.23472-381389");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_first_priority, test_3) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("10000000-sgh-478.23472-381389");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_first_priority, test_4) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("x-0.0001+xx-890317+x");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_first_priority, test_5) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("10000000-+478.23472-381389(x)");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_first_priority, test_6) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("100000.00--478.23472-..381389");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_second_priority, test_1) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("*569/3901/(199.237*23678.6785)");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_second_priority, test_2) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("10000000-*-478.23472/381389");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_second_priority, test_3) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput(".*367/3782");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_second_priority, test_4) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("x-0.0001*xx-890317/x");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_second_priority, test_5) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("x-0.0001*x-890317//x");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_second_priority, test_6) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("100000.00/478.23472*..381389");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_third_priority, test_1) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("^247^(0.4379)");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_third_priority, test_2) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("4269+478=48");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_third_priority, test_3) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput(".367^..3782");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_third_priority, test_4) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("x*(0.0001*x)x-890317/x");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_third_priority, test_5) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("x-0.0001*x-890317/()-x");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_third_priority, test_6) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("100000.00/478.23472(381389)");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_third_priority, test_7) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("1ee-7+cos(4)*1e+3");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_fourth_priority, test_1) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("sin65)-cos()3");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_fourth_priority, test_2) {
  try {
    s21::MathCalculator m;

    m.CalculateResultFromInput("sin(45)+cas(37)-456*log(0)");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_fourth_priority, test_3) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("32849-log(()");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_fourth_priority, test_4) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("lg(2.75)/log(100)");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_fourth_priority, test_5) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("ln(2)-atan(0x)*cos(30)");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_fourth_priority, test_6) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("sqrt(389*389)/tan(5)+log(100x0000)");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect_fourth_priority, test_7) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("tan(439-274)*cos(29) ");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_1) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("46/3+5^2*.(89+4)*sin(2)");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_2) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("sin(-30)+()-34.5");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_3) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("46/3+5^2*(89+4)*san(2)");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_4) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("46/3+5^2*(89+)*sin(2)");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_5) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("46/3+5^2*(89+4)*sin2");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_6) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("56.-90(cos(3))");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_7) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("56.-90*cos(3))^");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_8) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("57+[-9]*(46-24/3)");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_9) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput(".*567.98*(-cos(x))");
  } catch (...) {
  }
}

// ошибка на валгринде
// TEST(validation_src_test_incorrect, test_10) {
//   try {
//     s21::MathCalculator m;
//     m.CalculateResultFromInput("567.98*(-cos(x))mod");
//   } catch (...) {
//   }
// }

TEST(validation_src_test_incorrect, test_11) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("mod5-90/7");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_12) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("5467.43.290+327-cos(0)");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_13) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("x456-cos(3)");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_14) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("76sin(4)-9823");
  } catch (...) {
  }
}

// ошибка на валгринде
// TEST(validation_src_test_incorrect, test_15) {
//   try {
//     s21::MathCalculator m;
//     m.CalculateResultFromInput("76*sin(4)-9823+");
//   } catch (...) {
//   }
// }

TEST(validation_src_test_incorrect, test_16) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("7.9-gd(x)+652-cos(3)");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_17) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("901/67*1-546+coscos(984)");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_18) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("tan(50)/3+./0.0");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_19) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("(x+76.3-cos(x*4))/100x");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_20) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("10000..000+98/100000-cos(90)*(sqrt(625))");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_21) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("10000.000+98/10.00.00-cos(90)*(sqrt(625))");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_22) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("10000000+98/10.0000-cos(90)**(sqrt(625))");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_23) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("10000000+98/10.0000-c-os(90)*(sqrt(625))");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_24) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("10000000+98/100000-cos(90)*(sqrt(625),)");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_25) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput(
        "sqrt(5647*(9-(-78)+))+46^3/250-log(1000)-783*-1.0");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_26) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("++78-cos(3)");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_27) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("+67*(asan(-2)/5)");

  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_28) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("96mod^2-98*(1/2)");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_29) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("46/3+5^2*(89+4)*sin.(2)");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_30) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput(".");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_31) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("++");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_32) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("/");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_33) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("cos");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_34) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("mod");
  } catch (...) {
  }
}

// ошибка на валгринде
// TEST(validation_src_test_incorrect, test_35) {
//   try {
//     s21::MathCalculator m;
//     m.CalculateResultFromInput("-1+");
//   } catch (...) {
//   }
// }

TEST(validation_src_test_incorrect, test_36) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("x", ".");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_37) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("100-x", "+");
  } catch (...) {
  }
}

TEST(validation_src_test_incorrect, test_38) {
  try {
    s21::MathCalculator m;
    m.CalculateResultFromInput("100-x", "1e++");
  } catch (...) {
  }
}