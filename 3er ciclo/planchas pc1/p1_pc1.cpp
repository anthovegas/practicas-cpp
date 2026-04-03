#include "funciones.h"
#include <iostream>
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
            double resultado = 1 + (1 / calcularXrecursiva(1, n));
            cout << "El resultado es: " << resultado  << endl;
        }
    }
}