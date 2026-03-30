#include <iostream>
#include "primos.h"
using namespace std;

int main(){
    int n;
    cout << "Ingrese el valor de n: ";
    cin>>n;

    int gemelos[100][2];
    int cantidad;

    int (*ptr)[2] = gemelos;

    encontrarGemelos(n, ptr, cantidad);
    cout << "\nPares de primos gemelos encontrados: " << cantidad << endl;
    cout << "Matriz de primos gemelos: "<<endl;
    
    for(int i = 0; i < cantidad; i++){
        cout << "(" << gemelos[i][0] << ", " << gemelos[i][1] << ")" << endl;
    }
    return 0;
}