#include <iostream>
#include <cstring>
using namespace std;

//función para mezclar dos sublistas ordenadas en un mismo array
void mezclaLista(int* a, int Izq, int Centro, int Der){
    int n1 = Centro - Izq + 1; //Tamaño de la primera sublista
    int n2 = Der - Centro; //Tamaño de la segunda sublista

    //Arrays temporales para guardar las sublistas
    int* temporalIzq = new int[n1];
    int* temporalDer = new int[n2];

    //Copiar datos a los arrays temporales
    for (int i = 0; i < n1; i++){
        temporalIzq[i] = a[Izq + i];
    }
    for(int j = 0; j < n2; j++){
        temporalDer[j] = a[Centro + 1 + j];
    }

    //Mezclar los arrays temporales de vuelta al array original
    int i = 0; // índice inicial de la primera sublista
    int j = 0; //índice inicial de la segunda sublista
    int k = Izq; //índice inicial del array mezclado

    while(i < n1 && j < n2) {
        if(temporalIzq[i] <= temporalDer[j]){
            a[k] = temporalIzq[i];
            i++;
        } else {
            a[k] = temporalDer[j];
            j++;
        }
        k++;
    }

    //Copiar los elementos restantes de temporalIz[] si los hay
    while(i < n1){
        a[k] = temporalIzq[i];
        i++;
        k++;
    }

    //Copiar los elementos restantes de temporalDer[] si los hay
    while(j < n2){
        a[k] = temporalDer[j];
        j++;
        k++;
    }

    //Liberar memoria
    delete[] temporalIzq;
    delete[] temporalDer;
}

//Función para mezclar dos sublistas ordenadas de cadenas
void mezclaListaCadenas(char a[][100], int Izq, int Centro, int Der) {
    int n1 = Centro - Izq + 1;
    int n2 = Der - Centro;

    //Arrays temporal para cadenas
    char temporalIzq[n1][100];
    char temporalDer[n2][100];

    //Copiar datos a los arrays temporales
    for(int i = 0; i < n1; i++){
        strcpy(temporalIzq[i], a[Izq + i]);
    }
    for(int j = 0; j < n2; j++){
        strcpy(temporalDer[j], a[Centro + 1 + j]);
    }

    //Mezclar

    int i = 0, j = 0, k = Izq;

    while (i < n1 && j < n2){
        if(strcmp(temporalIzq[i], temporalDer[j]) <= 0){
            strcpy(a[k], temporalIzq[i]);
            i++;
        } else {
            strcpy(a[k], temporalDer[j]);
            j++;
        }
        k++;
    }

    //Copiar elementos restantes
    while(i < n1){
        strcpy(a[k], temporalIzq[i]);
        i++;
        k++;
    }

    while (j < n2){
        strcpy(a[k], temporalDer[j]);
        j++;
        k;
    }
}

void mostrarArray(int* arr, int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Función para mostrar array de cadenas
void mostrarArrayCadenas(char arr[][100], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        cout << "\"" << arr[i] << "\" ";
    }
    cout << endl;
}

//Función para verificar si un array está ordenado
bool estaOrdenado(int* arr, int tamaño){
    for(int i = 0; i < tamaño - 1; i++){
        if( arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int opcion;
    const int MAX = 100;
    
    cout << "=== MEZCLA DE LISTAS ORDENADAS ===" << endl;
    cout << "1. Mezclar listas numericas" << endl;
    cout << "2. Mezclar listas de cadenas" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    if (opcion == 1) {
        int n, Izq, Centro, Der;
        
        cout << "\nIngrese el tamaño del array: ";
        cin >> n;
        
        if (n > MAX || n <= 0) {
            cout << "Tamaño no válido!" << endl;
            return 1;
        }
        
        int* arr = new int[n];
        
        cout << "Ingrese los elementos del array:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Elemento " << i + 1 << ": ";
            cin >> arr[i];
        }

        cout << "\nIngrese los indices para la mezcla:" << endl;
        cout << "Izquierda (0 a " << n - 1 << "): ";
        cin >> Izq;
        cout << "Centro (" << Izq << " a " << n - 1 << "): ";
        cin >> Centro;
        cout << "Derecha (" << Centro + 1 << " a " << n - 1 << "): ";
        cin >> Der;
    }
}