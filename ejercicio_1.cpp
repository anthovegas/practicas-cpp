//Ejercicio 1
//Lea datos desde un vector y realice la búsqueda lineal o secuencial.
//a) Para datos numéricos
//b) Para cadenas

//# En Command Prompt sería:
//g++ ejercicio_1.cpp -o ejercicio_1
//ejercicio_1.exe

//# En PowerShell es igual, pero el ejecutable:
//g++ ejercicio_1.cpp -o ejercicio_1
//.\ejercicio_1.exe
#include <iostream>
using namespace std;

int buscar_num(int* matriz, int n){
    for(int i=0; i<10; ++i){
        if(matriz[i]==n) return i;
    }
    return -1;
}

int buscar_letra(char* cadena, char* palabra){
    for(int i=0; i<sizeof(cadena);++i){
        if(cadena[i]==palabra[0]) return i;
    }
    return -1;
}

int main(){
    int matriz [10]={1,2,3,4,5,6,7,8,9,10};
    char palabra[100];
    cout<<"Para datos numéricos: "<<endl;
    cout<<"Ingrese el número a buscar: ";
    int n;
    cin>>n;

    cout<< buscar_num(matriz, n);
    cout<<"Para cadenas: "<<endl;
    cout<<"Ingrese la cadena: ";
    cin.getline(palabra, 100);
    cout<<"Ingrese la letra a buscar: ";
    char letra[1];
    cin.getline(letra, 1);
    buscar_letra(palabra, letra);
}