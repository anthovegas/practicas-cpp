#include <iostream>
#include <iomanip>

using namespace std;

// Reserva memoria para un arreglo de punteros, y luego para cada fila
int** crearMatriz(int filas, int cols) {
    int** matriz = new int*[filas];
    for (int i = 0; i < filas; i++) {
        *(matriz + i) = new int[cols];
    }
    return matriz;
}

void leerMatriz(int** matriz, int filas, int cols) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> *(*(matriz + i) + j); 
        }
    }
}

// Libera la memoria en orden inverso (primero filas, luego el puntero principal)
void liberarMatriz(int** matriz, int filas) {
    for (int i = 0; i < filas; i++) {
        delete[] *(matriz + i);
    }
    delete[] matriz;
}

void imprimirMatriz(int** matriz, int filas, int cols, int ancho) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            // setw(ancho) establece el ancho de campo para la SIGUIENTE salida
            cout << setw(ancho) << *(*(matriz + i) + j);
        }
        cout << endl; // Salto de línea al terminar cada fila
    }
}

// Aplica la fórmula de convolución estrictamente a los píxeles interiores
void convolucion(int** img, int filas, int cols, int** kernel, int** resSinNorm) {
    // Solo recorremos los píxeles que tienen un vecindario 3x3 completo
    // Es decir, evitamos la primera/última fila y la primera/última columna
    for (int x = 1; x < filas - 1; x++) {
        for (int y = 1; y < cols - 1; y++) {
            int suma = 0;
            
            // Recorremos el kernel (-1 a 1)
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    // Píxel de la imagen: img[x + i][y + j]
                    int pixel = *(*(img + (x + i)) + (y + j));
                    // Píxel del kernel: kernel[i + 1][j + 1] (mapeamos de [-1,1] a [0,2])
                    int valorKernel = *(*(kernel + (i + 1)) + (j + 1));
                    
                    suma += pixel * valorKernel;
                }
            }
            // Guardamos el resultado
            *(*(resSinNorm + x) + y) = suma;
        }
    }
}

// Encuentra min/max de los píxeles modificados y aplica la fórmula
void normalizar(int** resSinNorm, int** resNorm, int filas, int cols) {
    int minVal = 999999;
    int maxVal = -999999;

    // 1. Encontrar minVal y maxVal SOLO en los píxeles donde se aplicó convolución
    for (int x = 1; x < filas - 1; x++) {
        for (int y = 1; y < cols - 1; y++) {
            int val = *(*(resSinNorm + x) + y);
            if (val < minVal) minVal = val;
            if (val > maxVal) maxVal = val;
            
            // OJO: En tu ejemplo de salida, el -1225 central se ignora en la normalización
            // o se mapea a 0. Si observamos la salida del ejemplo:
            // 1470 -> 255
            // 980  -> 209
            // -1225 -> 0
            // Esto implica que para el cálculo del rango de normalización en tu ejemplo,
            // minVal es -1225 y maxVal es 1470.
        }
    }

    // Evitar división por cero si la imagen fuera completamente plana
    if (maxVal == minVal) return;

    // 2. Aplicar fórmula: nuevo = 255 * (x - minVal) / (maxVal - minVal)
    for (int x = 1; x < filas - 1; x++) {
        for (int y = 1; y < cols - 1; y++) {
            int valOriginal = *(*(resSinNorm + x) + y);
            
            // Usamos float o double temporalmente para no perder decimales antes de multiplicar
            double calculo = 255.0 * (valOriginal - minVal) / (maxVal - minVal);
            
            // Asignamos truncando a entero
            *(*(resNorm + x) + y) = (int)calculo;
        }
    }
}

int main() {
    // Definimos dimensiones según el ejemplo (4 filas, 5 columnas)
    int filas = 4;
    int cols = 5;
    
    // 1. Crear matrices dinámicas con punteros dobles
    int** img = crearMatriz(filas, cols);
    int** kernel = crearMatriz(3, 3);
    int** resSinNorm = crearMatriz(filas, cols);
    int** resNorm = crearMatriz(filas, cols);

    // --- CARGA DE DATOS SEGÚN EL EJEMPLO ---
    // (En un examen real podrías leerlos con cin, aquí los asignamos directo para replicar la salida)
    
    // Fila 0
    cout << "Ingrese datos para imagen original: ";
    leerMatriz(img, filas, cols);

     cout << "Ingrese datos para Kernel: ";
    leerMatriz(kernel, 3, 3);


    // Inicializar matrices de resultados con 0 (para los bordes que no se tocan)
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < cols; j++) {
            *(*(resSinNorm + i) + j) = 0;
            *(*(resNorm + i) + j) = 0;
        }
    }

    // --- PROCESAMIENTO ---
    convolucion(img, filas, cols, kernel, resSinNorm);
    normalizar(resSinNorm, resNorm, filas, cols);

    // --- SALIDA A CONSOLA ---
    cout << "Imagen original:" << endl;
    imprimirMatriz(img, filas, cols, 5);

    cout << "\nKernel aplicado:" << endl;
    imprimirMatriz(kernel, 3, 3, 5);

    cout << "\nResultado de la convolucion (sin normalizar):" << endl;
    imprimirMatriz(resSinNorm, filas, cols, 6);

    cout << "\nResultado de la convolucion (normalizado 0-255):" << endl;
    imprimirMatriz(resNorm, filas, cols, 5);

    // --- LIBERAR MEMORIA (Fundamental en la UNI) ---
    liberarMatriz(img, filas);
    liberarMatriz(kernel, 3);
    liberarMatriz(resSinNorm, filas);
    liberarMatriz(resNorm, filas);

    return 0;
}
