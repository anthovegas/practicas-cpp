#include <iostream>
#include "secuencia.h"
using namespace std;

const int MAX=100;

int main(){
    int arr[MAX];
    int n;

    cout << "Ingrese la longitud del arreglo(max d 100): ";
    cin>>n;

    if(n>MAX){
        n = MAX;
    }
    cout << "Ingrese " << n << "elementos: ";
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }

    encontrarSecuenciaImpar(arr, n);

    return 0;
}