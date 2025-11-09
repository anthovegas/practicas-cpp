#include <iostream>
#include <cstring>
using namespace std;

void ordSeleccionNumeros(int* arr, int tamaño){
    for(int i=0; i<tamaño-1;i++){
        //encontrar el mínimo en el resto del array
        int min_idx=i;
        for(int j=i+1; j<tamaño;j++){
            if(arr[j]<arr[min_idx]){
                min_idx=j;
            }
        }
        //intercambiar el mínimo con el primer elemento no ordenado
        int temp = arr[min_idx];
        arr[min_idx]=arr[i];
        arr[i]=temp;
    }
}

void ordSeleccionCadenas(char arr[][100], int tamaño){
    for(int i=0; i<tamaño-1;i++){
        //encontrar el mínimo en el resto del array
        int min_idx = i;
        for(int j=i+1;j<tamaño;j++){
            if(strcmp(arr[j], arr[min_idx])<0){
                min_idx=j;
            }
        }
        //intercambiar el mínimo con el primer elemento no ordenado

        char temp[100];
        strcpy(temp, arr[min_idx]);
        strcpy(arr[min_idx], arr[i]);
        strcpy(arr[i], temp);
    }
}

//funcion par mostrar array de números

void mostrarNumeros(int* arr, int tamaño){
    for(int i=0; i<tamaño;i++){
        cout<<arr[i]<<" ";
    }
    cout << endl;
}

//función para mostrar array de cadenas

void mostrarCadenas(char arr[][100], int tamaño){
    for(int i=0; i<tamaño; i++){
        cout<<"\""<<arr[i]<<"\" ";
    }
    cout << endl;
}

int main() {
    int opcion;
    const int MAX = 100;

     cout << "=== ORDENACION POR SELECCION ===" << endl;
    cout << "1. Ordenar datos numericos" << endl;
    cout << "2. Ordenar cadenas" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    if(opcion == 1){
        //ordenacion de numeros;
        int numeros[MAX];
        int n;

        cout << "\nIngrese el tamaño del array: ";
        cin >> n;

        if(n > MAX || n <= 0){
            cout << "Tamaño no válido!" << endl;
            return 1;
        }

        cout << "Ingrese " << n << " numeros:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Elemento " << i + 1 << ": ";
            cin >> numeros[i];
        }

        cout << "\nArray original: ";
        mostrarNumeros(numeros, n);

        ordSeleccionNumeros(numeros, n);

        cout << "Array ordenado: ";
        mostrarNumeros(numeros, n);

    } else if( opcion == 2){
        //ordenacion de cadenas
        char cadenas[MAX][100];
        int n;

        cout << "\nIngrese el tamaño del array: ";
        cin >> n;
        cin.ignore(); //limpiar buffer

        if (n > MAX || n <= 0){
            cout << "Tamaño no válido!" << endl;
            return 1;
        }

        cout << "Ingrese " << n << " cadenas: " << endl;
        for (int i = 0; i < n; i++){
            cout << "Cadena " << i + 1 << ": ";
            cin.getline(cadenas[i], 100);
        }

        cout << "\nArray original: ";
        mostrarCadenas(cadenas, n);

        ordSeleccionCadenas(cadenas, n);

        cout << "Array ordenado: ";
        mostrarCadenas(cadenas, n);

    } else {
        cout << "Opcion no valida!" << endl;
        return 1;
    }

    return 0;
}