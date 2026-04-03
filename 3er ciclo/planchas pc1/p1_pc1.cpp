#include "funciones.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "Ingrese un numero natural: ";
    int n;
    cin >> n;
    if (natural(n)) {
        if (n == 1) {
            cout << "El resultado es: 2" << endl;
        }
        else {
            double resultado = 1.0 + (1.0 / calcularXrecursiva(1, n));
            cout << "El resultado es: " <<  resultado  << endl;
        }
    }
}