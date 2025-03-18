/* Fichier: first.c
* writing two independent programs, where the second program waits for the first to complete
* its waiting period before starting its own
* autor: Pierre MOLY
* Exercice 1
*/

#include "first.h"

int main()
{
    puts("-- Lancement de First -->");

    srand(getpid());
    int nb_rand = rand() % 3 + 3;

    printf("Je vais attendre %d secondes.\n", nb_rand);
    sleep(nb_rand);

    puts("<-- First vient de se terminer --");

    return 0;
}