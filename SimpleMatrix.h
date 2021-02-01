
#ifndef MATRIX_VECTORIZATION_SIMPLEMATRIX_H
#define MATRIX_VECTORIZATION_SIMPLEMATRIX_H


#include "Matrix.h"

class SimpleMatrix : public Matrix {

public:
    SimpleMatrix(int rows, int cols) : Matrix(rows, cols) {}


//    void add(Matrix &matrix) override;

    void multiply(Matrix &matrix) override;

};


#endif //MATRIX_VECTORIZATION_SIMPLEMATRIX_H
