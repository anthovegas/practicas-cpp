#include "funciones.h"
#include <iostream>
using namespace std;

bool natural(int n) {
    if (n > 0) {
        cout << "El numero es natural" << endl;
        return true;
    }
    else {
        cout << "El numero no es natural" << endl;
        return false;
    }
}

double calcularXrecursiva(int i, int n) {
    // caso i = n = 1 aparte.
    //suponiendo i = 1 para iniciar.
    double numerador = (i + 1) / 2;

    // caso base, si i = n - 1.
    if (i == n - 1) {
        if (i % 2 != 0) return i + (numerador / n);
        else return i - (numerador / n);
    }

    //caso recursivo.
    
    if (i % 2 != 0) {
        return i + (numerador / calcularXrecursiva(i + 1, n));
    } else {
        return i - (numerador / calcularXrecursiva(i + 1, n));
    }
    
}

