#include <iostream>
#include <cstring>
using namespace std;

void ordInsercionNumeros(int* arr, int tamaño){
    for(int i = 1; i < tamaño; i++){
        int clave = arr[i];
        int j = i - 1;

        //mover elementos mayores que la clave una posicion adelante
        while(j >= 0 && arr[j] > clave){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = clave;
    }
}

void ordInsercionCadenas(char arr[][100], int tamaño){
    for(int i = 1; i < tamaño; i++){
        char clave[100];
        strcpy(clave, arr[i]);
        int j = i - 1;

        // mover elementos mayores que la clave una posicion adelante
        while(j >= 0 && strcmp(arr[j], clave) > 0){
            strcpy(arr[j + 1], arr[j]);
            j = j - 1;
        }
        strcpy(arr[j + 1], clave);
    }
}

void mostrarNumeros(int* arr, int tamaño){
    for(int i = 0; i < tamaño; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mostrarCadenas(char arr[][100], int tamaño){
    for(int i = 0; i < tamaño; i++){
        cout << "\"" << arr[i] << "\" ";
    }
    cout << endl;
}

int main(){
    int opcion;
    const int MAX = 100;
     cout << "=== ORDENACION POR INSERCION ===" << endl;
    cout << "1. Ordenar datos numericos" << endl;
    cout << "2. Ordenar cadenas" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    if(opcion == 1){

        int numeros[MAX];
        int n;

        cout << "\nIngrese el tamaño del array: ";
        cin >> n;

        if(n > MAX || n <= 0){
            cout << "Tamaño no válido!" << endl;
            return 1;
        }

        cout << "Ingrese " << n << " numeros:" << endl;
        for(int i = 0; i < n; i++){
            cout << "Elemento " << i + 1 << ": ";
            cin >> numeros[i];
        }

        cout << "\nArray original: ";
        mostrarNumeros(numeros, n);

        ordInsercionNumeros(numeros, n);

        cout << "Array ordenado: ";
        mostrarNumeros(numeros, n);

    } else if (opcion == 2){

        char cadenas[MAX][100];
        int n;

        cout << "\nIngrese el tamaño del array: ";
        cin >> n;
        cin.ignore();

        if(n > MAX || n <= 0){
            cout << "Tamaño no válido!" << endl;
            return 1;
        }

        cout << "Ingrese " << n << " cadenas: " << endl;
        for (int i = 0; i < n; i++){
            cout << "Cadena " << i + 1 <<": ";
            cin.getline(cadenas[i], 100);
        }

        cout << "\nArray original: ";
        mostrarCadenas(cadenas, n);

        ordInsercionCadenas(cadenas, n);

        cout << "Array ordenado: ";
        mostrarCadenas(cadenas, n);

    } else {
        cout << "Opcion no valida!" << endl;
        return 1;
    }
    
    return 0;
}