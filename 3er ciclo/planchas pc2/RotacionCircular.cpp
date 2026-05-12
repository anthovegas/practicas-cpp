#include <iostream>
#include <string>
#include "RotacionCircular.h"
using namespace std;

void rotacioncircularizquierda (TP *matriz, int n, int k) {
    for (int i = 0; i < k; ++i) {
        TP temp = matriz[0];
        for (int j = 0; j < n - 1; ++j) {
            matriz[j] = matriz[j + 1];
        }
        matriz[n - 1] = temp;
    }
}

void rotacioncircularderecha (TP *matriz, int n, int k) {
    for (int i = 0; i < k; ++i) {
        TP temp = matriz[n - 1];
        for (int j = n - 1; j > 0; --j) {
            matriz[j] = matriz[j - 1];
        }
        matriz[0] = temp;
    }
}

void rotacioncircular (TP *matriz, int n, int k, string opcion) {
    if (k < 0) {
        k = -k;
        if (opcion == "izquierda") opcion = "derecha";
        else if (opcion == "derecha") opcion = "izquierda";
    }

    k = k % n;

    if (k == 0) {
        return;
    }

    if (opcion == "izquierda") rotacioncircularizquierda(matriz, n, k);
    else if (opcion == "derecha") rotacioncircularderecha(matriz, n, k);
}