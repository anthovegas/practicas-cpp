#include <iostream>
using namespace std;

void suma_arr(int arr[], int tamaño, int nivel){
    cout << "Nivel "<<nivel<<": ";
    for (int i=0; i<tamaño; i++){
        cout << arr[i]<<" ";
    }
    cout << endl;
    if (tamaño==1) return;

    int* arr2 = new int [tamaño-1];
    for (int i=0; i<tamaño-1; i++){
        arr2[i] = arr[i]+ arr[i+1];
    }
    suma_arr(arr2, tamaño-1, nivel+1);

    delete [] arr2;

}


int main(){
    cout<<"Ingrese el tamaño del vector: ";
    int N;
    cin>>N;
    int arr[N];
    cout << "Ingrese los valores del vector: ";
    for (int i=0; i<N; i++){
        cin>>arr[i];
    }
    suma_arr(arr, N, 0);
    return 0;
}