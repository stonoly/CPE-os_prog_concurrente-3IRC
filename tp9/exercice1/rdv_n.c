/* Fichier: rdv_n.c
* Write a program wishing to establish an appointment with n version of itself. N is an argument received
* on the command line
* autor: Pierre MOLY
* Exercice 1
*/

#include "rdv_n.h"

int main(int argc, char* argv[])
{
    if (argc != 2){
        puts("Il n'y a pas le bon nombre d'argument:");
        return 1;
    }

    int nb_people;
    int nb_people_success = sscanf(argv[1],"%d",&nb_people);
    if (nb_people_success != 1){
        puts("Le nombre de personne n'est pas valide");
        return 1;
    }

    int shmid = shmget(KEY_MUTEX, sizeof(int), 0);
    int mutex = sem_get(KEY_MUTEX);
    int semWaitPeople = sem_get(2);

    int* compt = shmat(shmid, NULL, 0);

    P(mutex);
    puts("Je suis un participant qui vient d'arriver je regarde mon ordre d'arrivé");
    *compt = *compt + 1;

    if (*compt == nb_people){
        puts("Je suis le dernier arrivé on peut y aller");
        V(mutex);

        for(int i = 0; i < nb_people; i++){
            V(semWaitPeople);
        }
    } else {
        printf("Je suis le %d arrivé tout le monde n'est là donc j'attends...\n", *compt);

        V(mutex);
        P(semWaitPeople);

        puts("C'est bon tout le monde est là allons y");
        shmdt(compt);

    }

    return 0;
}