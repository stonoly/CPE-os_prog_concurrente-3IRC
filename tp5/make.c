/* Fichier: make.c
* Write a program (make.c) which takes a series of .c sources files into arguments, the compiles each.
* Separately and simultaneously then makes the link edition using the last argument to name the executable.
* auteur: Pierre MOLY
* Exercice 2
*/

#include "make.h"

int main(int argc, char* argv[]){
    char* tab_li[argc + 3];
    tab_li[0] = "gcc";
    tab_li[1] = "-o";
    tab_li[2] = argv[argc - 1];

    for (int i = 1; i < argc - 1; i++){
        int size_names_file = strlen(argv[i]);
        char *tab = malloc((size_names_file + 1) * sizeof(char));
        if(tab == NULL) {
            return 1;
        }
        strcpy(tab, argv[i]);
        tab[size_names_file - 1] = 'o';
        tab[size_names_file] = '\0';
        tab_li[i + 2] = tab;




        pid_t fils = fork();
        if ( fils == 0 ){

            char* argv_ex[6] = {"gcc", "-c", argv[i], "-o", tab, NULL};
            int error = execvp("gcc", argv_ex);

            if (error == -1){
                exit(-1);
            }
        }

        wait(NULL);
    }

    tab_li[argc + 1] = NULL;

    pid_t fils_2 = fork();
        if ( fils_2 == 0 ){
            int error2 = execvp("gcc", tab_li);

            if (error2 == -1){
                exit(-1);
            }
        }

        wait(NULL);

    for (int i = 1; i < argc - 1; i++) {
        free(tab_li[i + 2]);
    }
    return 0;
}