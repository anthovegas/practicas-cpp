#include <iostream>
#include "reverse.h"
using namespace std;
int main(){
    cout<<"Ingrese el tamaño del arreglo(max 100): ";
    int N;
    cin>>N;
    if(N<100){
        int arr[N];
        cout<<"Ingrese los valores del arreglo: ";
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }

        cout<<"Ingrese la cantidad de rotaciones: ";
        int k;
        cin>>k;
        k %= N;

        cout<<"¿Rotar hacia la derecha o izquierda?: ";
        char direccion[10];
        cin>>direccion;
        
        if(direccion[0]=='i' || direccion[0]=='I'){
            rotleft(arr, N, k);
        } else {
            rotright(arr, N, k);
        }

        cout<<"El arreglo ahora es: ";
        for (int i=0; i<N; i++){
            cout<<arr[i]<<" ";
        }

    }
    return 0;
}