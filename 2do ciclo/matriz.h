#ifndef __MATRIZ_H__
#define __MATRIZ_H__

long long**crearMatriz();
void liberarMatriz(long long**matriz);
void multiplicarMatrices (long long**a, long long** b, long long** resultado);
void matrizPotencia(long long**a, int k, long long** resultado);
void imprimirMatriz(long long** matriz);
void copiarMatriz(long long** origen, long long** destino);

#endif

