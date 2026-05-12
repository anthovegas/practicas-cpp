#include "Delivery.h"

bool esPosible(T* A, int k, int n, T limite) {
    int repartidoresNecesarios = 1;
    T distanciaActual = 0; 

    for (auto i = 0; i < k; ++i) {
        //Si un solo pedido supera el limite, no es posible
        if (A[i] > limite) return false;

        if (distanciaActual + A[i] <= limite) {
            distanciaActual += A[i];
        } else {
            repartidoresNecesarios++;
            distanciaActual = A[i];
        }
    }
    return repartidoresNecesarios <= n;
}

T resolverDelivery(T* A, int k, int n) {
    T bajo = 0, alto = 0;

    // El rango de la busqueda binaria:
    // El minimo posible es el pedido mas grande.
    // El maximo posible es la suma de todos.
    for (auto i = 0; i < k; ++i) {
        if (A[i] > bajo) bajo = A[i];
        alto += A[i];
    }

    T resultado = alto; // Inicializamos con el peor caso
    while (bajo <= alto) {
        T medio = bajo + (alto - bajo) / 2;

        if (esPosible(A, k, n, medio)) {
            resultado = medio;
            alto = medio - 1; // Intentamos encontrar un limite mas pequeño
        } else {
            bajo = medio + 1;
        }
    }
    return resultado;
}

void mostrarGrupos(T* A, int k, T limiteOptimo) {
    std::cout << "Subdivision optima (Distancia Maxima:" << limiteOptimo << "km):" << std::endl;
    T sumaActual = 0;
    std::cout << "[ ";
    for (auto i = 0; i < k; ++i) {
        if (sumaActual + A[i] > limiteOptimo) {
            std::cout << "] [ " << A[i] << " ";
            sumaActual = A[i];
        } else {
            std::cout << A[i] << " ";
            sumaActual += A[i];
        }
    }
    std::cout << "]" << std::endl;
}