//
// Created by Leone on 17-04-2024.
//
#include "../src/Matrix.cpp"
#include "gtest/gtest.h"
#include <cstdlib>

TEST(MatrixCreate, MT){
  Matrix mat;
  std::tuple<int, int> nm(0,0);
  ASSERT_EQ(nm,mat.size());
}

TEST(MatrixCreate, N){
  Matrix mat(5);
  std::tuple<int, int> nm(1,5);
  ASSERT_EQ(nm,mat.size());
}

TEST(MatrixCreate, NM) {
  Matrix mat (3,2);
  Matrix mat2 (3,2);
  ASSERT_EQ(mat,mat2);
}

TEST(MatrixCreate, FileSaveAndFileCopy){
  Matrix Example(2,3);
  Example[0,0]=1;
  Example[0,1]=3;
  Example[0,2]=5;
  Example[1,0]=2;
  Example[1,1]=4;
  Example[1,2]=6;
  Example.save_to_file("ExMatrix.txt");

  Matrix mat("ExMatrix.txt");

  ASSERT_EQ(mat,Example);
}

TEST(MatrixCreate, CopyMatrix){
  Matrix mat1(5,5);
  mat1[2,2]=5;
  Matrix mat2(mat1);
  ASSERT_EQ(mat1,mat2);
}

TEST(MatrixSetGet, SetGet){
  Matrix mat(3,3);
  mat[1,1] = 1;
  double c = mat[1,1];
  ASSERT_EQ(c,1);
}

TEST(MatrixSetGet, ExeptionSet){
  Matrix mat(2,2);
  
  ASSERT_THROW({
    try{
      mat.operator[](2,2)= 22;
    }
    catch(const std::invalid_argument& e){
      throw e;
    } 
  }, std::invalid_argument);
}

TEST(MatrixSetGet, ExeptionGet){
  Matrix mat(2,2);
  
  ASSERT_THROW({
    try{
      double c = mat.operator[](2,2);
    }
    catch(const std::invalid_argument& e){
      throw e;
    } 
  }, std::invalid_argument);
}

TEST(MatrixSetGet, Fill){
  Matrix mat(9,9);
  mat.fill(9);
  double tmp=0;
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      tmp=mat[i,j];
      ASSERT_EQ(tmp,9);
    }
  }
}

TEST(MatrixDim, Size){
  int n,m;
  n=8;
  m=5;
  Matrix mat(n,m);
  ASSERT_EQ(n,std::get<0>(mat.size()));
  ASSERT_EQ(m,std::get<1>(mat.size()));
}

TEST(MatrixDim, Length){
  int n,m;
  n=8;
  m=5;
  Matrix mat(n,m);
  ASSERT_EQ(n,mat.length());
}

TEST(MatrixVal, Max){
  Matrix mat(4,4);
  mat[2,2]=2;
  mat[3,3]=4;
  mat[2,3]=3;
  ASSERT_EQ(4,mat.max());
}

TEST(MatrixVal, Min){
  Matrix mat(4,4);
  mat[2,2]=2;
  mat[3,3]=4;
  mat[2,3]=3;
  ASSERT_EQ(0,mat.min());
}

TEST(MatrixBool, Equal){
  Matrix mat(2,2);
  mat[0,0]=1;
  mat[1,1]=2;

  Matrix mat2(2,2);
  mat2[0,0]=1;
  mat2[1,1]=2;
  
  ASSERT_TRUE(mat==mat2);
}

TEST(MatrixBool, Diff){
  Matrix mat(2,2);
  mat[0,0]=1;
  mat[1,1]=2;

  Matrix mat2(2,2);
  mat2[0,0]=2;
  mat2[1,1]=1;
  
  ASSERT_TRUE(mat!=mat2);
}

