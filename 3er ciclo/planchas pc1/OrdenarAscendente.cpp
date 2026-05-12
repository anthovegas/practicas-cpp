#include <iostream>
#include "OrdenarAscendente.h"

void intercambiar (T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

void QuickSortAscendenteRecursivo(T *pArray, int n) {
    if (n <= 1) return;
    T pivot = pArray[n/2];
    int i = 0, j = n - 1;

    while(i <= j) {
        while(pArray[i] < pivot) i++;
        while(pArray[j] > pivot) j--;

        if (i <= j) {
            intercambiar(pArray[i], pArray[j]);
            i++;
            j--;
        }
    }

    QuickSortAscendenteRecursivo(pArray, j + 1);
    QuickSortAscendenteRecursivo(pArray + i, n - i);
}

void PrintArray(T *pArray, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << pArray[i] << " ";
    }
    std::cout << std::endl;
}

int frecuenciacontador (T* arr, int n, T num) {
    int count = 0;
    for (auto i = 0; i < n; i++) {
        if (arr[i] == num) {
            count++;
        }
    }
    return count;
}

void OrdenarRecursivoPorFrecuenciaAscendente(T *pArray, int n) {
    int* count = new int[n];
    for (auto i = 0; i < n; i++) {
        count[i] = frecuenciacontador(pArray, n, pArray[i]);
    }

    for (auto i = 0; i < n - 1; i++) {
        for (auto j = 0; j < n - i - 1; j++) {
            if (count[j] > count[j + 1]) {
                intercambiar(count[j], count[j + 1]);
                intercambiar(pArray[j], pArray[j + 1]);
            } else if (count[j] == count[j + 1] ) {
                if (pArray[j] > pArray[j + 1]) {
                    intercambiar(pArray[j], pArray[j + 1]);
                }
            }
        }
    }

    delete[] count;
}