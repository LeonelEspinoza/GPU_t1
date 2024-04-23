//
// Created by Leone on 16-04-2024.
//
#include "Matrix.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

Matrix::Matrix() {
    Matrix::n = 0;
    Matrix::m = 0;
    Matrix::mat = std::make_unique<double[]>(0);
}

Matrix::Matrix(int n) {
    Matrix::n = 1;
    Matrix::m = n;
    Matrix::mat = std::make_unique<double[]>(n);
    this->fill(0);
}

Matrix::Matrix(int n, int m) {
    Matrix::n = n;
    Matrix::m = m;
    Matrix::mat = std::make_unique<double[]>(n*m);
    this->fill(0);
}

Matrix::Matrix(const std::string &filename){
    std::ifstream F(filename);
    Matrix::n = 0;
    Matrix::m = 0;
    F >> n >> m;
    Matrix::mat = std::make_unique<double[]>(n*m);
    for (int i = 0; i < n*m; i++){
        F >> mat[i];
    }
    F.close();
}

Matrix::Matrix(const Matrix &matrix) {
    Matrix::n = matrix.n;
    Matrix::m = matrix.m;
    Matrix::mat = std::make_unique<double[]>(n*m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            this->operator[](i,j)=matrix[i,j];
        }
    }
}

double &Matrix::operator[](std::size_t x, std::size_t y) {
    if (n<=x || m<=y){
        throw std::invalid_argument("Index out of range");
    }
    return mat[m*x+y];
}

const double &Matrix::operator[](std::size_t x, std::size_t y) const {
    if (n<=x || m<=y){
        throw std::invalid_argument("Index out of range");
    }
    return mat[m*x+y];
}

void Matrix::fill(double value) {
    for(int i=0;i<n*m;i++){
        mat[i]=value;
    }
}

std::tuple<int, int> Matrix::size() const {
    return std::tuple<int, int>(n,m);
}

int Matrix::length() const {
    return n>m ? n : m;
}

double Matrix::max() const {
    double _max=mat[0];
    for(int i=1;i<n*m;i++){
        if (_max<mat[i]) {
            _max = mat[i];
        }
    }
    return _max;
}

double Matrix::min() const {
    double _min=mat[0];
    for(int i=1;i<n*m;i++){
        if (_min>mat[i]) {
            _min = mat[i];
        }
    }
    return _min;
}

std::ostream &operator<<(std::ostream &os, const Matrix &mat) {
    int n = std::get<0>(mat.size());
    int m = std::get<1>(mat.size());
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            os<<mat[i,j]<<" ";
        }
        os<<std::endl;
    }
    return os;
}

void Matrix::save_to_file(const std::string &filename) const {
    std::ofstream F(filename);
    F << n << " " << m << std::endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j< m; j++){
            F << this->operator[](i,j) << " ";
        }
        F<<std::endl;
    }
    F.close();
    return;
}

bool Matrix::operator==(const Matrix &matrix) const {
    if (matrix.size()!=this->size()){
        return false;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(this->operator[](i,j)!=matrix[i,j]){
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &matrix) const {
    return not (this->operator==(matrix));
}

Matrix &Matrix::operator=(const Matrix &matrix) {
    n=matrix.n;
    m=matrix.m;
    mat = std::make_unique<double[]>(n*m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            this->operator[](i,j)=matrix[i,j];
        }
    }
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &matrix) {
    if(m!=matrix.n){
        throw std::invalid_argument(
                "Can´t multiply matrices: First matrix's number of columns must be equal to second matrix's number of rows"
                );
    }
    Matrix res (n,matrix.m);
    for(int ci=0;ci<res.n;ci++){
        for (int cj = 0; cj < res.m; ++cj) {
            double sum=0;
            for (int k = 0; k < m; ++k) {
                sum+=this->operator[](ci,k)*matrix[k,cj];
            }
            res[ci,cj]=sum;
        }
    }
    n=res.n;
    m=res.m;
    mat=std::move(res.mat);
    return *this;
}

Matrix &Matrix::operator*=(double a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            this->operator[](i,j)=this->operator[](i,j)*a;
        }
    }
    return *this;
}

Matrix &Matrix::operator+=(const Matrix &matrix) {
    if( this->size()!=matrix.size()){
        throw std::invalid_argument(
                "Can´t add matrices: matrices must have same size"
        );
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            this->operator[](i,j)=this->operator[](i,j)+matrix[i,j];
        }
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &matrix) {
    if( this->size()!=matrix.size()){
        throw std::invalid_argument(
                "Can´t subtract matrices: matrices must have same size"
        );
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            this->operator[](i,j)=this->operator[](i,j)-matrix[i,j];
        }
    }
    return *this;
}

Matrix &Matrix::transpose() {
    Matrix tmp (m,n);
    for(int i=0;i<n;i++){
        for (int j = 0; j < m; ++j) {
            tmp[j,i]=this->operator[](i,j);
        }
    }
    n=tmp.n;
    m=tmp.m;
    mat=std::move(tmp.mat);
    return *this;
}


Matrix::~Matrix() = default;