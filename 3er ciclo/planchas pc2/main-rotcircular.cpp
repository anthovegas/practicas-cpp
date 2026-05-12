#include <iostream>
#include <string>
#include "RotacionCircular.h"
using namespace std;

int main () {
    cout << "Ingrese el tamaño del arreglo (max 100): ";
    int n;
    cin >> n;

    TP matriz[100];
    TP *ptrMatriz = matriz;

    cout << "Ingrese " << n << " elementos: ";
    for (int i = 0; i < n; ++i) {
        cin >> matriz[i];
    }

    cout << "Ingrese el valor de k (cantidad de posiciones a rotar): ";
    int k;
    cin >> k;
    
    cout << "¿Rotar hacia la derecha o izquierda? : ";
    string opcion;
    cin.ignore();
    getline(cin, opcion);

    cout << "Arreglo original: ";
    for (int i = 0; i < n; ++i) {
        cout << matriz[i] << " ";
    }
    cout << endl;

    cout << "Arreglo rotado: ";
    rotacioncircular(ptrMatriz, n, k, opcion);
    for (int i = 0; i < n; ++i) {
        cout << matriz[i] << " ";
    }
    cout << endl;

    return 0;
}

//g++ RotacionCircular.cpp main-rotcircular.cpp -o rotcircular.exe  
//rotcircular.exe