#include <gtest/gtest.h>

#include "../model/s21_model.h"

TEST(validation_src_test_correct_first_priority, test_1) {
  std::string src = "56-893-(-4765.5)+34.3245";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_first_priority, test_2) {
  std::string src = ".98+(1892-392+(465-23))-678.4";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_first_priority, test_3) {
  std::string src = "-1000009+2389.321901-(35797365.39-32457.983153)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_first_priority, test_4) {
  std::string src = "1-(+98246-2345.8)-(563478.3+(6248-(-478)))";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_first_priority, test_5) {
  std::string src = "13897200-14000000-(462748.3298+23476.54672)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_first_priority, test_6) {
  std::string src = "75839612.38364+468942.4325+2357955";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_first_priority, test_7) {
  std::string src = "10000000-478.23472-381389-238904.32";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_first_priority, test_8) {
  std::string src = "13897200-14000000-(462748.3298+23476.54672)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_first_priority, test_9) {
  std::string src = "x-0.0001-x-381389";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_first_priority, test_10) {
  std::string src = "x-0.0001+x-890317+x";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_correct_first_priority, test_11) {
  std::string src = "x-0.0001+1.2e-03-890317+x";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, true);
}

TEST(validation_src_test_incorrect_first_priority, test_1) {
  std::string src = "10000000-478.23472-381389+.";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_incorrect_first_priority, test_2) {
  std::string src = "10000000-+-478.23472-381389";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_incorrect_first_priority, test_3) {
  std::string src = "10000000-sgh-478.23472-381389";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_incorrect_first_priority, test_4) {
  std::string src = "x-0.0001+xx-890317+x";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_incorrect_first_priority, test_5) {
  std::string src = "10000000-+478.23472-381389(x)";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}

TEST(validation_src_test_incorrect_first_priority, test_6) {
  std::string src = "100000.00--478.23472-..381389";
  s21::Model m(src);
  EXPECT_EQ(m.ValidationSrc().first, false);
}
