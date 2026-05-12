#include "Alfabeto.h"
#include <iostream>
using namespace std;

void PrintArray(char *arr) {
    for (auto i = 0; arr[i] != '\0'; ++i) {
        cout << arr[i];
    }
    cout << endl;
}

char* Alfabeto(char *arr) {
    for (auto i = 0; i < 26; ++i) {
        arr[i] = 'A' + i;
    }
    arr[26] = '\0';
    PrintArray(arr);
    return arr;
}

char* AlfabetoDesplazado(char *arr, int n) {
    if (n < 1 || n > 26) {
        cerr << "Error: n debe estar entre 1 y 26." << endl;
        return nullptr;
    }
    for (auto i = 0; i < 26; ++i) {
        int index = 'A' + (i - n) % 26;
        if(index < 'A') {
            index += 26;
        }
        arr[i] = index;
    }
    arr[26] = '\0';
    PrintArray(arr);
    return arr;
}

char* CifrarFrase(char *frase, char *alfabetoDesplazado) {
    for (auto i = 0; frase[i] != '\0'; ++i) {
        if (frase[i] >= 'A' && frase[i] <= 'Z') {
            int index = frase[i] - 'A';
            frase[i] = alfabetoDesplazado[index];
        }
    }
    PrintArray(frase);
    return frase;
}

char* DescifrarFrase( char *fraseCifrada, char *alfabetoDesplazado) {
    for (auto i = 0; fraseCifrada[i] != '\0'; ++i) {
        if (fraseCifrada[i] >= 'A' && fraseCifrada[i] <= 'Z') {
            for (auto j = 0; j < 26; ++j) {
                if (fraseCifrada[i] == alfabetoDesplazado[j]) {
                    fraseCifrada[i] = 'A' + j;
                    break;
                }
            }
        }
    }
    PrintArray(fraseCifrada);
    return fraseCifrada;
}