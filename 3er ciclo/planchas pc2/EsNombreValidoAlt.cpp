#include <iostream>
#include "EsNombreValido.h"
#include <cctype>   // Para isalnum, isdigit, etc.
#include <cstring>  // Para manejar la cadena si fuera necesario

using namespace std;

// Función solicitada
int EsNombreValido(char *p) {
    int i = 0;

    // Caso especial: Cadena vacía (opcional, pero buena práctica)
    if (p[0] == '\0') return 1; 

    while (p[i] != '\0') {
        char actual = p[i];
        char siguiente = p[i + 1];

        // REGLA B: No puede comenzar con un número
        if (i == 0 && isdigit(actual)) {
            return 1; // Error en la posición 1
        }

        // REGLA A y C: Solo letras, dígitos y guion bajo (esto excluye espacios)
        if (!isalnum(actual) && actual != '_') {
            return i + 1; // Retorna la posición humana (índice + 1)
        }

        // REGLA D: No puede tener dos guiones bajos seguidos (__)
        if (actual == '_' && siguiente == '_') {
            return i + 1; // El error empieza en el primer guion de la pareja
        }

        i++;
    }

    return 0; // Si llegó aquí, todo es válido
}

int main() {
    // Pruebas
    cout << "mi_variable1: " << EsNombreValido((char*)"mi_variable1") << endl; // 0
    cout << "1variable: "    << EsNombreValido((char*)"1variable") << endl;    // 1
    cout << "var name: "     << EsNombreValido((char*)"var name") << endl;     // 4
    cout << "var__name: "    << EsNombreValido((char*)"var__name") << endl;    // 4

    return 0;
}

//g++ EsNombreValidoAlt.cpp -o esnombrevalidoAlt.exe  
//./esnombrevalidoAlt.exe