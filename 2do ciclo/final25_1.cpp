#include <iostream>
using namespace std;

struct Pagina {
private:
    char* url;
    int tiempo;
public:
    void visitarPagina(const char* url, int tiempo){
        char new = url[i];
    }
    void mostrarHistorial() {
        cout << "Historial de navegación" << endl;
        for(int i = 1; i < n; i++){
            cout << i << ". URL: " << url[i] << " | Tiempo de visita: " << tiempo << "s" << endl;
        }
    }
    bool eliminarPagina(const char* url){
        if(strcmp(url,url[n]) == 0){
            return true;
        } else {
            return false;
        }
    }

    void liberarHistorial(){
        cout << "Eliminando página: " << url[n] << endl;
        delete[] url;
    }
};

int main() {
    
}