#include "PerfectNum.h"
#include <iostream>
#include <cmath>

using namespace std;

T perfectNum(T num) {
    T sum = 0;
    for (auto i = 1; i < num; ++i) {
        if (num % i == 0) {
            if (i == num) continue;
            sum += i;
        }
    }
    return sum;
}

void AlmacenarNum(T* arr, int limite_inf, int limite_sup) {
    int tamaño = limite_sup - limite_inf + 1;
    for (auto i = 0; i < tamaño; ++i) {
        arr[i] = limite_inf + i;
    }
}

T NumerosPerfectosArreglo(T* arr, int tamaño, int contadorPerfectos, T* perfectNums) {
    for (auto i = 0; i < tamaño; ++i) {
        if (perfectNum(arr[i]) == arr[i]) {
            perfectNums[contadorPerfectos] = arr[i];
            contadorPerfectos++;
        }
    }
    return contadorPerfectos;
    
}

void MostrarPerfectos(T* perfectNums, int contadorPerfectos) {
    cout << "Numeros perfectos encontrados: " << contadorPerfectos << endl;
    for (auto i = 0; i < contadorPerfectos; ++i) {
        cout << perfectNums[i] << " ";
    }
    cout << endl;
}

T numPerfectInferioirMasCercano(T num, T* perfectNums, int contadorPerfectos) {
    T numPerfectoMasCercano = 0;
    for (auto i = 0; i < contadorPerfectos; ++i) {
        if (perfectNums[i] < num && perfectNums[i] > numPerfectoMasCercano) {
            numPerfectoMasCercano = perfectNums[i];
        }
    }
    return numPerfectoMasCercano;
}