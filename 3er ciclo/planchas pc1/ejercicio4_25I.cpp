#include <iostream>
#include "Delivery.h"
using namespace std;

int main() {
    int n, k;
    cout << "Ingrese el numero de repartidores (n): ";
    cin >> n;
    cout << "Ingrese el numero de pedidos (k): ";
    cin >> k;

    T *A = new T[k];
    cout << "Ingrese las distancias de los pedidos: " << endl;
    for (auto i = 0; i < k; ++i) {
        cin >> A[i];
    }

    T Optimo = resolverDelivery(A, k, n);
    mostrarGrupos(A, k, Optimo);

    delete[] A;
    return 0;
}