
#include <cstdlib>
#include <random>
#include <iostream>
#include <iomanip>
#include "Matrix.h"

Matrix::Matrix(const Matrix &matrix) {
    data = new float*[matrix.rows];
    for (int i = 0; i < matrix.rows; ++i) {
        data[i] = new float[matrix.cols];
        for (int j = 0; j < matrix.cols; ++j) {
            data[i][j] = matrix.getData()[i][j];
        }
    }
}

Matrix::~Matrix() {
    Matrix::clear();
}

float **Matrix::allocate(int rows, int cols) {
    auto data_ = new float *[rows];
    for (int i = 0; i < rows; ++i) {
        data_[i] = new float[cols];
        for (int j = 0; j < cols; ++j)
            data_[i][j] = 0;
    }
    return data_;
}

void Matrix::fill() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = getRandomFloat(MIN_VALUE, MAX_VALUE);
            //std::cout<<getRandomFloat(MIN_VALUE, MAX_VALUE)<<std::endl;
        }
    }
}

float Matrix::getRandomFloat(float min, float max) {
    float a = min + (float) (rand()) / ((float) (RAND_MAX / (max - min)));
    return a;
}

void Matrix::fill(float value) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = value;
        }
    }
}

void Matrix::clear() {
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete data;
}

void Matrix::print() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << std::setprecision(8) << std::setw(7) <<data[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void Matrix::fill(float **matrix) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = matrix[i][j];
        }
    }
}

Matrix Matrix::operator*(Matrix &matrix) {
    if (cols != matrix.getRows())
        throw std::runtime_error("Can't multiply matrix");

    auto data_ = matrix.getData();

    auto cols_ = matrix.getCols();
    auto resultData = allocate(rows, cols_);

    for (int i = 0; i < rows; ++i) {
        auto resultRow = resultData[i];
        auto row = data[i];
        for(int j = 0; j < cols; ++j){
            auto val = row[j];
            auto col = data_[j];
            for(int k = 0; k < cols_; ++k){
                resultRow[k] += val * col[k];
            }
        }
    }

    Matrix result(rows, cols_);
    result.fill(resultData);

    return result;

}

Matrix Matrix::operator+(Matrix &matrix1) {
    auto resultData = allocate(this->rows, this->cols);
    auto data1 = matrix1.getData();
    auto data2=data;
    for (int i=0; i<this->rows; ++i) {
        auto row1=data1[i];
        auto row2=data2[i];
        for (int j=0; j< this->cols; ++j) {
            resultData[i][j]=row1[j]+row2[j];
        }
    }

    Matrix result(this->rows, this->cols);
    result.fill(resultData);

    return result;
}

Matrix& Matrix::operator=(const Matrix &matrix) {
    this->cols=matrix.cols;
    this->rows=matrix.rows;
    this->data=allocate(matrix.rows, matrix.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            this->data[i][j] = matrix.getData()[i][j];
        }
    }
    return *this;
}





