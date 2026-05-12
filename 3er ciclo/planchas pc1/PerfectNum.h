#ifndef __PERFECTNUM_H__
#define __PERFECTNUM_H__

using T = int;

T perfectNum(T num);
void AlmacenarNum(T* arr, int limite_inf, int limite_sup);
T NumerosPerfectosArreglo(T* arr, int tamaño, int contadorPerfectos, T* perfectNums);
void MostrarPerfectos(T* perfectNums, int contadorPerfectos);
T numPerfectInferioirMasCercano(T num, T* perfectNums, int contadorPerfectos);

#endif