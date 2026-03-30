#include <iostream>
using namespace std;

// Función para crear el arreglo dinámico
void crearArreglo(int* arr, int n) {
    arr = new int [n]; //pido memoria para n elementos de tipo int
}

// Función para leer las respuestas del usuario
void leerRespuestas(int* arr, int n) {
    cout << "Ingrese las respuestas (valores entre 1 y 5): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        // Validar que la respuesta esté en el rango correcto
        while (arr[i] < 1 || arr[i] > 5) {
            cout << "Error: La respuesta debe estar entre 1 y 5. Ingrese nuevamente: ";
            cin >> arr[i];
        }
    }
}

// Función para calcular el promedio
float calcularPromedio(int* arr, int n) {
    if (n == 0) return 0.0;
    
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += arr[i];
    }
    //  return static_cast<float>(suma) / n;
    suma = suma / n;
    float prom = suma;
    return prom;
}

// Función para mostrar las frecuencias de cada respuesta
void mostrarFrecuencias(int* arr, int n) {
    int frecuencias[6] = {0}; // Índices 1-5, el 0 no se usa
    
    // Contar frecuencias
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 1 && arr[i] <= 5) {
            frecuencias[arr[i]]++;
        }
    }
    
    cout << "Frecuencia de respuestas:" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << i << ": " << frecuencias[i] << endl;
    }
}

// Función para calcular la moda (puntuación más frecuente)
int calcularModa(int* arr, int n) {
    int frecuencias[6] = {0}; // Índices 1-5
    
    // Contar frecuencias
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 1 && arr[i] <= 5) {
            frecuencias[arr[i]]++;
        }
    }
    
    // Encontrar la moda
    int moda = 1;
    int maxFrecuencia = frecuencias[1];
    
    for (int i = 2; i <= 5; i++) {
        if (frecuencias[i] > maxFrecuencia) {
            maxFrecuencia = frecuencias[i];
            moda = i;
        }
    }
    
    return moda;
}

// Función para liberar la memoria
void destruirArreglo(int *&arr) {
    cout << "Liberando la memoria asignada" << endl;
    delete[] arr; // libera la memoria
    arr = nullptr; // establecer el puntero a nullptr después de liberar
}

int main() {
    int n;
    int* respuestas = nullptr;
    
    cout << "=== SISTEMA DE ENCUESTAS DE SATISFACCION ===" << endl;
    cout << "Ingrese la cantidad de respuestas: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Error: La cantidad de respuestas debe ser un numero positivo." << endl;
        return 1;
    }
    
    crearArreglo(respuestas, n);

    leerRespuestas(respuestas, n);
    
    cout << "\n--- RESULTADOS DE LA ENCUESTA ---" << endl;

    // Promedio
    float promedio = calcularPromedio(respuestas, n);
    cout << "Promedio de satisfaccion: " << promedio << endl;
    
    // Frecuencias
    mostrarFrecuencias(respuestas, n);
    
    // Moda
    int moda = calcularModa(respuestas, n);
    cout << "Moda: " << moda << endl;
    
    // Liberar memoria
    destruirArreglo(respuestas);
    return 0;
}