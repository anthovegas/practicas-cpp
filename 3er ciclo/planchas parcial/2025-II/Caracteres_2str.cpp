#include <iostream>
#include <string>

using namespace std;

int main() {
    string entrada;
    cout << "Entrada: ";
    getline(cin, entrada);

    string resultado = ""; // Aquí construiremos la cadena final
    bool ultimoFueEspacio = false;

    for (int i = 0; i < entrada.length(); i++) {
        char c = entrada[i];

        // b. Convertir a minúscula manualmente (sin tolower)
        if (c >= 'A' && c <= 'Z') {
            c += 32;
        }

        // a. Manejo de espacios duplicados
        if (c == ' ') {
            if (ultimoFueEspacio) {
                continue; // Si ya hubo un espacio, ignoramos este y pasamos al siguiente
            }
            ultimoFueEspacio = true;
        } else {
            ultimoFueEspacio = false;
        }

        // c. Reemplazo de vocales con el operador += (lo más básico)
        if (c == 'a') {
            resultado += "1";
        } else if (c == 'e') {
            resultado += "5";
        } else if (c == 'i') {
            resultado += "9";
        } else if (c == 'o') {
            resultado += "15";
        } else if (c == 'u') {
            resultado += "21";
        } else {
            // Si no es vocal, simplemente agregamos el caracter (o el espacio validado)
            resultado += c;
        }
    }

    cout << "Salida: \"" << resultado << "\"" << endl;

    return 0;
}