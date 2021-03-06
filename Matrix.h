#pragma once

#include <vector>

class Matrix {
protected:
    float **data{};
    int rows{};
    int cols{};

    const float MIN_VALUE = 0.;
    const float MAX_VALUE = 100.;

public:
    Matrix(int rows_, int cols_) : rows(rows_), cols(cols_) {
        data = allocate(rows, cols);
        fill();
    }


    Matrix(const Matrix &);

    Matrix() = default;

    ~Matrix();


    Matrix operator+(Matrix &matrix1);

    Matrix operator*(Matrix &matrix1);

    Matrix& operator=(const Matrix &matrix);

    void print();

    bool operator==(const Matrix &rhs) const {
        return data == rhs.data &&
               rows == rhs.rows &&
               cols == rhs.cols;
    }

    bool operator!=(const Matrix &rhs) const {
        return !(rhs == *this);
    }

    float **getData() const {
        return data;
    }

    int getRows() const {
        return rows;
    }

    void setRows(int rows_) {
        Matrix::rows = rows_;
    }

    int getCols() const {
        return cols;
    }

    void setCols(int cols_) {
        Matrix::cols = cols_;
    }

    void fill();

    void fill(float value);

protected:
    void clear();

    float **allocate(int rows, int columns);

    float getRandomFloat(float min, float max);

    void fill(float **matrix);

};

