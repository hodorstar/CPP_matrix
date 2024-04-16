#include "test.h"

TEST(EqMatrix, test1) {
  S21Matrix first(3, 3);
  first.SetAnyNum(2);
  S21Matrix second(3, 3);
  second.SetAnyNum(2);
  EXPECT_EQ(first.EqMatrix(second), true);
}

TEST(EqMatrix, test2) {
  S21Matrix first(3, 3);
  first.SetAnyNum(1);

  S21Matrix second(3, 3);
  second.SetAnyNum(2);

  EXPECT_EQ(first.EqMatrix(second), false);
}

TEST(SumFunction, test_1) {
  S21Matrix first(3, 3);
  first.SetAnyNum(1);
  S21Matrix second(3, 3);
  second.SetAnyNum(2);
  first.SumMatrix(second);
  for (int i = 1; i <= first.GetRows(); i++) {
    for (int j = 1; j <= first.GetCols(); j++) {
      EXPECT_NEAR(first(i, j), 3, 1e-7);
    }
  }
}

TEST(SumFunction, test_2) {
  S21Matrix first(3, 3);
  first.SetAnyNum(1);
  S21Matrix second(2, 2);
  second.SetAnyNum(1);

  EXPECT_ANY_THROW(first.SumMatrix(second));
}

TEST(SubFunction, test_1) {
  S21Matrix first(3, 3);
  first.SetAnyNum(1);
  S21Matrix second(3, 3);
  second.SetAnyNum(2);
  first.SubMatrix(second);
  for (int i = 1; i <= first.GetRows(); i++) {
    for (int j = 1; j <= first.GetCols(); j++) {
      EXPECT_NEAR(first(i, j), -1, 1e-7);
    }
  }
}

TEST(SubFunction, test_2) {
  S21Matrix first(3, 3);
  S21Matrix second(2, 2);
  EXPECT_ANY_THROW(first.SubMatrix(second));
}

TEST(MulNumber, test_1) {
  S21Matrix first(3, 3);
  double value = 2;
  first.SetAnyNum(7);
  first.MulNumber(value);
  for (int i = 1; i <= first.GetRows(); i++) {
    for (int j = 1; j <= first.GetCols(); j++) {
      EXPECT_NEAR(first(i, j), 14, 1e-7);
    }
  }
}

TEST(MulMatrix, test_1) {
  S21Matrix first(2, 3);
  first.SetAnyNum(2);
  S21Matrix second(3, 2);
  second.SetAnyNum(4);
  first.MulMatrix(second);
  S21Matrix expect(2, 2);
  expect.SetAnyNum(24);
  EXPECT_EQ(first.EqMatrix(expect), true);
}

TEST(MulMatrix, test_3) {
  S21Matrix first(3, 3);
  first.SetAnyNum(6);
  S21Matrix second(3, 3);
  second.SetAnyNum(3);
  S21Matrix expect(3, 3);
  expect.SetAnyNum(486);
  first.MulMatrix(second);
  first.MulMatrix(second);
  EXPECT_EQ(expect.EqMatrix(first), true);
}

TEST(MulMatrix, test_2) {
  S21Matrix first(2, 3);
  S21Matrix second(5, 2);
  EXPECT_ANY_THROW(first.MulMatrix(second));
}

TEST(Transpose, test_1) {
  S21Matrix first(2, 3);
  S21Matrix expect(3, 2);
  S21Matrix got(3, 2);
  first(1, 1) = 1;
  first(1, 2) = 2;
  first(1, 3) = 3;
  first(2, 1) = 9;
  first(2, 2) = 7;
  first(2, 3) = 5;

  expect(1, 1) = 1;
  expect(1, 2) = 9;
  expect(2, 1) = 2;
  expect(2, 2) = 7;
  expect(3, 1) = 3;
  expect(3, 2) = 5;

  got = first.Transpose();

  EXPECT_EQ(got.EqMatrix(expect), true);
}

TEST(Determinant, test_1) {
  S21Matrix matrix(2, 3);
  EXPECT_ANY_THROW(matrix.Determinant());
}

TEST(Determinant, test_2) {
  S21Matrix matrix(0, 0);
  double value = matrix.Determinant();
  EXPECT_NEAR(value, 0, 1e-7);
}

TEST(Determinant, test_3) {
  S21Matrix matrix(1, 1);
  matrix(1, 1) = 4;
  double value = matrix.Determinant();
  EXPECT_NEAR(value, 4, 1e-7);
}

TEST(Determinant, test_4) {
  S21Matrix matrix(2, 2);
  matrix(1, 1) = 4;
  matrix(1, 2) = -5;
  matrix(2, 1) = 9;
  matrix(2, 2) = 15;
  double value = matrix.Determinant();
  EXPECT_NEAR(value, 105, 1e-7);
}

