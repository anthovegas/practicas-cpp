#include <iostream>
#include "validar.h"
using namespace std;
int main(){
    char entrada[100];
    cout << "\nIngrese un nombre de variable para validar: ";
    cin.getline(entrada, 100);

    int resultado = EsNombreValido(entrada);
    if(resultado == 0){
        cout << "Nombre de variable VALIDO" << endl;
    } else {
        cout << "Nombre de varible INVALIDO en la posicion: " << resultado << endl;
    }
    return 0;
}