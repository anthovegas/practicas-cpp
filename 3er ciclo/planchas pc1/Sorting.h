#ifndef __SORTING_H__
#define __SORTING_H__

using T1 = int;

void QuickSort(T1 *pArray, int n, bool (*pComp)(T1, T1));
void Merge(T1 *pVect1, int tam1, T1 *pVect2, int tam2, T1 *&rOutput, int &nElem, bool (*pComp)(T1, T1));

bool asc(T1 a, T1 b);
bool desc(T1 a, T1 b);

#endif // __SORTING_H__