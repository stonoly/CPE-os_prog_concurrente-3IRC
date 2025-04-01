/* Fichier: init.c
* Write a program wishing to establish an appointment with n version of itself. N is an argument received
* on the command line
* autor: Pierre MOLY
* Exercice 1
*/

#include "init.h"

int main()
{
    sem_create(KEY_MUTEX, 1);

    sem_create(2, 0);

    int shmid = shmget(KEY_MUTEX, sizeof(int), IPC_CREAT|IPC_EXCL|0600);
    if (shmid == -1) {
        perror("Shmget Create Error");
        }

    return 0;
}