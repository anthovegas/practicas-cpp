//Lea datos desde un vector y realice la búsqueda binaria.
//a) Para datos numéricos
//b) Para cadenas


//Desactivar el texto fantasma (inline suggestions) — método recomendado:
//Esto desactiva las sugerencias en línea (ghost text) que muchas extensiones usan.
//Abre los Ajustes (Ctrl+,).
//En el cuadro de búsqueda escribe: Inline Suggest
//Desmarca la casilla "Editor: Inline Suggest" (o en español "Editor: Sugerencia en línea").
//Alternativa (editar settings.json): abre el archivo de configuración (Command Palette → Preferences: Open Settings (JSON)) y añade:
//"editor.inlineSuggest.enabled": false
//Efecto: deja de mostrarse el texto predictivo en línea de cualquier proveedor de sugerencias.
#include <iostream>
#include <cstring>
using namespace std;
void ordernarNumeros(int *arr, int tamaño){
    for(int i=0;i<tamaño-1;++i){
        for(int j=0; j<tamaño-1-i; ++j){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
// _strcmp_ es una función de programación que compara dos cadenas de texto
// carácter por carácter basándose en sus valores ASCII. Devuelve \(0\) si
// las cadenas son idénticas, un valor positivo si la primera cadena es "mayor" 
//que la segunda, y un valor negativo si es "menor". 

//strcpy es una función de la biblioteca estándar de C/C++ utilizada para copiar
// el contenido de una cadena de caracteres (string) a otra. Esta función toma dos
// argumentos: la cadena de destino (donde se copiará) y la cadena de origen 
//(la que se copiará). Para usar strcpy, es necesario incluir la cabecera 
//<string.h> (o <cstring> en C++). 
void ordernarCademas(char arr[][100], int tamaño){
    for(int i=0; i<tamaño-1;++i){
        for (int j = 0; j<tamaño-1-i; j++)
        {
            if(strcmp(arr[j],arr[j+1])>0){
                char temp[100];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
        }
        
    }

}

int busquedaBinariaNumeros(int* arr, int tamaño, int valor){
    int izquierda=0;
    int derecha= tamaño-1-;

    while(izquierda <= derecha){
        int medio = izquierda + (izquierda - derecha)/2;


    }
}

