#include <iostream>
#include "Sorting.h"
#include "Array.h"
using namespace std;

int main() {
    int vec1[] = {7, 2, 5, 10};
    int vec2[] = {5, 2, 18, 1, 0, 14, 7, 3, 6};
    
    QuickSort(vec1, 4, asc);
    QuickSort(vec2, 9, asc);
    
    int *resultado = nullptr, tam;
    Merge(vec1, 4, vec2, 9, resultado, tam, asc);
    PrintArray(vec1, 4, cout);
    PrintArray(vec2, 9, cout);

    cout << "Resultado: ";
    PrintArray(resultado, tam, cout);
    DestroyArray(resultado);
    return 0;
}