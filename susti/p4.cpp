#include <iostream>
#include <fstream>
using namespace std;

struct Producto {
    int codigo;
    char nombre[50];
    double precio;
    int stock;
};

void registrarProducto (const char* nomArchivo) {
    ofstream archivo(nomArchivo, ios::binary | ios::app);
    if (!archivo) return;

    Producto p;
    cout << "Codigo: "; cin >> p.codigo;
    cin.ignore();
    cout << "Nombre: "; cin.getline(p.nombre, 50);
    cout << "Precio: "; cin >> p.precio;
    cout << "Stock: "; cin >> p.stock;

    archivo.write((char*)&p, sizeof(Producto));
    archivo.close();
}

void mostrarProductos (const char* nomArchivo) {
    ifstream archivo(nomArchivo, ios::binary);
    if(!archivo) {
        cout << "Archivo no encontrado. " << endl;
        return;
    }

    Producto p;
    while (archivo.read((char*)&p, sizeof(Producto))) {
        cout << "ID: " << p.codigo << " | " << p.nombre
             << " | Precio: " << p.precio << " | Stock: " << p.stock << endl;
    }
    archivo.close();
}

void actualizarStock (const char* nomArchivo, int codBusq) {
    fstream archivo (nomArchivo, ios::binary | ios::in | ios::out);
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

int main() {
    int op, cod;
    const char* inventario = "datos.bin";

    do {
        cout << "\n1. Registrar\n2. Actualizar Stock\n3. Mostrar\n4. Salir\nOpcion: ";
        cin >> op;
        switch(op) {
            case 1: registrarProducto(inventario); break;
            case 2: 
                cout << "Codigo a buscar: "; cin >> cod;
                actualizarStock(inventario, cod); break;
            case 3: mostrarProductos(inventario); break; 
        }
    } while (op != 4);

    return 0;
}