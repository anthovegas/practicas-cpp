#include "primos.h"
#include <cmath>

bool esPrimo(int numero){
    if(numero < 2) return false;
    if (numero == 2) return true;
    if (numero % 2 == 0) return false;

    for (int i = 3; i<= sqrt(numero); i += 2){
        if (numero % i == 0) return false;
    }
    return true;
}

void encontrarGemelos(int n, int(*gemelos)[2], int &cantidad){
    cantidad = 0;

    for(int i = 2; i <= n - 2; i++){
        if(esPrimo(i) && esPrimo(i+2)){
            if(cantidad < 100){
                gemelos[cantidad][0] = i;
                gemelos[cantidad][1] = i + 2;
                cantidad++;
            } else {
                break;
            }
        }
    }

}