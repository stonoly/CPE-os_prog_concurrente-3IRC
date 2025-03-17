/* Fichier: greater.c
* Write a program Largest number
* autor: Pierre MOLY
* Exercice 1
*/

#include "greater.h"

int main(int argc, char* argv[]){
    printf("Argc: %d\n", argc);
    printf("Argv[1]: %s\n", argv[1]);
    if (argc != 2){
        puts("Il n'y a pas d'arguments ou trop d'arguments");
        return 1;
    }
    return 0;
}