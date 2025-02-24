/* Fichier: successif.c
* Write the program (successif.c) which corresponds exactly to the sequel to command : du -sh /usr/share ; ls -l ; ps
* auteur: Pierre MOLY
* Exercice 1.2
*/

#include "successif.h"

int main(void){

    pid_t fils_1 = fork();

     if (fils_1 == 0){

         char* argv[4] = {"du","-sh", "/usr/share", NULL};
         int error = execvp("du",argv);

         if (error == -1){
             perror("exec du fail");
             exit(-1);
         }
     }
     wait(NULL);

     pid_t fils_2 = fork();
     if (fils_2 == 0){
         char* argv[3] = {"ls","-l", NULL};
         int error = execvp("ls",argv);

         if (error == -1){
             perror("exec ls fail");
             exit(-1);
         }
     }
     wait(NULL);

     pid_t fils_3 = fork();
     if (fils_3 == 0){
         char* argv[2] = {"ps", NULL};
         int error = execvp("ps",argv);

         if (error == -1){
             perror("exec ps fail");
             exit(-1);
         }
     }
     wait(NULL);

     return 0;
 }