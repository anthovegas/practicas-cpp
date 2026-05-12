#include <iostream>
#include <string>
using namespace std;

template <typename T>
void merge(T* arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    T* L = new T[n1];
    T* R = new T[n2];

    for (auto i = 0; i < n1; i++) L[i] = arr[l + i];
    for (auto j = 0; j < n2; j++) R[j] = arr [m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

template <typename T>
void mergeSort(T* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

template <typename T>
void solve(int n) {
    T*arr = new T[n];
    for (auto i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    for (auto i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    delete[] arr;

}

int main() {
    //Para velocidad
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