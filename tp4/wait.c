/* Fichier: wait.c
* Bed on the command line (argc/argv) the number n of processes that it must create
* auteur: Pierre MOLY
* Exercice 4
*/

#include "wait.h"

int main(int argc, char* argv[]){
    if (argc != 2){
        puts("Error");
        return 1;
    }

    int itteration;
    int validate = sscanf(argv[1],"%d",&itteration);

    if (validate != 1){
        puts("Error");
        return 1;
    }
    for (int i = 0; i < itteration; i++){
        pid_t pid_fils = fork();
        pid_t pid_pere = getppid();
        pid_t pid_actual = getpid();
        printf("%d: Je suis le processus %d, mon père est le processus %d et fork a retourné %d\n", i, pid_actual, pid_pere, pid_fils);
    }
    return 0;
}