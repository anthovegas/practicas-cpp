#include <iostream>
#include "EsNombreValido.h"
using namespace std;

int main() {
    // Pruebas
    cout << "mi_variable1: " << EsNombreValido((char*)"mi_variable1") << endl; // 0
    cout << "1variable: "    << EsNombreValido((char*)"1variable") << endl;    // 1
    cout << "var name: "     << EsNombreValido((char*)"var name") << endl;     // 4
    cout << "var__name: "    << EsNombreValido((char*)"var__name") << endl;    // 4

    return 0;
}

//g++ EsNombreValido.cpp main-EsNombreValido.cpp -o esnombrevalido.exe  
//./esnombrevalido.exe