#include <iostream>
#include <fstream>
using namespace std;

struct Producto {
    int codigo;
    char nombre[50];
    double precio;
    int stock;
};

void Registrar(const char* nomArchivo) {
    ofstream archivo(nomArchivo, ios::binary);
    if (!archivo) return;

    Producto p;
    cout << "Ingrese los datos: " << endl;
    cout << "Nombre: "; cin >> p.nombre;
    cout << "Codigo: "; cin >> p.codigo;
    cout << "Precio: "; cin >> p.precio;
    cout << "Stock: "; cin >> p.stock;

    archivo.write((char*)&p, sizeof(Producto));
    archivo.close();
}

void Actualizar (const char* nomArchivo, int codBusq) {
    fstream archivo(nomArchivo, ios::binary);
    if (!archivo) return;

    Producto p;
    bool encontrado = false;

    while (archivo.read((char*)&p, sizeof(Producto))) {
        if (p.codigo == codBusq) {
            cout << "Nuevo stock para " << p.nombre << ": ";
            cin >> p.stock;

            archivo.seekp((int)archivo.tellg() - sizeof(Producto));
            archivo.write((char*)&p, sizeof(Producto));

            encontrado = true;
            break;
        }
    }
    if (!encontrado) cout << "Producto no hallado." << endl;
    archivo.close();
}

void mostrarProducto(const char* nomArchivo) {
    ifstream archivo (nomArchivo, ios::binary);
    if(!archivo) {
        cout << "Archivo no encontrado." << endl;
        return;
    }

    Producto p;
    while (archivo.read((char*)&p, sizeof(Producto))) {
        cout << "ID: " << p.codigo << " | " << p.nombre
             << " | Precio: " << p.precio << " | Stock: " << p.stock << endl;
    }
    archivo.close();
}


int main() {
    int op, cod;
    const char* inventario = "datos.bin";

    do {
        cout << "\n1. Registrar\n2. Actualizar Stock\n3. Mostrar\n4. Salir\nOpcion: ";
        cin >> op;
        switch(op) {
            case 1: Registrar(inventario); break;
            case 2: cout << "Codigo a buscar: "; cin >> cod; Actualizar(inventario, cod); break;
            case 3: mostrarProducto(inventario); break;
        }
    } while (op != 4);
    return 0;
}