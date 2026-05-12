#include <iostream>
#include "Sorting.h"
using namespace std;

template <typename T>
void PrintArray(T arr[], int n) {
    for (auto i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "Ingrese el numero de elementos: ";
    int n;
    cin >> n;

    cout << "Para int(i) o para float(f): ";
    char choice;
    cin >> choice;

    if (choice == 'i') {
        int* arr1 = new int[n];
        cout << "Ingrese los elementos: ";
        for (auto i = 0; i < n; ++i) cin >> arr1[i];

        PrintArray(arr1, n);
        BurbujaRecursivo(arr1, n, Mayor<int>);
        cout << "Ordenado de mayor a menor: ";
        PrintArray(arr1, n);

        BurbujaRecursivo(arr1, n, Menor<int>);
        cout << "Ordenado de menor a mayor: ";
        PrintArray(arr1, n);

        delete[] arr1;

    } else if (choice == 'f') {
        float* arr2 = new float[n];
        cout << "Ingrese los elementos: ";
        for (auto i = 0; i < n; ++i) cin >> arr2[i];

        PrintArray(arr2, n);
        BurbujaRecursivo(arr2, n, Mayor<float>);
        cout << "Ordenado de mayor a menor: ";
        PrintArray(arr2, n);

        BurbujaRecursivo(arr2, n, Menor<float>);
        cout << "Ordenado de menor a mayor: ";
        PrintArray(arr2, n);

        delete[] arr2;
    } else {
        cout << "Opcion no valida." << endl;
    }
    return 0;
}