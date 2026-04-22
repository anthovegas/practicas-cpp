#ifndef __CONJUNTOS_H__
#define __CONJUNTOS_H__

void Create_Matrix(int *&matrix, int n);
void Read_Matrix(int *matrix, int n);
void Print_Matrix(int *matrix, int n);
int Union(int *matrixA, int *matrixB, int *&matrixUnion, int n, int m);
void Delete_Matrix(int *&matrix);

#endif // __CONJUNTOS_H__