#ifndef __CARACTERES_H__
#define __CARACTERES_H__

#include <iostream>
#include <string>

// Alias de tipos
using C = char;
using S = string;
using OS = ostream;

// Versión char
void EliminarEspacios(C* cadena);
void Minusculas(C* cadena);
void VocalesNum(C* cadena, int capacidad);
void Imprimir(C* cadena, OS& os);

// Versión string
void ProcesarTodoString(S& palabra);
void ImprimirString(S& palabra, OS& os);

#endif