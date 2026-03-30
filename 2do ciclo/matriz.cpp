#include <iostream>
#include "matriz.h"
using namespace std;

long long** crearMatriz(){
    long long**matriz = new long long*[2];

    for(int i=0;i<2;i++){
        matriz[i] = new long long[2];
    }

    return matriz;
}

void liberarMatriz(long long** matriz){
    for(int i=0;i<2;i++){
        delete[] matriz[i];
    }
    delete[] matriz;
}

void imprimirMatriz(long long** matriz){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<matriz[i][j]<<" ";
        }
        cout << endl;
    }
}

void copiarMatriz(long long** origen, long long** destino){
    for(int i=0;i<2;i++){
        for (int j=0; j<2;j++){
            destino[i][j] = origen [i][j];
        }
    }
}

void multiplicarMatrices(long long** a, long long** b, long long** resultado){
    for(int i=0;i<2;i++){
        for(int j=0; j<2;j++){
            resultado[i][j]=0;

            for(int k=0; k<2; k++){
                resultado[i][j]+= a[i][k] * b[k][j];
            }
        }
    }
}

void matrizPotencia(long long** a, int k, long long** resultado){
    if(k==0){
        for(int i = 0; i<2;i++){
            for(int j = 0;j<2; j++){
                resultado[i][j]= (i == j) ? 1 : 0;
            }
        }
        return;
    }
    if(k == 1){
        copiarMatriz(a, resultado);
        return;
    }

    long long** temp = crearMatriz();

    copiarMatriz(a, resultado);

    for( int exponente = 2; exponente<=k; exponente++){
        copiarMatriz(resultado, temp);
        multiplicarMatrices(temp, a, resultado);
    }
    liberarMatriz(temp);
}