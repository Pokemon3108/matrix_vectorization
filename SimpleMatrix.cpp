#include <stdexcept>
#include "SimpleMatrix.h"

void SimpleMatrix::multiply(Matrix &matrix) {
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

    clear();
    cols = cols_;
    data = resultData;

}


