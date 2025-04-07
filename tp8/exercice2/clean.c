/* Fichier: clean.c
* Several processes wish to establish an appointment. Each process performs certain treatment but
* can only continue their execution if all the processes have reached the end of their treatment
* respective. Once, that does, everyone resumes their execution independently of the others
* autor: Pierre MOLY
* Exercice 2
*/

#include "clean.h"

int main()
{
    int semWaitFirst = sem_get(1);
    sem_delete(semWaitFirst);

    int semWaitSecond = sem_get(2);
    sem_delete(semWaitSecond);

    return 0;
}