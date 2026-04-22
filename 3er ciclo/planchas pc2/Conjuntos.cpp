#include <iostream>
#include "conjuntos.h"
using namespace std;

void Create_Matrix(int *&matrix, int n) {
    matrix = new int[n];
}

void Read_Matrix(int *matrix, int n) {
    for (auto i = 0; i < n; ++i)
        cin >> matrix[i];
}

void Print_Matrix(int *matrix, int n) {
    for (auto i = 0; i < n; ++i) 
        cout << "Elemento " << i << ": " << matrix[i] << " ";
}

int Union(int *matrixA, int *matrixB, int *&matrixUnion, int n, int m) {
    
    int pos = 0;
    for (auto i = 0; i < n; ++i) {
        bool encontrado = false;
        
        for (auto j = 0; j < pos; ++j) {
            if (matrixUnion[j] == matrixA[i]) {
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            matrixUnion[pos] = matrixA[i];
                pos++;
        }
    }

    for (auto i = 0; i <m; ++i) {
        bool encontrado = false;
        
        for (auto j = 0; j < pos; ++j) {
            if (matrixUnion[j] == matrixB[i]) {
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            matrixUnion[pos] = matrixB[i];
                pos++;
        }
    }
    int *matrixFinal;
    Create_Matrix(matrixFinal, pos);
    for (auto i = 0; i < pos; ++i) {
        matrixFinal[i] = matrixUnion[i];
    }

    Delete_Matrix(matrixUnion);
    matrixUnion = matrixFinal;
    return pos;
}

void Delete_Matrix(int *&matrix) {
    delete[] matrix;
}

int main() {
    cout << "Cuantos elementos desea ingresar en el conjunto A? :";
    int n;
    cin >> n;

    int *matrixA;
    Create_Matrix(matrixA, n);
    Read_Matrix(matrixA, n);

    cout << "Cuantos elementos desea ingresar en el conjunto B? :";
    int m;
    cin >> m;

    int *matrixB;
    Create_Matrix(matrixB, m);
    Read_Matrix(matrixB, m);

    int *matrixUnion;
    Create_Matrix(matrixUnion, n + m);

    int totalUnion = Union(matrixA, matrixB, matrixUnion, n, m);

    Print_Matrix(matrixUnion, totalUnion);

    Delete_Matrix(matrixA);
    Delete_Matrix(matrixB);
    Delete_Matrix(matrixUnion);

    return 0;
}