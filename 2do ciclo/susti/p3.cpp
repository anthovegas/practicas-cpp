#include <iostream>
using namespace std;

void MatrizAgregarNum (int *&Matriz, int valor, int &n) {
    int *temp = new int[n+1];
    for (int i = 0; i < n; ++i){
        temp[i] = Matriz[i];
    }
    temp[n] = valor;
    if (Matriz != nullptr) delete[] Matriz;
    Matriz = temp;
    n++;

}

bool esParada (int *Matriz, int valor, int n, int &m1, int &m2) {
    int count = 0;
    for(int i = 0; i < n; ++i) {
        if (valor % Matriz[i] == 0) {
            if(count == 0) m1 = Matriz[i];
            if(count == 1) m2 = Matriz[i]; 
            count++;
        }
    }
    return (count >= 2);
}

int main(){
    int* Matriz = nullptr;
    int n = 0;
    int valor, m1, m2;
    cout << "Ingrese numeros enteros positivos: ";
    
    while (cin >> valor && valor > 0) {
        if (n >= 2 && esParada(Matriz, valor, n, m1, m2)) {
            cout << "El numero " << valor << " es multiplo de " << m1 << " y " << m2;
            break;
        }
        MatrizAgregarNum(Matriz, valor, n);
    }

    cout << "\nVector Final: ";
    for (int i = 0; i < n; ++i) {
        cout << Matriz[i] << " ";
    }
    cout << endl;

    if (Matriz != nullptr) delete[] Matriz;
    
    return 0;
}