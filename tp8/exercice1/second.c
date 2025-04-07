/* Fichier: second.c
* writing two independent programs, where the second program waits for the first to complete
* its waiting period before starting its own
* autor: Pierre MOLY
* Exercice 1
*/

#include "second.h"

int main()
{
    puts("-- Lancement de Second -->");

    int semWaitFirst = sem_get(1);
    puts("J'attend que First ai finit pour générer un temps d'attente");
    P(semWaitFirst);

    srand(getpid());
    int nb_rand = rand() % 4 + 1;

    printf("Je vais attendre %d secondes.\n", nb_rand);
    sleep(nb_rand);

    V(semWaitFirst);
    puts("<-- Second vient de se terminer --");

    return 0;
}