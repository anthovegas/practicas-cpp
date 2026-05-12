#include "Caracteres.h"
#include <fstream>
using namespace std;

void DesplazarDerecha(C* cadena, int desde, int pasos) {
    int n = 0;
    while (cadena[n] != '\0') n++;
    for (int i = n; i >= desde; i--) {
        cadena[i + pasos] = cadena[i];
    }
}

void DesplazarIzquierda(C* cadena, int desde) {
    int i = desde;
    while (cadena[i] != '\0') {
        cadena[i] = cadena[i + 1];
        i++;
    }
}

void EliminarEspacios(C* cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] == ' ' && cadena[i+1] == ' ') {
            DesplazarIzquierda(cadena, i);
            i--;
        }
    }
}

void Minusculas(C* cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] >= 'A' && cadena[i] <= 'Z') {
            cadena[i] += ('a' - 'A');
        }
    }
}

void VocalesNum(C* cadena, int capacidad) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        C actual = cadena[i];
        if (actual == 'a') { cadena[i] = '1'; }
        else if (actual == 'e') { cadena[i] = '5'; }
        else if (actual == 'i') { cadena[i] = '9'; }
        else if (actual == 'o' || actual == 'u') {
            DesplazarDerecha(cadena, i + 1, 1); 
            if (actual == 'o') {
                cadena[i] = '1'; cadena[i+1] = '5';
            } else {
                cadena[i] = '2'; cadena[i+1] = '1';
            }
            i++;
        }
    }
}

void Imprimir(C* cadena, OS& os) {
    os << "\"" << cadena << "\"" << endl;
}

void ProcesarConString(S& palabra) {
    S temporal = "";
    
    int i = 0;
    while (palabra[i] != '\0') {
        C actual = palabra[i];

        if (actual >= 'A' && actual <= 'Z') {
            actual = actual + ('a' - 'A');
        }

        if (actual == ' ') {
            int ultimoIndex = 0;
            while(temporal[ultimoIndex] != '\0') ultimoIndex++;
            
            if (ultimoIndex == 0 || temporal[ultimoIndex - 1] != ' ') {
                temporal += actual;
            }
        } 
        else if (actual == 'a') { temporal += '1'; }
        else if (actual == 'e') { temporal += '5'; }
        else if (actual == 'i') { temporal += '9'; }
        else if (actual == 'o') { temporal += "15"; }
        else if (actual == 'u') { temporal += "21"; }
        else {
            temporal += actual;
        }
        i++;
    }
    palabra = temporal;
}

void ImprimirString(S& palabra, OS& os) {
    int i = 0;
    while (palabra[i] != '\0') {
        os << palabra[i];
        i++;
    }
    os << endl;
}

int main() {
    C miCadena[200];
    cout << "Ingresa cadena (para char): ";
    cin.getline(miCadena, 200);
    
    EliminarEspacios(miCadena);
    Minusculas(miCadena);
    VocalesNum(miCadena, 200);

    cout << "Resultado en consola: ";
    Imprimir(miCadena, cout);

    S miFrase;
    cout << "Ingresa una frase: ";
    getline(cin, miFrase);

    ProcesarTodoString(miFrase);

    cout << "Resultado: ";
    ImprimirString(miFrase, cout);

    return 0;
}