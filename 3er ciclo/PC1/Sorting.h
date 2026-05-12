#ifndef __SORTING_H__
#define __SORTING_H__

using ContainerRange = int;

template <typename T>
void intercambiar(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
bool Mayor(T a, T b) {
    return a > b;
}

template <typename T>
bool Menor(T a, T b) {
    return a < b;
}

template <typename T, typename Func>
void BurbujaRecursivo(T arr[], ContainerRange n, Func func) {
    if (n <= 1) return;

    for (auto j = 1; j < n; ++j) {
        if (func(arr[j], arr[0])) {
            intercambiar(arr[0], arr[j]);
        }
    }
    BurbujaRecursivo(arr + 1, n - 1, func);
}

template <typename T>
void PrintArray(T arr[], int n);

#endif // __SORTING_H__