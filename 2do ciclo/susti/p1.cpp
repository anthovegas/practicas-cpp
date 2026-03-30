#include <iostream>
#include <cmath>
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

    cout << "Promedios: " << endl;
    for (int i = 0; i < filas; ++i) {
        double suma = 0.0;
        for (int j = 0; j < columnas; ++j) {
            suma += pMatriz[i][j];
        }
        pProm[i] = suma/columnas;

        cout << "Promedio estudiante " << i + 1 << ": " << pProm[i] << endl;
    }

}

void EliminarProm (double *&pProm, int filas, int columnas) {
    delete[] pProm;
    pProm = nullptr;
}

void pSim (double **&pSim, double *&pProm, int filas) {
    
    pSim = new double*[filas];
    for ( int i = 0; i < filas; ++i) {
        pSim[i] = new double[filas];
    }
    
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < filas; ++j) {
            pSim[i][j] = 1.0 - (abs(pProm[i]-pProm[j])/4.0);
            
            cout << "Sim[" << i + 1 << "][" << j + 1 << "]: " << pSim[i][j] << " ";
        }
        cout << endl;
    }
}

void EliminarpSim (double **&pSim, int filas) {
    for (int i = 0; i < filas; ++i){
        delete[] pSim[i];    
    }
    delete[] pSim;
    pSim = nullptr;
}

void Similitud (double **&pSim, int filas) {
    double max = -1.0;
    int max_i = 0;
    int max_j = 0;
    for (int i = 0; i < filas; ++i) {
        for (int j = i + 1; j < filas; ++j) {
            if (pSim[i][j] > max) {
                max = pSim[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    cout << "Estudiantes más similares: " << max_i + 1 << " y " << max_j + 1 << endl;
    cout << "Similitud: " << max << endl;
}

int main () {
    cout << "Ingrese numero de estudiantes: " << endl;
    int N;
    cin >> N;
    cout << "Ingrese numero de tecnologias: " << endl;
    int M;
    cin >> M;

    int **Estudiantes = nullptr;
    CrearMatriz(Estudiantes, N, M);

    for ( int i = 0; i < N; ++i) {
        for ( int j = 0; j < M; ++j){
            cout << "Ingrese puntajes del estudiante " << i + 1 << " (del 1 al 5): ";
            cin >> Estudiantes[i][j];
        }
    }
    double *pProm = nullptr;
    Prom(Estudiantes, pProm, N, M);
    double **Sim = nullptr;
    pSim(Sim, pProm, N);
    Similitud(Sim, N);

    EliminarpSim(Sim, N);
    EliminarProm(pProm, N, M);
    EliminarMatriz(Estudiantes, N, M);
}