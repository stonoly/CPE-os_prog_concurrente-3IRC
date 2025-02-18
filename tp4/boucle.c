/* Fichier: boucle.c
* Calls on fork in a loop that will make 3 iterations
* auteur: Pierre MOLY
* Exercice 3
*/

#include "boucle.h"

int main(){
    for (int i = 0; i < 3; i++){
        pid_t pid_fils = fork();
        pid_t pid_pere = getppid();
        pid_t pid_actual = getpid();
        printf("%d: Je suis le processus %d, mon père est le processus %d et fork a retourné %d\n", i, pid_actual, pid_pere, pid_fils);
    }
    return 0;
}