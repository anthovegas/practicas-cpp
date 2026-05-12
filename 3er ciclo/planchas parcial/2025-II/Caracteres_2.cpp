#include <iostream>

using namespace std;

int main() {
    // Definimos un buffer suficientemente grande para permitir la expansión
    char str[1000];
    
    cout << "Entrada: ";
    cin.getline(str, 1000);

    // --- FASE 1: Minúsculas y eliminación de espacios duplicados ---
    // Usamos dos punteros (lectura y escritura) sobre el mismo arreglo.
    char *read = str;
    char *write = str;
    bool ultimoFueEspacio = false;

    while (*read != '\0') {
        char actual = *read;

        // b. Convertir todas las letras a minúsculas
        if (actual >= 'A' && actual <= 'Z') {
            actual += 32;
        }

        // a. Eliminar espacios duplicados
        if (actual == ' ') {
            if (!ultimoFueEspacio) {
                *write = actual;
                write++;
                ultimoFueEspacio = true;
            }
        } else {
            *write = actual;
            write++;
            ultimoFueEspacio = false;
        }
        read++;
    }
    *write = '\0'; // Marcamos el nuevo final de la cadena procesada

    // --- FASE 2: Reemplazo de vocales con expansión de memoria ---
    // c. Las vocales 'o' (15) y 'u' (21) ocupan 2 caracteres, por lo que la cadena crece.
    
    int longitudActual = 0;
    int espacioExtra = 0;
    char *p = str;
    
    // Contamos cuánto espacio extra necesitamos para no desbordar
    while (*p != '\0') {
        if (*p == 'o' || *p == 'u') {
            espacioExtra++;
        }
        longitudActual++;
        p++;
    }

    // d. Modificamos el arreglo original (de atrás hacia adelante)
    // Esto es clave: si empezamos desde el principio, sobrescribiríamos
    // los caracteres que aún no hemos leído al expandir 'o' o 'u'.
    char *pViejo = str + longitudActual;          // Puntero al '\0' actual
    char *pNuevo = str + longitudActual + espacioExtra; // Puntero a la nueva posición del '\0'
    
    while (pViejo >= str) {
        if (*pViejo == 'a') {
            *pNuevo = '1';
        } else if (*pViejo == 'e') {
            *pNuevo = '5';
        } else if (*pViejo == 'i') {
            *pNuevo = '9';
        } else if (*pViejo == 'o') {
            *pNuevo = '5';
            *(--pNuevo) = '1'; // Escribe el '1' antes del '5'
        } else if (*pViejo == 'u') {
            *pNuevo = '1';
            *(--pNuevo) = '2'; // Escribe el '2' antes del '1'
        } else {
            *pNuevo = *pViejo; // Copia caracteres normales y el '\0'
        }
        pViejo--;
        pNuevo--;
    }

    cout << "Salida: \"" << str << "\"" << endl;

    return 0;
}