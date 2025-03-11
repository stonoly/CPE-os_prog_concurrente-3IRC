/* Fichier: counter.c
* Write a program that creates 4 sons. The first son displays the integers from 1 to 50, the second from 51 to 100, the
* third from 101 to 150 and the last from 151 to 200
* auteur: Pierre MOLY
* Exercice 6
*/

#include "counter.h"

int main() {

    int i = 0;
    int limit_compt = 0;

    while(i < 4){
        pid_t pid_fils = fork();
        if (pid_fils == 0){

            switch (i) {
                case 0:
                    limit_compt = 50;
                    break;
                case 1:
                    limit_compt = 100;
                    break;
                case 2:
                    limit_compt = 150;
                    break;
                case 3:
                    limit_compt = 200;
                    break;
                default:
                    printf("Il y a une erreur.");
                    break;
                }

            for (int j = i * 50; j < limit_compt;  j++){
                printf("%d,", j + 1);
            }

            printf("\n");
            i = 4;
        }
        wait(NULL);//Rajout pour la variante 2
        i ++;
    }

    return 0;
}