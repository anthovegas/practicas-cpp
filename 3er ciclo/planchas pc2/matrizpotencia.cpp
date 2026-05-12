#include "matrizpotencia.h"
#include <iomanip>
#include <iostream>
using namespace std;

void CreateMatrix(TP **&pMat, const size_t rows, const size_t cols) {
    pMat = new TP *[rows];
    for (size_t i = 0; i < rows; ++i) 
        pMat[i] = new TP [cols];
}

void ReadMatrix(TP **pMat, const size_t rows, const size_t cols) {
    cout << "Ingrese los valores: " << endl;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            cin >> pMat[i][j];
        } 
    }
}

void PrintMatrix(TP **pMat, const size_t rows, const size_t cols) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            cout << pMat[i][j] << " ";
        }
        cout << endl;
    }
}

void DeleteMatrix(TP **&pMat, const size_t rows) {
    for (size_t i = 0; i < rows; ++i) 
        delete[] pMat[i];
    delete[] pMat;
    pMat = nullptr;
}

void multiplicarMatrices(TP **pMatA, TP **pMatB, TP **&pMatC, int n) {
    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < n; ++j) {
            pMatC[i][j] = 0;
            for (auto k = 0; k < n; ++k) {
                pMatC[i][j] += pMatA[i][k] * pMatB[k][j];
            }
        }
    }
}

void matrizPotencia(TP **&A, int k, int tamaño) {
    if (k == 0) {
        for (auto i = 0; i < tamaño; ++i) {
            for (auto j = 0; j < tamaño; ++j) {
                if (i == j) {
                    A[i][j] = 1;
                } else {
                    A[i][j] = 0;
                }
            }
        }
    }

    if (k < 0 || k == 1) return;

    TP **Resultado, **Base;
    CreateMatrix(Resultado, tamaño, tamaño);
    CreateMatrix(Base, tamaño, tamaño);

    for(auto i = 0; i < tamaño; ++i)
        for (auto j = 0; j < tamaño; ++j)
            Base[i][j] = A[i][j];
    
    for (auto i = 1; i < k; ++i) {
        multiplicarMatrices(A, Base, Resultado, tamaño);

        for (auto i = 0; i < tamaño; ++i)
            for (auto j = 0; j < tamaño; ++j)
                A[i][j] = Resultado[i][j];
    }
}

//g++ matrizpotencia.cpp main-potencia.cpp -o potencia.exe
// ./potencia.exe