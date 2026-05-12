#include <iostream>
using namespace std;

using ContainerRange = int;


template <typename T>
void Merge (T arr[], const ContainerRange left, const ContainerRange mid, const ContainerRange right) {
    auto n1 = mid - left + 1;
    auto n2 = right - mid;

    T* L = new T[n1];
    T* R = new T[n2];

    for (auto i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    
    for (auto j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];
    
    auto i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }

    delete[] L;
    delete[] R;

}

template <typename T>
void MergeSort (T arr[], const ContainerRange begin, const ContainerRange end) {
    if (begin < end) {
        ContainerRange mid = begin + (end - begin) / 2;

        MergeSort(arr, begin, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, begin, mid, end);
    }
}

template <typename T>
void OrdLeerImp(int n) {
    T* arr = new T[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];

    MergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i) cout << arr[i] << "\n";

    delete[] arr;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    //Para que n y t puedan llegar a 10^5

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        string datatype;
        int n;
        cin >> datatype >> n;

        if (datatype == "int") OrdLeerImp<int>(n);
        if (datatype == "long") OrdLeerImp<long long>(n); //se usa long long por seguridad
        if (datatype == "char") OrdLeerImp<char>(n);
        if (datatype == "string") OrdLeerImp<string>(n);
    }

    return 0;
}
//g++ MergeTemplate.cpp -o mergetemplate.exe
//./mergetemplate.exe

