#include <iostream>
#include "Alfabeto.h"
using namespace std;

int main() {
    cout << "Cuantos caracteres desea desplazar (entre 1 y 26): ";
    int n;
    cin >> n;

    cout << "Ingrese una frase para cifrar: ";
    char frase[100];
    cin.ignore();
    cin.getline(frase, 100);

    cout << "Vector original: "<<endl;
    char alfabeto[27];
    Alfabeto(alfabeto);

    cout << "Vector reordenado: " << endl;
    char alfabetoDesplazado[27];
    AlfabetoDesplazado(alfabetoDesplazado, n);

    cout << "Frase cifrada: " << endl;
    CifrarFrase(frase, alfabetoDesplazado);
    
    cout << "Ingrese una frase para descifrar: ";
    char fraseCifrada[100];
    cin.getline(fraseCifrada, 100);

    cout << "Frase descifrada: " << endl;
    DescifrarFrase(fraseCifrada, alfabetoDesplazado);

    return 0;
}

