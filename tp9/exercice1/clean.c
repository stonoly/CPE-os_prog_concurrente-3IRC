/* Fichier: clean.c
* Write a program wishing to establish an appointment with n version of itself. N is an argument received
* on the command line
* autor: Pierre MOLY
* Exercice 1
*/

#include "clean.h"

int main()
{
    int shmid = shmget(KEY_MUTEX, sizeof(int), 0);
    int res_del = shmctl(shmid, IPC_RMID, NULL);
    if (res_del == -1) {
        perror("Delete Shm");
    }

    int mutex = sem_get(KEY_MUTEX);
    sem_delete(mutex);

    int semWaitPeople = sem_get(2);
    sem_delete(semWaitPeople);

    return 0;
}