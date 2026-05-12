#include <iostream>
#include "EsNombreValido.h"
using namespace std;

int CaracteresValidos (TP *p) {
    for (int i = 0; p[i] != '\0'; ++i) {
        if (!((p[i] >= 'a' && p[i] <= 'z') || 
              (p[i] >= 'A' && p[i] <= 'Z') || 
              (p[i] >= '0' && p[i] <= '9') || 
               p[i] == '_')) return i + 1;
    }
    return -1;
}

int CaracterInicial (TP *p) {
    if (p[0] == '\0') return 0;

    if ((p[0] >= 'a' && p[0] <= 'z') ||
        (p[0] >= 'A' && p[0] <= 'Z') || p[0] == '_') {
        return -1;
    }
    return 0;
}

int Dosguiones (TP *p) {
    for (int i = 0; p[i] != '\0' && p[i + 1] != '\0'; ++i)
        if (p[i] == '_' && p[i + 1] == '_') return i + 1;
    return -1;
}

int EsNombreValido (TP *p) {
    int r;

    if (CaracterInicial(p) != -1) return 1;

    r = CaracteresValidos(p);
    if (r != -1) return r;

    r = Dosguiones(p);
    if (r != -1) return r;
    
    return 0;
}