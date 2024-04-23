//
// Created by Leone on 17-04-2024.
//
#include "../src/Matrix.cpp"
#include "gtest/gtest.h"

TEST(CPPLib, MatrixCreate) {
  Matrix mat (3,2);
  Matrix mat2 (3,2);
  ASSERT_EQ(mat,mat2);
}

TEST(CPPlib, MatrixFileCreate){
  Matrix mat("ExMatrix.txt");
  Matrix Example(2,3);
  Example[0,0]=1;
  Example[0,1]=3;
  Example[0,2]=5;
  Example[1,0]=2;
  Example[1,1]=4;
  Example[1,2]=6;

  ASSERT_EQ(mat,Example);
}

TEST(CPPLib, MatrixSaveToFile){
  Matrix mat(4,4);
  mat.fill(9);
  mat[0,3]=0.3;
  mat[1,2]=1.2;
  mat[2,1]=2.1;
  mat[3,0]=3.0;
  mat.save_to_file("Matrix4x4.txt");
  Matrix mat2("Matrix4x4.txt");
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
