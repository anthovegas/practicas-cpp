#include <iostream>
#include "funciones_planchas.h"
using namespace std;

int frecuenciacontador (T* arr, int n, T num) {
    int count = 0;
    for (auto i = 0; i < n; i++) {
        if (arr[i] == num) {
            count++;
        }
    }
    return count;
}

void contadorarreglo(T* arr, int n, int* count) {
    for (auto i = 0; i < n; i++) {
        bool yaLeido = false;
        for (auto j = 0; j < i; j++) {
            if (arr[j] == arr[i]) {
                yaLeido = true;
                break;
            }
        }
        
        if(yaLeido) continue;

        count[i] = frecuenciacontador(arr, n, arr[i]);

        if (count[i] == 1) {
            cout << arr[i] << " aparece una vez." << endl;
        }
        else {
            cout << arr[i] << " aparece " << count[i] << " veces." << endl;
        }
    }

    for (auto i = 0; i < n; i++) {
        if (count[i] == 1) {
            cout << "Respuesta: " << arr[i] << endl;
            break;
        } else {
            cout << "Respuesta: No hay elementos que aparezcan una sola vez." << endl;
            break;
        }
    }

}

int main() {
    int n;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;

    T* arr = new T[n];
    cout << "Ingrese los elementos del arreglo: ";
    for (auto i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int* count = new int[n];
    contadorarreglo(arr, n, count);

    delete[] arr;
    delete[] count;
    return 0;
}