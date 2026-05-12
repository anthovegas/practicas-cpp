#ifndef __ORDERAR_ASCENDENTE_H__
#define __ORDERAR_ASCENDENTE_H__

using T = int;

void intercambiar (T &a, T &b);
void QuickSortAscendenteRecursivo(T *pArray, int n);

int frecuenciacontador (T* arr, int n, T num);
void OrdenarRecursivoPorFrecuenciaAscendente(T *pArray, int n);
void PrintArray(T *pArray, int n);

#endif // __ORDERAR_ASCENDENTE_H__