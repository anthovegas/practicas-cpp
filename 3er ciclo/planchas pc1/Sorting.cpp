#include "Sorting.h"

bool asc(T1 a, T1 b) { return a < b; }
bool desc(T1 a, T1 b) { return a > b; }

void intercambiar (T1 &a, T1 &b) {
    T1 temp = a;
    a = b;
    b = temp;
}

void QuickSort(T1 *pArray, int n, bool (*pComp)(T1, T1)) {
    if (n <= 1) return;

    T1 pivot = pArray[n / 2];
    int i = 0, j = n - 1;

    while (i <= j) {
        while (pComp(pArray[i], pivot) && pArray[i] != pivot) i++;
        while (pComp(pivot, pArray[j]) && pArray[j] != pivot) j--;

        if (i <= j) {
            intercambiar(pArray[i], pArray[j]);
            i++;
            j--;
        }
    }

    if (j > 0) QuickSort(pArray, j + 1, pComp);
    if (i < n) QuickSort(pArray + i, n - i, pComp);
}

void Merge(T1 *pVect1, int tam1, T1 *pVect2, int tam2, T1 *&rOutput, int &nElem, bool (*pComp)(T1, T1)) {
    T1 *temp = new T1[tam1 + tam2];
    int i = 0, j = 0, k = 0;

    while (i < tam1 || j < tam2) {
       T1 actual;
       if (i < tam1 && (j == tam2 || pComp(pVect1[i], pVect2[j]))) {
           actual = pVect1[i++];
       } else {
            actual = pVect2[j++];
       }

       if (k == 0 || (actual != temp[k - 1])) {
           temp[k++] = actual;
       }
    }

    nElem = k;
    rOutput = new int[nElem];
    for (auto m = 0; m < nElem; m++) rOutput[m] = temp[m];
    delete[] temp;
}