#include <iostream>
#include <cstring>
using namespace std;

void ordBurbujaNumeros(int* arr, int tamaño){
    bool intercambiado;
    for(int i = 0; i < tamaño - 1; i++){
        intercambiado = false;
        for(int j = 0; j < tamaño - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                //intercambiar elementos
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                intercambiado = true;
            }
        }

        //si no hubo intercambios, el array ya está ordenado
        if(!intercambiado){
            break;
        }
    }
}

void ordBurbujaCadenas(char arr[][100], int tamaño){
    bool intercambiado;
    for(int i = 0; i < tamaño - 1; i++){
        intercambiado = false;
        for(int j = 0; j < tamaño - i - 1; j++){
            if(strcmp(arr[j], arr[j + 1]) > 0){
                char temp[100];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
                intercambiado = true;
            }
        }

        //si no hubo intercambios, el array está ordenado
        if(!intercambiado){
            break;
        }
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

//función para mostrar el proceso paso a paso 
void ordBurbujaConPasos(int* arr, int tamaño){
    cout << "\nProceso de ordenacion: " << endl;
    bool intercambiado;
    for(int i = 0; i < tamaño - 1; i++){
        intercambiado = false;
        cout << "Pasada " << i + 1 << ": ";

        for(int j = 0; j < tamaño - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                intercambiado = true;
            }
        }

        //mostrar array después de esta pasada
        mostrarNumeros(arr, tamaño);
        
        if(!intercambiado){
            cout << "¡Array ordenado! No se necesitan mas pasadas." << endl;
            break;
        }
    }
}

int main(){
    int opcion;
    const int MAX = 100;

    cout << "=== ORDENACION POR BURBUJA MEJORADA ===" << endl;
    cout << "1. Ordenar datos numericos" << endl;
    cout << "2. Ordenar cadenas" << endl;
    cout << "3. Ordenar numeros con pasos (demo)" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    if(opcion == 1 || opcion == 3){
        // ordenación de números
        int numeros[MAX];
        int n;

        cout << "\nIngrese el tamaño del array: ";
        cin >> n;

        if(n > MAX || n <= 0){
            cout << "Tamaño no válido!" << endl;
            return 1;
        }

        cout << "Ingrese " << n << " numeros: " << endl;
        for (int i = 0; i < n; i++){
            cout << "Elemento " << i + 1 << ": ";
            cin >> numeros[i];
        }

        cout << "\nArray original: ";
        mostrarNumeros(numeros, n);

        if(opcion == 1){
            ordBurbujaNumeros(numeros, n);
            cout << "Array ordenado: ";
            mostrarNumeros(numeros, n);
        } else {
            ordBurbujaConPasos(numeros, n);
        }
    } else if (opcion == 2){
        char cadenas[MAX][100];
        int n;

        cout << "\nIngrese el tamaño del array: ";
        cin >> n;
        cin.ignore();

        if(n > MAX || n <= 0) {
            cout << "Tamaño no válido!" << endl;
            return 1;
        }

        cout << "Ingrese " << n << " cadenas:" << endl;
        for(int i = 0; i < n; i++){
            cout << "Cadena " << i + 1 << ": ";
            cin.getline(cadenas[i], 100);
        }

        cout << "\nArray original: ";
        mostrarCadenas(cadenas, n);

        ordBurbujaCadenas(cadenas, n);

        cout << "Array ordenado: ";
        mostrarCadenas(cadenas, n);

    } else {
        cout << "Opcion no valida!" << endl;
        return 1;
    }

    return 0;
}