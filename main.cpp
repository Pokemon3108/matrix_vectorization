#include <iostream>
#include "Matrix.h"
#include "SimpleMatrix.h"

int main() {
    SimpleMatrix matrix1(18, 8);
    SimpleMatrix matrix2(8, 4);
    matrix1.print();
    matrix2.print();
    matrix1.multiply(matrix2);
    matrix1.print();
}
