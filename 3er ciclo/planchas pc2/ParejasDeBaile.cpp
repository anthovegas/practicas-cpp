#include <iostream>
#include <string>
using namespace std;

using T = int;

void CrearMatriz (T *&a, int n) {
    a = new T[n];
    for (int i = 0; i < n; ++i) a[i] = 0;
}

void EliminarMatriz (T *&a) {
    delete[] a;
    a = nullptr;
}

void LlenadoDeDatos (T *a, int inicio, int fin) {
    for (int i = inicio; i <= fin; ++i) a[i]++;
}

int CalculoMaximo (T *a, T *b, int n) {
    int max = 0;
    for (int i = 1; i < n; ++i) {
        int min = (a[i] < b[i]) ? a[i]: b[i];
        int total = min * 2;
        if (total > max) max = total;
    }
    return max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    T* mujeres;
    T* hombres;
    CrearMatriz (mujeres, 367);
    CrearMatriz (hombres, 367);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 0; i < n; ++i) {
        string genero; 
        int inicio, fin;
        cin >> genero >> inicio >> fin;
        if (genero == "M") 
            LlenadoDeDatos(hombres, inicio, fin);
        else if (genero == "F") 
            LlenadoDeDatos(mujeres, inicio, fin);
    }

    int max = CalculoMaximo (mujeres, hombres, 367);
    cout << max;

    EliminarMatriz(mujeres);
    EliminarMatriz(hombres);

    return 0;
}