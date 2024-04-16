#include "test.h"

TEST(Accessor, test_1) {
  S21Matrix first(5, 8);
  EXPECT_NEAR(first.GetRows(), 5, 1e-7);
  EXPECT_NEAR(first.GetCols(), 8, 1e-7);
}

TEST(Mutator, test_1) {
  S21Matrix first(5, 8);
  first.SetAnyNum(10);
  first.SetRows(3);
  first.SetCols(2);
  S21Matrix expect(3, 2);
  expect.SetAnyNum(10);
  EXPECT_EQ(expect.EqMatrix(first), true);
}

TEST(Mutator, test_2) {
  S21Matrix first(2, 1);
  first.SetAnyNum(10);
  first.SetRows(3);
  first.SetCols(2);
  S21Matrix expect(3, 2);
  expect.SetAnyNum(10);
  expect(1, 2) = 0;
  expect(2, 2) = 0;
  expect(3, 1) = 0;
  expect(3, 2) = 0;
  EXPECT_EQ(expect.EqMatrix(first), true);
}

TEST(Mutator, test_3) {
  S21Matrix first(2, 1);
  first.SetAnyNum(10);
  EXPECT_ANY_THROW(first.SetRows(-3));
  EXPECT_ANY_THROW(first.SetCols(-2));
}
