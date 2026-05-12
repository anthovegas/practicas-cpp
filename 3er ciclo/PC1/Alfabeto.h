#ifndef __ALFABETO_H__
#define __ALFABETO_H__

char* Alfabeto(char *arr); 
char* AlfabetoDesplazado(char *arr, int n); //entre 1 y 26
char* CifrarFrase(char *frase, char *alfabetoDesplazado);
char* DescifrarFrase(char *fraseCifrada, char *alfabetoDesplazado);
void PrintArray(char *arr);

#endif // __ALFABETO_H__