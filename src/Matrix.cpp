//
// Created by Leone on 16-04-2024.
//
#include "Matrix.h"
#include <cstdlib>

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
    return mat[m*x+y];
}

const double &Matrix::operator[](std::size_t x, std::size_t y) const {
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

std::ostream &operator<(std::ostream &os, const Matrix &mat) {
    for(int i=0;i<mat.n;i++){
        for(int j=0;j<mat.m;j++){
            os<<mat.mat[i*mat.m+j]<<" ";
        }
        os<<std::endl;
    }
    return os;
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
            if(mat[m*i+j]!=matrix[i,j]){
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
                "Can´t multiply matrices: First matrix's number of rows must be equal to second matrix's number of columns"
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
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            this->operator[](i,j)=this->operator[](i,j)+matrix[i,j];
        }
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &matrix) {
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

