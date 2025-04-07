/* Fichier: rdv_two_t_bis.c
* Several processes wish to establish an appointment. Each process performs certain treatment but
* can only continue their execution if all the processes have reached the end of their treatment
* respective. Once, that does, everyone resumes their execution independently of the others
* autor: Pierre MOLY
* Exercice 2 bis
*/

#include "rdv_two.h"

int main()
{
    puts("-- Le troisième est arrivé -->");

    int semWaitFirst = sem_get(1);
    int semWaiSecond = sem_get(2);
    int semWaitThird = sem_get(3);

    V(semWaitThird);
    V(semWaitThird);

    puts("Je suis là.");
    P(semWaitFirst);
    P(semWaiSecond);

    puts("Allons y.");

    return 0;
}