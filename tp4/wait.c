/* Fichier: wait.c
* Bed on the command line (argc/argv) the number n of processes that it must create
* auteur: Pierre MOLY
* Exercice 4
*/

#include "wait.h"
#include <stdio.h>

int main(int argc, char* argv[]){
    if (argc != 2){
        puts("Error there is no argument voucher number ./wait <number_process>");
        return 1;
    }

    int itteration;
    int validate = sscanf(argv[1],"%d",&itteration);

    if (validate != 1){
        puts("Error");
        return 1;
    }
    int i = 0;
    for (int i = 0; i < itteration; i++){
        pid_t pid_fils = fork();
        if (pid_fils == 0){
            pid_t pid_pere = getppid();
            pid_t pid_actual = getpid();
            puts("--------------------");
            printf("Je suis le processus %d, mon père est le processus %d\n", pid_actual, pid_pere);
            sleep(i * 2);
            printf("%d: Je reprends mon processus\n", pid_actual);
            exit(i);
        }
    }
    int status;
    pid_t terminated_pid;
    for (i = 0; i < itteration; i++) {
        terminated_pid = wait(&status);
        if (WIFEXITED(status)) {
            printf("Je suis le père de %d, et il m'a retourné : %d\n", terminated_pid, WEXITSTATUS(status));
        }
    }

    return 0;
}