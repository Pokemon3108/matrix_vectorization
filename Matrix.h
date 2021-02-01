//
// Created by Neonl on 02/01/21.
//

#ifndef MATRIX_VECTORIZATION_MATRIX_H
#define MATRIX_VECTORIZATION_MATRIX_H

#include <vector>

class Matrix {
protected:
    int** data;
    int rows;
    int cols;

public:
    Matrix(int rows_, int cols_):rows(rows_), cols(cols_){}
    Matrix(const Matrix&);
    ~Matrix();

    bool operator==(const Matrix &rhs) const {
        return data == rhs.data &&
               rows == rhs.rows &&
               cols == rhs.cols;
    }

    bool operator!=(const Matrix &rhs) const {
        return !(rhs == *this);
    }

    int **getData() const {
        return data;
    }

    int getRows() const {
        return rows;
    }

    void setRows(int rows) {
        Matrix::rows = rows;
    }

    int getCols() const {
        return cols;
    }

    void setCols(int cols) {
        Matrix::cols = cols;
    }

protected:
    static void free(double **space, int rows, int columns);
    static void fill(double **space, int rows, int columns);
    static void fill(double **space, int rows, int columns, double value);
    static double** allocate(int rows, int columns);
    static double getRandomDouble(int min, int max);

private:
    Matrix();
};


#endif //MATRIX_VECTORIZATION_MATRIX_H
