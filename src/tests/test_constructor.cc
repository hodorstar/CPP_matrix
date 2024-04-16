#include "test.h"

TEST(BaseConstructor, test_1) {
  S21Matrix matrix;
  EXPECT_EQ(matrix.GetRows(), 0);
  EXPECT_EQ(matrix.GetCols(), 0);
}

TEST(ParamConstructor, test_1) {
  S21Matrix matrix(2, 3);
  matrix(2, 1) = 555;
  EXPECT_EQ(matrix.GetRows(), 2);
  EXPECT_EQ(matrix.GetCols(), 3);
  EXPECT_EQ(matrix(2, 1), 555);
}

TEST(ParamConstructor, test_2) {
  EXPECT_ANY_THROW(S21Matrix matrix(-2, 3));
  EXPECT_ANY_THROW(S21Matrix matrix_2(2, -3));
}

TEST(CopyConstructor, test_1) {
  S21Matrix first(3, 2);
  first.SetRundomNum();
  S21Matrix second(first);
  EXPECT_EQ(second.EqMatrix(first), true);
}

TEST(CopyConstructor, test_2) {
  S21Matrix first(0, 0);
  S21Matrix second(first);
  EXPECT_EQ(second.EqMatrix(first), true);
}

TEST(MoveConstructor, test_1) {
  S21Matrix first(3, 2);
  first.SetRundomNum();
  S21Matrix expect(first);
  S21Matrix second = std::move(first);
  EXPECT_EQ(second.EqMatrix(expect), true);
}