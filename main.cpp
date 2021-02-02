#include <iostream>
#include "Matrix.h"
#include "SimpleMatrix.h"

int main() {

    SimpleMatrix matrix1(5, 10);
    matrix1.fill();
    SimpleMatrix matrix2(10, 6);
    matrix2.fill();
    auto result = reinterpret_cast<SimpleMatrix*> (matrix1.multiply(matrix2));
    (*result).print();
}
