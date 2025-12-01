#include <iostream>
#include <string>
using namespace std;

class Contacto {
    private:
        int id;
        string nombre;
        string telefono;
        string email;
    public:
        Contacto(int i, string n, string t, string e){
            id = i;
            nombre = n;
            telefono = t;
            email = e;
        }

        Contacto(){
            id = 0;
            nombre = "";
            telefono = "";
            email = "";
        }

        int getId() { return id; }
        string getNombre() { return nombre; }
        string getTelefono() { return telefono; }
        string getEmail() { return email; }

        void mostrar() {
            cout << "ID: " << id << " | " << nombre
                 << " | Tel: " << telefono << " | Email: " << email << endl;
        }
};

class Agenda {
    private: 
        Contacto* contactos;
        int capacidad;
        int cantidad;
        int siguienteId;

        void redimensionar() {
            int nuevaCapacidad = capacidad * 2;
            Contacto* nuevoArray = new Contacto[nuevaCapacidad];

            for (int i = 0; i < cantidad; i++){
                nuevoArray[i] = contactos[i];
            }

            delete[] contactos;
            contactos = nuevoArray;
            capacidad = nuevaCapacidad;

            cout << "Array redimensionado a capacidad: " << capacidad << endl;
        }

    public:

        Agenda() {
            capacidad = 5;
            cantidad = 0;
            siguienteId = 1;
            contactos = new Contacto[capacidad];
        }

        ~Agenda() {
            delete[] contactos;
        }

        void agregar() {

            if(cantidad >= capacidad){
                redimensionar();
            }

            string nombre, telefono, email;

            cout << "Nombre: ";
            cin.ignore();
            getline(cin, nombre);

            cout << "Telefono: ";
            getline(cin, telefono);

            cout << "Email: ";
            getline(cin, email);

            contactos[cantidad] = Contacto(siguienteId, nombre, telefono, email);
            cantidad++;
            siguienteId++;

            cout << "Contacto agregado! (Total: " << cantidad << ")" << endl;
        }

        void listar() {
            if (cantidad == 0){
                cout << "La agenda está vacía. " << endl;
                return;
            }

            cout << "\n=== LISTA DE CONTACTOS (" << cantidad << ") ===" << endl;
            for (int i = 0; i < cantidad; i++){
                contactos[i].mostrar();
            }
            cout << "Capacidad actual: " << capacidad << endl;
        }

        void buscar() {
            if (cantidad == 0) {
                cout << "La agenda está vacía. " << endl;
                return;
            }

            string nombreBuscado;
            cout << "Nombre a buscar: ";
            cin.ignore();
            getline(cin, nombreBuscado);

            bool encontrado = false;
            for (int i = 0; i < cantidad; i++){
                if (contactos[i].getNombre().find(nombreBuscado) != string::npos) {
                    contactos[i].mostrar();
                    encontrado = true;
                }
            }

            if (!encontrado){
                cout << "No se encontraron contactos." << endl;
            }
        }

        void eliminar() {
            if (cantidad == 0) {
                cout << "La agenda está vacía." << endl;
                return;
            }

            int idEliminar;
            cout << "ID a eliminar: ";
            cin >> idEliminar;

            for (int i = 0; i < cantidad; i++) {
                if (contactos[i].getId() == idEliminar) {
                    for (int j = i; j < cantidad - 1; j++) {
                        contactos[j] = contactos[j + 1];
                    }
                    cantidad--;
                    cout << "Contacto eliminado. " << endl;
                    return;
                }
            }
            cout << "Contacto no encontrado." << endl;
        }
};

void mostrarMenu() {
    cout << "\n=== AGENDA DE CONTACTOS ===" << endl;
    cout << "1. Agregar contacto" << endl;
    cout << "2. Listar contactos" << endl;
    cout << "3. Buscar por nombre" << endl;
    cout << "4. Eliminar contacto" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione: ";
}

int main(){
    Agenda agenda;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch(opcion) {
            case 1: agenda.agregar(); break;
            case 2: agenda.listar(); break;
            case 3: agenda.buscar(); break;
            case 4: agenda.eliminar(); break;
            case 5: cout << "Saliendo..." << endl; break;
            default: cout << "Opción no valida. " << endl;
        }
    } while(opcion != 5);

    return 0;
}
