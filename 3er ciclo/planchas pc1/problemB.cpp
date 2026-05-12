#include <iostream>
#include <string>
#include <random> // pivote aleatorio
using namespace std;

//Mersenne Twister
mt19937 mt(1337);

template <typename T>
void intercambiar(T& a, T& b) {
    T temporal = a;
    a = b;
    b = temporal;
}

template <typename T>
void quickSort(T* arr, int left, int right) {
    if (left >= right) return;

    uniform_int_distribution<int> dist(left, right);
    int pivotIndex = dist(mt);
    intercambiar(arr[pivotIndex], arr[right]);

    T pivot = arr[right];
    int i = left;

    for (auto j = left; j < right; j++) {
        if (arr[j] < pivot) {
            intercambiar(arr[i], arr[j]);
            i++;
        }
    }
    intercambiar(arr[i], arr[right]);

    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

template <typename T>
void solve(int n) {
    T* arr = new T[n];
    for (auto i = 0; i < n; i++) cin >> arr[i];

    quickSort(arr, 0, n - 1);

    for (auto i = 0; i < n; i++) cout << arr[i] << " ";
    delete[] arr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if(!(cin >> t)) return 0;

    while (t--) {
        string datatype;
        int n;
        cin >> datatype >> n;

        if (datatype == "int") solve<int>(n);
        else if (datatype == "char") solve<char>(n);
        else if (datatype == "long") solve<long long>(n);
        else if (datatype == "string") solve<string>(n);
    }
    return 0;
}
