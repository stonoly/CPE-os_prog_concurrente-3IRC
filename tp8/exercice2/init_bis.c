/* Fichier: init_bis.c
* Several processes wish to establish an appointment. Each process performs certain treatment but
* can only continue their execution if all the processes have reached the end of their treatment
* respective. Once, that does, everyone resumes their execution independently of the others
* autor: Pierre MOLY
* Exercice 2 bis
*/

#include "init.h"

int main()
{
    sem_create(1, 0);
    sem_create(2, 0);
    sem_create(3, 0);

    return 0;
}