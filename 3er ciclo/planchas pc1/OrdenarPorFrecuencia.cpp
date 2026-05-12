#include <iostream>
#include "OrdenarAscendente.h"
using namespace std;

int main() {
    int n;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;

    T* arr = new T[n];
    cout << "Ingrese los elementos del arreglo: ";
    for (auto i = 0; i < n; i++) {
        cin >> arr[i];
    }

    PrintArray(arr, n);
    
    QuickSortAscendenteRecursivo(arr, n);
    cout << "Arreglo ordenado ascendentemente: ";
    PrintArray(arr, n);

    OrdenarRecursivoPorFrecuenciaAscendente(arr, n);
    cout << "Arreglo ordenado por frecuencia ascendente: ";
    PrintArray(arr, n);

    delete[] arr;
    return 0;
}