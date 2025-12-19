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

    cout << "Promedios: " << endl;
    for (int i = 0; i < filas; ++i) {
        double suma = 0.0;
        for (int j = 0; j < columnas; ++j) {
            suma =+ pMatriz[i][j];
        }
        double promedio = suma/columnas;
        pProm[i] = promedio;

        cout << "Promedio estudiante " << i + 1 << ": " << pProm[i] << endl;
    }

}

void EliminarProm (double *&pProm, int filas, int columnas) {
    delete[] pProm;
    pProm = nullptr;
}

long long factorial(int n) {
    if (n <= 1) {
        return 1L;
    }
    return n*factorial(n-1);
}


void pSim (double **&pSim, double *&pProm, int filas) {
    
    int columnas = factorial(filas)/(2*factorial(filas-2));
    pSim = new double*[filas];
    for ( int i = 0; i < filas; ++i) {
        pSim[i] = new double[columnas];
    }
    
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            pSim[i][j] = 1.0 - (abs(pProm[i]-pProm[j])/4.0);
            
            cout << "Sim[" << i + 1 << "][" << j + 1 << "]: " << pSim[i][j] << " ";
        }
        cout << endl;
    }
}

void EliminarpSim (double **&pSim, int filas) {
    int columnas = factorial(filas)/(2*factorial(filas-2));
    for (int i = 0; i < filas; ++i){
        delete[] pSim[i];    
    }
    delete[] pSim;
    pSim = nullptr;
}

void Similitud (double **&pSim, int filas) {
    int columnas = factorial(filas)/(2*factorial(filas-2));
    
    double max = pSim[0][1];
    int max_i = 0;
    int max_j = 1;
    for (int i = 0; i < filas; ++i) {
        for (int j = i + 1; j < columnas; ++j) {
            if (pSim[i][j] > max) {
                max = pSim[i][j];
                max_i = i + 1;
                max_j = j + 1;
            }
        }
    }
    cout << "Estudiantes más similares: " << max_i << " y " << max_j << endl;
    cout << "Similitud: " << pSim[max_i][max_j] << endl;
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

    EliminarMatriz(Estudiantes, N, M);
    EliminarProm(pProm, N, M);
    EliminarpSim(Sim, N);

}