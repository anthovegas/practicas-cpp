#include <iostream>
#include <iomanip> // Para dar formato a la tabla

using namespace std;

// Función para el Promedio: E_bar = (1/n) * Sum(E_i)
double calcularPromedio(double *E, int n) {
    double suma = 0;
    for (int i = 0; i < n; i++) {
        suma += *(E + i); // Uso de punteros
    }
    return suma / n;
}

// Función para Diferencia Centrada: Di = (E_{i+1} - E_{i-1}) / 2
void calcularDiferenciaCentrada(double *E, double *D, int n) {
    *(D + 0) = 0;           // D0 = 0
    *(D + n - 1) = 0;       // Dn-1 = 0

    for (int i = 1; i < n - 1; i++) {
        *(D + i) = (*(E + i + 1) - *(E + i - 1)) / 2.0;
    }
}

// Función de Normalización en Cascada (Paso 1: Rango [0,1], Paso 2: Suma = 1)
void normalizarCascada(double *E, int n) {
    double min = *E, max = *E;

    // Paso A: Escalar al rango [0,1]
    for (int i = 1; i < n; i++) {
        if (*(E + i) < min) min = *(E + i);
        if (*(E + i) > max) max = *(E + i);
    }

    for (int i = 0; i < n; i++) {
        *(E + i) = (*(E + i) - min) / (max - min);
    }

    // Paso B: Reescalar para que la suma sea 1
    double sumaTotal = 0;
    for (int i = 0; i < n; i++) {
        sumaTotal += *(E + i);
    }

    for (int i = 0; i < n; i++) {
        *(E + i) = *(E + i) / sumaTotal;
    }
}

int main() {
    int n;
    double E[20], E_original[20], D[20];

    cout << "n = ";
    cin >> n;

    if (n > 20) n = 20; // Validación básica según el enunciado

    for (int i = 0; i < n; i++) {
        cin >> E[i];
        E_original[i] = E[i]; // Guardamos copia para la tabla final
    }

    // 1. Calcular promedio
    double promedio = calcularPromedio(E, n);

    // 2. Calcular diferencias centradas
    calcularDiferenciaCentrada(E, D, n);

    // 3. Normalización en cascada (Modifica el arreglo E)
    normalizarCascada(E, n);

    // --- Salida de resultados ---
    cout << "\nIndice | E_original | D_centrada | E_normalizada" << endl;
    cout << "------------------------------------------------------------" << endl;

    fixed(cout);
    cout.precision(3);

    for (int i = 0; i < n; i++) {
        cout << i << "\t| " 
             << E_original[i] << "\t| " 
             << D[i] << "\t| " 
             << E[i] << endl;
    }

    cout << "Energia promedio = " << promedio << endl;

    return 0;
}
