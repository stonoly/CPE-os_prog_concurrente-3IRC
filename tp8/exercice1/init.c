/* Fichier: init.c
* writing two independent programs, where the second program waits for the first to complete
* its waiting period before starting its own
* autor: Pierre MOLY
* Exercice 1
*/

#include "init.h"

int main()
{
    sem_create(1, 1);
    
    return 0;
}