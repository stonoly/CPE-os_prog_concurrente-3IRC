/* Fichier: guess.c
* Write a program (Guess) whose father's process asks the user a number and transmits it to help
* From a pipe to its son process
* autor: Pierre MOLY
* Exercice 1
*/

#include "guess.h"

int main()
{
    int tube_num[2];
    int tube_comp[2];
    int res1 = pipe(tube_num);
    int res2 = pipe(tube_comp);
    if (res1 == -1 && res2 == -1){
        perror("Création Pipe"); exit(-1);
    }

    if (fork() == 0) {
        close(tube_num[1]);
        close(tube_comp[0]);

        int num_son = 0;
        srand(getpid());
        int gen_num = rand()%101;
        printf("Generate: %d\n",gen_num);
        int stop = 0;

        while (stop != 1){
            read(tube_num[0],&num_son,sizeof(int));

            if (num_son > gen_num){
                write(tube_comp[1],"-",sizeof(char));
            } else if (num_son < gen_num){
                write(tube_comp[1],"+",sizeof(char));
            } else {
                stop = 1;
                write(tube_comp[1],"=",sizeof(char));
            }
        }

        close(tube_num[0]);
        close(tube_comp[1]);

    } else {
        close(tube_num[0]);
        close(tube_comp[1]);

        int num_dad;
        char comparate_num;

        while (comparate_num != '='){
            sleep(1);
            printf("Ecriver un nombre: ");
            scanf("%d", &num_dad);
            write(tube_num[1], &num_dad, sizeof(int));
            read(tube_comp[0], &comparate_num, sizeof(char));
            printf("C'est %c\n",comparate_num);
        }

        close(tube_num[1]);
        close(tube_comp[0]);
    }
    return 0;
}