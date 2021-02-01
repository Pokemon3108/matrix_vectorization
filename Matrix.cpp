
#include <cstdlib>
#include <random>
#include <iostream>
#include <iomanip>
#include "Matrix.h"

Matrix::Matrix(const Matrix & matrix) {
    for (int i=0; i<rows; ++i) {
        for (int j=0; j<cols; ++j) {
            data[i][j]=matrix.getData()[i][j];
        }
    }
}

Matrix::~Matrix() {
    Matrix::clear();
}

float** Matrix::allocate(int rows, int cols) {
    auto data_ = new float*[rows];
    for(int i = 0;i< rows; ++i){
        data_[i] = new float[cols];
        for(int j  = 0; j < cols; ++j)
            data_[i][j] = 0;
    }
    return data_;
}

void Matrix::fill() {
    for (int i=0; i<rows; ++i) {
        for (int j=0; j<cols; ++j) {
            data[i][j]=getRandomFloat(MIN_VALUE, MAX_VALUE);
        }
    }
}

float Matrix::getRandomFloat(float min, float max) {
    return min + (float)(rand()) / ((float)(RAND_MAX/(max - min)));
}

void Matrix::fill(float value) {
    for (int i=0; i<rows; ++i) {
        for (int j=0; j<cols; ++j) {
            data[i][j]=value;
        }
    }
}

void Matrix::clear() {
    for (int i=0; i<rows; ++i) {
        delete [] data[i];
    }
    delete data;
}

void Matrix::print() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << std::setprecision(5) << std::setw(7) << data[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void Matrix::fill(float **matrix) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j]=matrix[i][j];
        }
    }
}


