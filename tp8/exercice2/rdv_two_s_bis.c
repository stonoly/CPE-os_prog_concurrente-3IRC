/* Fichier: rdv_two_s_bis.c
* Several processes wish to establish an appointment. Each process performs certain treatment but
* can only continue their execution if all the processes have reached the end of their treatment
* respective. Once, that does, everyone resumes their execution independently of the others
* autor: Pierre MOLY
* Exercice 2 bis
*/

#include "rdv_two.h"

int main()
{
    puts("-- Le second est arrivé -->");

    int semWaitFirst = sem_get(1);
    int semWaitSecond = sem_get(2);
    int semWaitThird = sem_get(3);

    V(semWaitSecond);
    V(semWaitSecond);

    puts("Je suis là.");
    P(semWaitFirst);
    P(semWaitThird);


    puts("Allons y.");

    return 0;
}