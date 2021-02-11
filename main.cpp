#include <iostream>
#include "Matrix.h"

int main() {

//    Matrix matrix1(1, 2);
//    matrix1.fill();
//    Matrix matrix2(2, 3);
//    matrix2.fill();
//    auto result = matrix1 * matrix2;
//    result.print();


    const int M = 5;
    const int N = 10;

    auto **pMatrix1 = new Matrix *[M];
    for (int i = 0; i < M; ++i) {
        pMatrix1[i] = new Matrix[N];
        for (int j = 0; j < N; ++j) {
            Matrix matrix(M, N);
            matrix.fill();
            pMatrix1[i][j]=matrix;
           //c pMatrix1[i][j].print();
        }
    }

    const int K = 15;
    auto **pMatrix2 = new Matrix *[N];
    for (int i = 0; i < N; ++i) {
        pMatrix2[i] = new Matrix[K];
        for (int j = 0; j < K; ++j) {
            Matrix matrix(N, K);
            matrix.fill();

            pMatrix2[i][j]=matrix;
           // pMatrix2[i][j].print();
        }
    }

    auto **result = new Matrix *[M];
    for (int i = 0; i < M; ++i) {
        result[i] = new Matrix[K];
        for (int j = 0; j < K; ++j) {
            Matrix matrix(M, K);
            matrix.fill(0.);
            result[i][j]=matrix;
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < K; ++k) {
                Matrix m = pMatrix1[i][j] * pMatrix2[j][k];
                //m.print();
                result[i][k] = result[i][k] + m;
                //result[i][k].print();
                if (k==K-1) {
                    result[i][k].print();
                }
            }
        }
    }

}
