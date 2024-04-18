//
// Created by Leone on 17-04-2024.
//
#include "..\src\Matrix.cpp"
#include "gtest\gtest.h"

TEST(CPPLib, MatrixCreate) {
    std::cout<<"nihao"<<std::endl;
    Matrix mat (3,2);
    Matrix mat2 (3,2);
    ASSERT_EQ(mat,mat2);

}

/*
#include "gtest/gtest.h"
#include "geom/point.h"
#include "geom/triangle.h"

using Pd = Point<double>;
using Td = Triangle<double>;

TEST(CPPLib, TriangleCreate) {
  Pd p1(-1.0, 0.0);
  Pd p2(1.0, 0.0);
  Pd p3(0.0, 1.0);

  Td t(p1, p2, p3);

  ASSERT_EQ(t[0], p1);
  ASSERT_EQ(t[1], p2);
  ASSERT_EQ(t[2], p3);
}

TEST(CPPLib, TriangleArea) {
  Pd p1(-1.0, 0.0);
  Pd p2(1.0, 0.0);
  Pd p3(0.0, 1.0);

  Td t(p1, p2, p3);

  ASSERT_EQ(t.area(), 1.0);
}
 */
