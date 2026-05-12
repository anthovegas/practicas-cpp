#include <iostream>
#include "SecuenciaImpares.h"
using namespace std;

bool EsImpar(TP num) {
    return (num % 2 != 0);
}

void ImprimirSecuenciaImparMasLarga (TP *p, int n) {
    TP *mejor_inicio = nullptr;
    int max_longitud = 0;

    for (TP *actual = p; actual < (p + n); actual++) {
        if (EsImpar(*actual)) {
            int longitud_actual = 0;
            for (TP *explorador = actual; explorador < (p + n); explorador += 2) {
                if (EsImpar(*explorador)) longitud_actual++;
                else break;
            }

            if (longitud_actual > max_longitud) {
                max_longitud = longitud_actual;
                mejor_inicio = actual;
            }
        }
    }

    if (max_longitud > 0) {
        cout << "La secuencia impar más larga es: ";
        for (int i = 0; i < max_longitud; i++) {
            cout << *(mejor_inicio + i * 2) << " ";
        }
        cout << endl;
    } else {
        cout << "No se encontraron números impares en la secuencia." << endl;
    }
}