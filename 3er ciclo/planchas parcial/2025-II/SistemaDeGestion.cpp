#include <iostream>

using namespace std;

// Función para mezclar dos mitades (parte del Merge Sort)
void merge(int* doc, int* hash, int izq, int med, int der) {
    int n1 = med - izq + 1;
    int n2 = der - med;

    // Arreglos temporales para la mezcla
    int L_doc[100], L_hash[100];
    int R_doc[100], R_hash[100];

    for (int i = 0; i < n1; i++) {
        *(L_doc + i) = *(doc + izq + i);
        *(L_hash + i) = *(hash + izq + i);
    }
    for (int j = 0; j < n2; j++) {
        *(R_doc + j) = *(doc + med + 1 + j);
        *(R_hash + j) = *(hash + med + 1 + j);
    }

    int i = 0, j = 0, k = izq;
    while (i < n1 && j < n2) {
        // Ordenamos por hash de forma creciente
        if (*(L_hash + i) <= *(R_hash + j)) {
            *(hash + k) = *(L_hash + i);
            *(doc + k) = *(L_doc + i);
            i++;
        } else {
            *(hash + k) = *(R_hash + j);
            *(doc + k) = *(R_doc + j);
            j++;
        }
        k++;
    }

    while (i < n1) {
        *(hash + k) = *(L_hash + i);
        *(doc + k) = *(L_doc + i);
        i++; k++;
    }
    while (j < n2) {
        *(hash + k) = *(R_hash + j);
        *(doc + k) = *(R_doc + j);
        j++; k++;
    }
}

void mergeSort(int* doc, int* hash, int izq, int der) {
    if (izq < der) {
        int med = izq + (der - izq) / 2;
        mergeSort(doc, hash, izq, med);
        mergeSort(doc, hash, med + 1, der);
        merge(doc, hash, izq, med, der);
    }
}

// Búsqueda binaria para encontrar el PRIMER índice de un hash
int buscarPrimero(int* hash, int n, int objetivo) {
    int inicio = 0, fin = n - 1;
    int resultado = -1;
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        if (*(hash + medio) == objetivo) {
            resultado = medio;
            fin = medio - 1; // Seguimos buscando a la izquierda para el primero
        } else if (*(hash + medio) < objetivo) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return resultado;
}

void imprimirDatos(int* doc, int* hash, int n) {
    cout << "Indice\tDocumento\tHash" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << "\t" << *(doc + i) << "\t\t" << *(hash + i) << endl;
    }
}

int main() {
    int n;
    int documentos[100], hashes[100];

    cout << "n = ";
    cin >> n;

    // Lectura de datos
    for (int i = 0; i < n; i++) cin >> *(documentos + i);
    for (int i = 0; i < n; i++) cin >> *(hashes + i);

    cout << "\nDatos Originales:" << endl;
    imprimirDatos(documentos, hashes, n);

    // Ordenamiento
    mergeSort(documentos, hashes, 0, n - 1);

    cout << "\nDatos Ordenados por Hash:" << endl;
    imprimirDatos(documentos, hashes, n);

    // Búsqueda
    int hashBuscado;
    cout << "\nIngrese hash a buscar: ";
    cin >> hashBuscado;

    int pos = buscarPrimero(hashes, n, hashBuscado);

    if (pos != -1) {
        cout << "\nDocumentos con hash = " << hashBuscado << ":" << endl;
        cout << "Indice\tDocumento\tHash" << endl;
        // Como está ordenado, los iguales están juntos
        while (pos < n && *(hashes + pos) == hashBuscado) {
            cout << pos << "\t" << *(documentos + pos) << "\t\t" << *(hashes + pos) << endl;
            pos++;
        }
    } else {
        cout << "No se encontraron documentos con ese hash." << endl;
    }

    return 0;
}