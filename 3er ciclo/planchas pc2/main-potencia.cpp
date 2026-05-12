#include <iostream>
#include "matrizpotencia.h"
using namespace std;

int main() {
    TP **A;
    int tamaño = 2;
    CreateMatrix(A, tamaño, tamaño);
    A[0][0] = 2;
    A[0][1] = 3;
    A[1][0] = 4;
    A[1][1] = 5;

    cout << "Ingrese un numero natural: ";
    int n;
    cin >> n;
    matrizPotencia(A, n, tamaño);
    PrintMatrix(A, tamaño, tamaño);
    DeleteMatrix(A, tamaño);
}