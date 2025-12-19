#include <iostream>
using namespace std;

void CrearMatriz(int **&pMatriz, int filas, int columnas) {
    pMatriz = new int*[filas];
    for (int i = 0; i < filas; ++i) {
        pMatriz[i] = new int[columnas];
    }
}

void EliminarMatriz (int **&pMatriz, int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        delete[] pMatriz[i];
    }
    delete[] pMatriz;
    pMatriz = nullptr;
}


void Prom (int **&pMatriz, double *&pProm, int filas, int columnas) {
    pProm = new double[filas];

    for (int i = 0; i < filas; ++i) {
        double suma = 0.0;
        for (int j = 0; j < columnas; ++j) {
            suma =+ pMatriz[i][j];
        }
        pProm[i] = suma/columnas;
    }

}

void EliminarProm (double *&pProm, int filas, int columnas) {
    delete[] pProm;
    pProm = nullptr;
}

void factorial(int n) {
    if (n <= 1) {
        
    }
}

void pSim (double **&pSim, int filas) {
    int columnas = 
}