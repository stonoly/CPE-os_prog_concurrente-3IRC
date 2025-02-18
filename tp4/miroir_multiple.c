/* Fichier: miroir_multiple.c
* Takes a character string in arguments and displays it upside down
* auteur: Pierre MOLY
* Exercice 1
*/

#include "miroir.h"

int main(int argc, char* argv[]){
    if (argc == 1){
        puts("Il n'y a pas d'arguments");
        return 1;
    }else {
        for (int j = 1; j < argc; j++){
            for (int i = strlen(argv[j]) - 1; 0 <= i; i--){
                printf("%c", argv[j][i]);
            }
            printf(" ");
        }
        printf("\n");
        return 0;
    }
}