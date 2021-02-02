#pragma once

#include <memory>
#include "Matrix.h"

class SimpleMatrix : public Matrix {

public:
    SimpleMatrix(int rows, int cols) : Matrix(rows, cols) {}


//    void add(Matrix &matrix) override;

    Matrix* multiply(Matrix &matrix) override;

};


