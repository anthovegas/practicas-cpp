#include <iostream>
#include "matriz.h"
using namespace std;

int main(){
    int k;

    cout<<"Ingrese el valor de k(numero natural): ";
    cin>>k;

    if(k<0){
        cout<<"ERROR: k debe ser un numero natural. "<<endl;
        return 1;
    }

    long long** A = crearMatriz();

    A[0][0] = 2;
    A[0][1] = 3;
    A[1][0] = 4;
    A[1][1] = 5;

    long long** resultado = crearMatriz();

    matrizPotencia(A, k, resultado);

    cout<<"\nMatriz A:" << endl;
    imprimirMatriz(A);

    cout << "\nA^"<<k<<":"<<endl;
    imprimirMatriz(resultado);

    liberarMatriz(A);
    liberarMatriz(resultado);

    return 0;

}