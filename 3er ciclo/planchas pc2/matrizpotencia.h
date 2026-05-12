#ifndef __MATRIZPOTENCIA_H__
#define __MATRIZPOTENCIA_H__

#include <cstddef>  

using TP = unsigned long long int;

void CreateMatrix(TP **&pMat, const size_t rows, const size_t cols);
void ReadMatrix(TP **pMat, const size_t rows, const size_t cols);
void PrintMatrix(TP **pMat, const size_t rows, const size_t cols);
void DeleteMatrix(TP **&pMat, const size_t rows);

void multiplicarMatrices(TP **pMatA, TP **pMatB, TP **&pMatC, int n);
void matrizPotencia(TP **&A, int k, int tamaño);

#endif // __MATRIZPOTENCIA_H__