#ifndef __DELIVERY_H__
#define __DELIVERY_H__

#include <iostream>

using T = int;

// Verifica si es posible repartir con un 'limite' de distancia usando 'n' repartidores
bool esPosible(T* A, int k, int n, T limite);

// Encuentra el limite optimo usando Busqueda Binaria
T resolverDelivery(T* A, int k, int n);

//Imprime los grupos resultantes
void mostrarGrupos(T* A, int k, T limiteOptimo);

#endif // __DELIVERY_H__