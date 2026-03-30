#include <iostream>
#include <cstring>
using namespace std;

struct HistorialEntrada {
    int id;
    string url;
    string titulo;
    string fecha;
    string hora;
};

const int MAX_ENTRADAS = 100;

HistorialEntrada historial[MAX_ENTRADAS];
int numEntradas = 0; // Contador de entradas actuales
int siguienteId = 1; // Contador para IDs automáticos

void mostrarMenu();
void agregarEntrada();
void mostrarHistorial();
void eliminarEntrada();
void buscarPorURL();
void limpiarHistorial();
bool estaLleno();
bool estaVacio();

int main() {
    int opcion;
    
    cout << "=== HISTORIAL DE NAVEGACION WEB ===" << endl;
    
    do {
        mostrarMenu();
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer
        
        switch(opcion) {
            case 1:
                agregarEntrada();
                break;
            case 2:
                mostrarHistorial();
                break;
            case 3:
                eliminarEntrada();
                break;
            case 4:
                buscarPorURL();
                break;
            case 5:
                limpiarHistorial();
                break;
            case 0:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion no valida!" << endl;
        }
        cout << endl;
    } while(opcion != 0);
    
    return 0;
}



bool estaLleno() {
    return numEntradas >= MAX_ENTRADAS;
}

bool estaVacio() {
    return numEntradas == 0;
}

void mostrarMenu() {
    cout << "\n--- HISTORIAL DE NAVEGACION WEB ---" << endl;
    cout << "1. Agregar entrada al historial" << endl;
    cout << "2. Mostrar historial completo" << endl;
    cout << "3. Eliminar una entrada por ID" << endl;
    cout << "4. Buscar visitas por URL" << endl;
    cout << "5. Limpiar historial completo" << endl;
    cout << "0. Salir" << endl;
}

void agregarEntrada() {
    if (estaLleno()) {
        cout << "Error: El historial esta lleno (maximo " << MAX_ENTRADAS << " entradas)." << endl;
        return;
    }
    
    // Agregar nueva entrada en la posición actual
    historial[numEntradas].id = siguienteId++;
    
    cout << "Ingrese la URL: ";
    getline(cin, historial[numEntradas].url);
    
    cout << "Titulo de la pagina: ";
    getline(cin, historial[numEntradas].titulo);
    
    cout << "Fecha (dd/mm/aaaa): ";
    getline(cin, historial[numEntradas].fecha);
    
    cout << "Hora (hh:mm): ";
    getline(cin, historial[numEntradas].hora);
    
    cout << ">> Entrada agregada con ID: " << historial[numEntradas].id << endl;
    numEntradas++;
}

void mostrarHistorial() {
    if (estaVacio()) {
        cout << "El historial esta vacio." << endl;
        return;
    }
    
    cout << "--- Historial de navegacion ---" << endl;
    for(int i = 0; i < numEntradas; i++) {
        cout << "ID: " << historial[i].id 
             << " | URL: " << historial[i].url 
             << " | Titulo: " << historial[i].titulo 
             << " | Fecha: " << historial[i].fecha 
             << " | Hora: " << historial[i].hora << endl;
    }
}

void eliminarEntrada() {
    if (estaVacio()) {
        cout << "El historial esta vacio." << endl;
        return;
    }
    
    int idEliminar;
    cout << "Ingrese el ID de la entrada a eliminar: ";
    cin >> idEliminar;
    
    bool encontrado = false;
    for(int i = 0; i < numEntradas; i++) {
        if(historial[i].id == idEliminar) {
            encontrado = true;
            // Desplazar todas las entradas siguientes una posición hacia atrás
            for(int j = i; j < numEntradas - 1; j++) {
                historial[j] = historial[j + 1];
            }
            numEntradas--;
            cout << ">> Entrada eliminada exitosamente." << endl;
            break;
        }
    }
    
    if(!encontrado) {
        cout << "No se encontro ninguna entrada con ID: " << idEliminar << endl;
    }
}

void buscarPorURL() {
    if (estaVacio()) {
        cout << "El historial esta vacio." << endl;
        return;
    }
    
    string urlBuscar;
    cout << "Ingrese URL a buscar: ";
    getline(cin, urlBuscar);
    
    bool encontrado = false;
    cout << "Resultados encontrados:" << endl;
    
    for(int i = 0; i < numEntradas; i++) {
        // Buscar si la URL contiene el texto buscado
        if(historial[i].url.find(urlBuscar) != string::npos) {
            cout << "ID: " << historial[i].id 
                 << " | URL: " << historial[i].url 
                 << " | Titulo: " << historial[i].titulo 
                 << " | Fecha: " << historial[i].fecha 
                 << " | Hora: " << historial[i].hora << endl;
            encontrado = true;
        }
    }
    
    if(!encontrado) {
        cout << "No se encontraron entradas con la URL: " << urlBuscar << endl;
    }
}

void limpiarHistorial() {
    if (estaVacio()) {
        cout << "El historial ya esta vacio." << endl;
        return;
    }
    
    char confirmacion;
    cout << "¿Estás seguro que deseas borrar todo el historial? (s/n): ";
    cin >> confirmacion;
    
    if(confirmacion == 's' || confirmacion == 'S') {
        numEntradas = 0;
        siguienteId = 1; // Reiniciar contador de IDs
        cout << ">> Historial limpiado correctamente." << endl;
    } else {
        cout << "Operacion cancelada." << endl;
    }
}