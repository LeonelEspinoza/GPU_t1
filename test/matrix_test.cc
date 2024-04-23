//
// Created by Leone on 17-04-2024.
//
#include "../src/Matrix.cpp"
#include "gtest/gtest.h"

TEST(MatrixTest, MatrixCreateNM) {
  Matrix mat (3,2);
  Matrix mat2 (3,2);
  ASSERT_EQ(mat,mat2);
}

TEST(MatrixTest, MatrixFileCreate){
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

TEST(MatrixTest, MatrixSaveToFile){
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

TEST(MatrixTest, MatrixSetGetValue){
  Matrix mat(3,3);
  mat[1,1] = 1;
  double c = mat[1,1];
  ASSERT_EQ(c,1);
}

TEST(MatrixTest, MatrixExptSetValue){
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

TEST(MatrixTest, MatrixExptGETValue){
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

TEST(MatrixTest, MatrixFill){
  Matrix mat(9,9);
  mat.fill(9);
  std::tuple<int,int> nm = mat.size();
  int n = std::get<0>(nm);
  int m = std::get<1>(nm);
  double tmp=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      tmp=mat[i,j];
      ASSERT_EQ(tmp,9);
    }
  }
}