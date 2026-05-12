#include <iostream>
#include "PerfectNum.h"
using namespace std;

int main() {
    cout << "Ingrese el limite inferior: ";
    T limite_inf;
    cin >> limite_inf;
    cout << "Ingrese el limite superior: ";
    T limite_sup;
    cin >> limite_sup;

    int tamaño = limite_sup - limite_inf + 1;
    T* arr = new T[tamaño];
    AlmacenarNum(arr, limite_inf, limite_sup);
    int contadorPerfectos = NumerosPerfectosArreglo(arr, tamaño, 0, arr);
    MostrarPerfectos(arr, contadorPerfectos);
    
    cout << "Ingrese un numero para encontrar el numero perfecto inferior mas cercano: ";
    T num;
    cin >> num;
    T numPerfectoMasCercano = numPerfectInferioirMasCercano(num, arr, contadorPerfectos);
    if (numPerfectoMasCercano != 0) {
        cout << "El numero perfecto inferior mas cercano a " << num << " es: " << numPerfectoMasCercano << endl;
    } else {
        cout << "No hay numero perfecto inferior a " << num << " en el rango dado." << endl;
    }
    delete[] arr;
    return 0;
}