TEST(MatrixMath, assign){
  Matrix mat0(3,3);
  mat0[0,0]=1;
  mat0[1,1]=2;
  mat0[2,2]=3;
  Matrix mat1(2,2);
  mat1=mat0;
  ASSERT_EQ(mat0,mat1);
}

TEST(MatrixMath, MultMatrix){
  Matrix mat0(2,3);
  mat0[0,0]=1;
  mat0[0,1]=2;
  mat0[0,2]=3;
  mat0[1,0]=4;
  mat0[1,1]=5;
  mat0[1,2]=6;
  Matrix mat1(3,2);
  mat1[0,0]=1;
  mat1[0,1]=2;
  mat1[1,0]=3;
  mat1[1,1]=4;
  mat1[2,0]=5;
  mat1[2,1]=6;
  mat0*=mat1;
  Matrix res(2,2);
  res[0,0]=22;
  res[0,1]=28;
  res[1,0]=49;
  res[1,1]=64;
  ASSERT_EQ(mat0,res);
}

TEST(MatrixMath, ExeptionMultMatrix){
  Matrix mat0(2,1);
  Matrix mat1(2,2);  
  ASSERT_THROW({
    try{
      mat0*=mat1;
    }
    catch(const std::invalid_argument& e){
      throw e;
    }
  },std::invalid_argument);
}

TEST(MatrixMath, MultConstant){
  Matrix mat(2,2);
  mat.fill(1);
  mat*=5;
  double tmp;
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      tmp=mat[i,j];
      ASSERT_EQ(tmp,5);
    }
  }
}

TEST(MatrixMath, SumV1){
  Matrix mat(2,2);
  mat.fill(3);
  Matrix mat1(2,2);
  mat1[1,1]=2;
  mat+=mat1;
  double res=mat[1,1];
  ASSERT_EQ(res,5);
}

TEST(MatrixMath, SumV2){
  Matrix mat(2,2);
  mat.fill(3);
  Matrix mat1(2,2);
  mat1.fill(2);
  mat+=mat1;
  double tmp;
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      tmp=mat[i,j];
      ASSERT_EQ(tmp,5);
    }
  }  
}  

TEST(MatrixMath, ExeptionSum){
  Matrix mat(2,2);
  mat.fill(2);
  Matrix mat1(3,3);
  mat.fill(3);
  ASSERT_THROW({
    try{
      mat+=mat1;
    }
    catch(const std::invalid_argument& e){
      throw e;
    }
  },std::invalid_argument);
}

TEST(MatrixMath, SubV1){
  Matrix mat(2,2);
  mat.fill(3);
  Matrix mat1(2,2);
  mat1[1,1]=2;
  mat-=mat1;
  double res=mat[1,1];
  ASSERT_EQ(res,1);
}

TEST(MatrixMath, SubV2){
  Matrix mat(2,2);
  mat.fill(3);
  Matrix mat1(2,2);
  mat1.fill(2);
  mat-=mat1;
  double tmp;
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      tmp=mat[i,j];
      ASSERT_EQ(tmp,1);
    }
  }  
}

TEST(MatrixMath, ExeptionSub){
  Matrix mat(2,2);
  mat.fill(2);
  Matrix mat1(3,3);
  mat.fill(3);
  ASSERT_THROW({
    try{
      mat-=mat1;
    }
    catch(const std::invalid_argument& e){
      throw e;
    }
  },std::invalid_argument);
}

TEST(MatrixMath, Transpose){
  Matrix mat0(2,3);
  mat0[0,0]=1;
  mat0[0,1]=2;
  mat0[0,2]=3;
  mat0[1,0]=4;
  mat0[1,1]=5;
  mat0[1,2]=6;
  mat0.transpose();
  Matrix mat1(3,2);
  mat1[0,0]=1;
  mat1[0,1]=4;
  mat1[1,0]=2;
  mat1[1,1]=5;
  mat1[2,0]=3;
  mat1[2,1]=6;
  ASSERT_EQ(mat0,mat1);
}