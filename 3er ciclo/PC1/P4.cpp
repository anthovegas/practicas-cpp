#include <iostream>
#include "DistribuirPedidos.h"
using namespace std;

void arreglo(T arr[], int n) {
    for (auto i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (num < 1 || num > 10) {
            cout << "Error: Solo se permiten números enteros del 1 al 10." << endl;
            return;
        }
        arr[i] = num;
    }
}

void PrintArray(T arr[], int n) {
    for (auto i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool esPosible(T* arr, int k, int n) {
    int camionesNecesarios = 1;
    T capacidadActual = 0;

    for (auto i = 0; i < n; ++i) {
        if(arr[i] > 20) return false;
        if(capacidadActual + arr[i] <= 20) {
            capacidadActual += arr[i];
        } else {
            camionesNecesarios++;
            capacidadActual = arr[i];
        }
    }
    return camionesNecesarios;
}

