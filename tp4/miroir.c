/* Fichier: miroir.c
* Takes a character string in argument and displays it upside down
* auteur: Pierre MOLY
* Exercice 1
*/

#include "miroir.h"

int main(int argc, char* argv[]){
    if (argc != 2){
        puts("Il n'y a pas le bon nombre d'arguments");
        return 1;
    }else {
        for (int i = strlen(argv[1]) - 1; 0 <= i; i--){
            printf("%c", argv[1][i]);
        }
        printf("\n");
        return 0;
   }
}