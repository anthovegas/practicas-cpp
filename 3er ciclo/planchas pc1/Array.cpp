#include "Array.h"

void PrintArray(int *pArray, int n, std::ostream &os) {
    os << "[ ";
    for (int i = 0; i < n; i++) {
        os << pArray[i] << " ";
    }
    os << " ]" << std::endl;
}

void DestroyArray(int *&pArray) {
    if (pArray != nullptr) {
        delete[] pArray;
        pArray = nullptr; // Estado seguro
    }
}