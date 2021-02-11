#include <stdexcept>
#include "SimpleMatrix.h"

Matrix* SimpleMatrix::operator*(Matrix &matrix) {
    if (cols != matrix.getRows())
        throw std::runtime_error("Can't multiply matrix");

    auto data_ = matrix.getData();

    auto cols_ = matrix.getCols();
    auto resultData = allocate(rows, cols_);

    for (int i = 0; i < rows; ++i) {
        auto resultRow = resultData[i];
        auto row = data[i];
        for(int j = 0; j < cols_; ++j){
            auto val = row[j];
            auto col = data_[j];
            for(int k = 0; k < cols_; ++k){
                resultRow[k] += val * col[k];
            }
        }
    }

    SimpleMatrix* result=new SimpleMatrix(rows, cols_);
    (*result).fill(resultData);

    return result;

}

Matrix *SimpleMatrix::operator+(Matrix &matrix) {
    auto resultData = allocate(this->rows, this->cols);
    auto data1 = matrix.getData();
    auto data2=data;
    for (int i=0; i<this->rows; ++i) {
        auto row1=data1[i];
        auto row2=data2[i];
        for (int j=0; j< this->cols; ++j) {
            resultData[i][j]=row1[j]+row2[j];
        }
    }

    SimpleMatrix* result=new SimpleMatrix(this->rows, this->cols);
    (*result).fill(resultData);

    return result;
}


