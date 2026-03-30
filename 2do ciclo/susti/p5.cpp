#include <iostream>
#include <iomanip>
using namespace std;

void normalizarFila(double* matriz, int columnas, int fil) {
    double suma = 0;
    for (int i = 0; i < columnas; ++i) {
        suma += *(matriz + fil * columnas + i);
    }

    if (suma != 0) {
        for (int i = 0; i < columnas; ++i) {
        *(matriz + i) = *(matriz + i)/suma;
        }
    }
    
}

void normalizarColumna(double* matriz, int filas, int columnas, int col) {
    double suma = 0;
    for (int i = 0; i < filas; ++i) {
        suma += *(matriz + i * columnas + col);
    }

    if (suma != 0) {
        for (int i = 0; i < filas; ++i) {
        *(matriz + i * columnas + col) /= suma;
        }
    }
}

void imprimirMatriz(double* matriz, int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << fixed << setprecision(2) << *(matriz + i * columnas + j) << "\t";
        }
        cout << endl;
    }
}

int main() {
    double Matriz[3][3] = {{0,1,2},{3,4,5},{6,7,8}};
    double* pMatriz = (double*)Matriz;
    imprimirMatriz(pMatriz, 3, 3);

    normalizarFila (pMatriz, 3, 2);
    normalizarColumna(pMatriz, 3, 3, 3);
    imprimirMatriz (pMatriz, 3, 3);
}