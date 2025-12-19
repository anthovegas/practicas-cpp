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
