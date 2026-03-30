#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

void insertarLista (Nodo*& Lista, int n) {
    Nodo* nuevo = new Nodo();
    nuevo->dato  = n;
    nuevo->siguiente = nullptr;

    if ( Lista == nullptr) {
        Lista = nuevo;
    } else {
        Nodo* aux = Lista;
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}

Nodo* combinarLista(Nodo* L1, Nodo* L2) {
    Nodo ficticio;
    ficticio.siguiente = nullptr;
    Nodo* cola = &ficticio;

    while ( L1 != nullptr || L2 != nullptr) {
        if ( L1!= nullptr ) {
            cola->siguiente = L1;
            cola = L1;
            L1 = L1-> siguiente;
        }
        if ( L2!= nullptr ) {
            cola->siguiente = L2;
            cola = L2;
            L2 = L2-> siguiente;
        }
    }
    return ficticio.siguiente;
}

void mostrarLista(Nodo* lista){
    while (lista != nullptr){
        cout << lista->dato << " -> ";
        lista = lista->siguiente;
    }
    cout << "NULL" << endl;
}

int main() {
    Nodo* lista1 = nullptr;
    Nodo* lista2 = nullptr;
    int n1, n2, valor;

    cout << "Ingrese la cantidad de elementos para la lista 1: ";
    cin >> n1;
    cout << "Ingrese los datos de lista1: " << endl;
    for (int i = 0; i < n1; ++i) {
        cin >> valor;
        insertarLista(lista1, valor);
    }
    cout << "Ingrese la cantidad de elementos para la lista 2: ";
    cin >> n2;
    cout << "Ingrese los datos de lista2: " << endl;
    for (int i = 0; i < n2; ++i) {
        cin >> valor;
        insertarLista(lista2, valor);
    }

    Nodo* resultados = combinarLista(lista1, lista2);
    cout << "Lista combinada: ";
    mostrarLista(resultados);

    return 0;
}
