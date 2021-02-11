#pragma once

#include <memory>
#include "Matrix.h"

class SimpleMatrix : public Matrix {

public:
    SimpleMatrix(int rows, int cols) : Matrix(rows, cols) {}

    Matrix* operator + (Matrix& matrix) override;

    Matrix* operator *(Matrix &matrix) override;

};


