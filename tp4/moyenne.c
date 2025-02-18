/* Fichier: moyenne.c
* Calculate and displays the average of a set of notes
* auteur: Pierre MOLY
* Exercice 2
*/

#include "moyenne.h"

int main(int argc, char* argv[]){
    if (argc == 1){
        puts("Aucune note fourni, moyenne impossible à calculer");
        return 1;
    }else {
        int nbr_note = 0;
        int total_notes = 0;
        for (int j = 1; j < argc; j++){
            int nb;
            int nb_success = sscanf(argv[j],"%d",&nb);
            if (nb_success != 1){
                puts("Note(s) non valide(s)");
                return 1;
            } else {
                if (0 <= nb && nb <= 20){
                    nbr_note += 1;
                    total_notes += nb;
                } else {
                    puts("Note(s) non valide(s)");
                    return 1;
                }
            }
        }
        float moyenne = total_notes / nbr_note;
        printf("Moyenne : ");
        printf("%4.2f\n", moyenne);
        return 0;
    }
}