TEST(Determinant, test_5) {
  S21Matrix matrix(3, 3);
  matrix(1, 1) = 1;
  matrix(1, 2) = -5;
  matrix(1, 3) = 9;
  matrix(2, 1) = 15;
  matrix(2, 2) = 4;
  matrix(2, 3) = 3;
  matrix(3, 1) = 2;
  matrix(3, 2) = 6;
  matrix(3, 3) = 7;
  double value = matrix.Determinant();
  EXPECT_NEAR(value, 1243, 1e-7);
}

TEST(Determinant, test_9) {
  S21Matrix matrix(3, 3);
  matrix(1, 1) = -9;
  matrix(1, 2) = 5;
  matrix(1, 3) = 4;
  matrix(2, 1) = 6;
  matrix(2, 2) = 3;
  matrix(2, 3) = 8;
  matrix(3, 1) = 4;
  matrix(3, 2) = 8;
  matrix(3, 3) = 5;
  double value = matrix.Determinant();
  EXPECT_NEAR(value, 595, 1e-7);
}

TEST(CalcComplements, test_1) {
  S21Matrix matrix(2, 3);
  EXPECT_ANY_THROW(matrix.CalcComplements());
}

TEST(CalcComplements, test_2) {
  S21Matrix matrix(1, 1);
  S21Matrix got(1, 1);
  got = matrix.CalcComplements();
  EXPECT_NEAR(got(1, 1), 1, 1e-7);
}

TEST(CalcComplements, test_3) {
  S21Matrix matrix(3, 3);
  S21Matrix expect(3, 3);
  S21Matrix got(3, 3);
  matrix(1, 1) = 1;
  matrix(1, 2) = 2;
  matrix(1, 3) = 3;
  matrix(2, 1) = 0;
  matrix(2, 2) = 4;
  matrix(2, 3) = 2;
  matrix(3, 1) = 5;
  matrix(3, 2) = 2;
  matrix(3, 3) = 1;

  expect(1, 1) = 0;
  expect(1, 2) = 10;
  expect(1, 3) = -20;
  expect(2, 1) = 4;
  expect(2, 2) = -14;
  expect(2, 3) = 8;
  expect(3, 1) = -8;
  expect(3, 2) = -2;
  expect(3, 3) = 4;

  got = matrix.CalcComplements();

  EXPECT_EQ(got.EqMatrix(expect), true);
}

TEST(InverseMatrix, test_1_1) {
  S21Matrix matrix(0, 0);
  EXPECT_ANY_THROW(matrix.InverseMatrix());
}

TEST(InverseMatrix, test_2) {
  S21Matrix matrix(3, 3);

  matrix(1, 1) = 1;
  matrix(1, 2) = 2;
  matrix(1, 3) = 3;
  matrix(2, 1) = 4;
  matrix(2, 2) = 5;
  matrix(2, 3) = 6;
  matrix(3, 1) = 7;
  matrix(3, 2) = 8;
  matrix(3, 3) = 9;

  EXPECT_ANY_THROW(matrix.InverseMatrix());
}

TEST(InverseMatrix, test_3) {
  S21Matrix matrix(3, 3);
  S21Matrix expect(3, 3);
  S21Matrix got(3, 3);

  matrix(1, 1) = 2;
  matrix(1, 2) = 5;
  matrix(1, 3) = 7;
  matrix(2, 1) = 6;
  matrix(2, 2) = 3;
  matrix(2, 3) = 4;
  matrix(3, 1) = 5;
  matrix(3, 2) = -2;
  matrix(3, 3) = -3;

  expect(1, 1) = 1;
  expect(1, 2) = -1;
  expect(1, 3) = 1;
  expect(2, 1) = -38;
  expect(2, 2) = 41;
  expect(2, 3) = -34;
  expect(3, 1) = 27;
  expect(3, 2) = -29;
  expect(3, 3) = 24;

  got = matrix.InverseMatrix();

  EXPECT_EQ(got.EqMatrix(expect), true);
}

TEST(InverseMatrix, test_4) {
  S21Matrix matrix(3, 3);
  S21Matrix expect(3, 3);
  S21Matrix got(3, 3);

  matrix(1, 1) = 2;
  matrix(1, 2) = 1;
  matrix(1, 3) = 1;
  matrix(2, 1) = 1;
  matrix(2, 2) = 1;
  matrix(2, 3) = 1;
  matrix(3, 1) = 1;
  matrix(3, 2) = 1;
  matrix(3, 3) = 2;

  expect(1, 1) = 1;
  expect(1, 2) = -1;
  expect(1, 3) = 0;
  expect(2, 1) = -1;
  expect(2, 2) = 3;
  expect(2, 3) = -1;
  expect(3, 1) = 0;
  expect(3, 2) = -1;
  expect(3, 3) = 1;

  got = matrix.InverseMatrix();

  EXPECT_EQ(got.EqMatrix(expect), true);
}
