/* Fichier: clean.c
* writing two independent programs, where the second program waits for the first to complete
* its waiting period before starting its own
* autor: Pierre MOLY
* Exercice 1
*/

#include "clean.h"

int main()
{
    int semWaitFirst = sem_get(1);
    sem_delete(semWaitFirst);

    return 0;
}