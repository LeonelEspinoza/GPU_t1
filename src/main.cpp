#include <iostream>
#include "src/Matrix.h"

int main(int argc, char* argv[]){
    Matrix mat(2,3);
    mat[0,0]=1;
    mat[0,1]=2;
    mat[0,2]=3;
    mat[1,0]=4;
    mat[1,1]=5;
    mat[1,2]=6;
    std::cout<mat;
    Matrix mat2(3,2);
    mat2[0,0]=1;
    mat2[0,1]=2;
    mat2[1,0]=3;
    mat2[1,1]=4;
    mat2[2,0]=5;
    mat2[2,1]=6;
    std::cout<<"---"<<std::endl;
    std::cout<mat2;
    mat*=mat2;
    std::cout<<"---"<<std::endl;
    std::cout<mat;
    mat2.transpose();
    std::cout<<"---"<<std::endl;
    std::cout<mat2;
}