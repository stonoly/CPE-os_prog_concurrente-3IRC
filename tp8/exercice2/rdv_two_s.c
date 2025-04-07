/* Fichier: rdv_two_s.c
* Several processes wish to establish an appointment. Each process performs certain treatment but
* can only continue their execution if all the processes have reached the end of their treatment
* respective. Once, that does, everyone resumes their execution independently of the others
* autor: Pierre MOLY
* Exercice 2
*/

#include "rdv_two.h"

int main()
{
    puts("-- Le second est arrivé -->");

    int semWaitFirst = sem_get(1);
    int semWaitSecond = sem_get(2);

    V(semWaitFirst);

    puts("Je suis là.");
    P(semWaitSecond);

    puts("Allons y.");

    return 0;
}