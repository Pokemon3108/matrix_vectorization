#ifndef MATRIX_VECTORIZATION_MATRIX_H
#define MATRIX_VECTORIZATION_MATRIX_H

#include <vector>

class Matrix {
protected:
    float **data;
    int rows;
    int cols;

    const float MIN_VALUE = 0.;
    const float MAX_VALUE = 100.;

public:
    Matrix(int rows_, int cols_) : rows(rows_), cols(cols_) {
        data = allocate(rows, cols);
        fill();
    }

    Matrix(const Matrix &);

    ~Matrix();

//    virtual void add(Matrix &matrix) = 0;

    virtual void multiply(Matrix &matrix) = 0;

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

protected:
    void clear();

    void fill();

    void fill(float value);

    float** allocate(int rows, int columns);

    static float getRandomFloat(float min, float max) ;

private:
    Matrix(){};
};


#endif //MATRIX_VECTORIZATION_MATRIX_H
