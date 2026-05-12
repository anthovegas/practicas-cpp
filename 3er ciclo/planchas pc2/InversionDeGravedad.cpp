#include <iostream>
#include <string>
#include <random> // Necesario para mt19937
using namespace std;

using ContainerRange = int;
std::random_device rd;
std::mt19937 gen(rd());

template <typename T>
void intercambiar (T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
ContainerRange particionar (T arr[], ContainerRange first, ContainerRange last) {
    //usando la sugerencia
    uniform_int_distribution<ContainerRange> distr(first, last);
    int random_index = distr(gen);
    intercambiar(arr[random_index], arr[last]); //Se mueve el aleatorio al final
    
    auto pivote = arr[last];
    auto i = (first - 1);

    for (auto j = first; j <= last - 1; ++j) {
        if (arr[j] < pivote) {
            ++i;
            intercambiar (arr[i], arr[j]);
        }
    }
    intercambiar(arr[i + 1], arr[last]);
    return (i + 1);
}

template <typename T>
void QuickSort (T arr[], ContainerRange first, ContainerRange last) {
   if (first < last) {
        auto pivot = particionar(arr, first, last);
        QuickSort(arr, first, pivot - 1);
        QuickSort(arr, pivot + 1, last);
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    //Para que n y t puedan llegar a 10^5

    int n;
    cin >> n;

    ContainerRange* arr = new ContainerRange[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];

    QuickSort(arr, 0, n - 1);
    
    for (int i = 0; i < n; ++i) 
        cout << arr[i] << (i == n - 1 ? "" : " "); //para evitar el último espacio

    delete[] arr;
    return 0;
}