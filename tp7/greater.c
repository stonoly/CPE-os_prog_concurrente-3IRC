/* Fichier: greater.c
* Write a program Largest number
* autor: Pierre MOLY
* Exercice 1
*/

#include "greater.h"

int generation_random(void){
    srand(getpid());
    int number_random  = rand() % 100 + 1;
    return number_random;
}

int main(int argc, char* argv[]){

    int number_of_processus;
    int processus_pid_biggest;
    int processus_index_biggest;
    int biggest_numb;

    if (argc != 2){
        puts("Il n'y a pas le bon nombre d'argument");
        return 1;
    }

    if (sscanf(argv[1], "%d", &number_of_processus) == 1) {
        printf("L'entier extrait est : %d\n", number_of_processus);
    } else {
        puts("Ce n'est pas un entier passé en argument");
        return 1;
    }

    if (number_of_processus > 1){
        int tube_transmission[number_of_processus][2];
        int pipe_transmission = pipe(tube_transmission[0]);
    } else {
        int tube_transmission[1][2];
        int pipe_transmission = pipe(tube_transmission);
    }


    for (int i = 0; i < number_of_processus; i++){

        pid_t pid_processus = fork();
        if ( pid_processus == 0 ){

            printf("Je suis le processus enfant numero %d\n", i);
            int number_generate = generation_random();
            close(tube_transmission[0][0]);
            write(tube_transmission[0][1], [number_generate, pid_processus, i], sizeof(int[3]));
            close(tube_transmission[0][1]);
            exit(-1);
        } else {
            printf("Je suis le processus pere numero %d avec le pid : %d\n", i, pid_processus);
        }
    }

    if (number_of_processus == 0){

        biggest_numb = generation_random();
        processus_pid_biggest = getpid();
        processus_index_biggest = number_of_processus;

    } else {

        if (pipe_final == -1){
            perror("Création Pipe");
            exit(-1);
        }

        close(tube_transmission[0][1]);
        int comparate[3];
        read(tube_transmission[0][1], &comparate, sizeof(int[3]));
        if (comparate[0] > generation_random()){
            biggest_numb = comparate[0];
            processus_pid_biggest = comparate[1];
            processus_index_biggest = comparate[2];


        }
        printf("number_generate à la fin %d\n", biggest_numb);
        close(tube_transmission[0][0]);

    }
    printf("Le plus grand nombre = %d - pid = %d - Numéro %d\n", biggest_numb, processus_pid_biggest, processus_index_biggest);
    return 0;
}