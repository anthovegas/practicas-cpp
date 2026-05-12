#ifndef __ROTACIONCIRCULAR_H__
#define __ROTACIONCIRCULAR_H__
#include <string>

using TP = int;
using namespace std;

void rotacioncircular (TP *matriz, int n, int k, string opcion);
void rotacioncircularizquierda (TP *matriz, int n, int k);
void rotacioncircularderecha (TP *matriz, int n, int k);

#endif // __ROTACIONCIRCULAR_H__