#include "validar.h"
#include <cctype>
int EsNombreValido(char *p){
    if(*p == '\0'){
        return 1;
    }
    if(!isalpha(*p) && *p != '_'){
        return 1;
    }

    p++;
    int posicion = 1;
    while(*p != '\0'){
        posicion++;
        if(*p == ' '){
            return posicion;
        }

        if(!isalnum(*p) && *p != '_'){
            return posicion;
        }
        if(*p == '_' && *(p + 1) == '_'){
            return posicion;
        }
        p++;
    }
    return 0;

}