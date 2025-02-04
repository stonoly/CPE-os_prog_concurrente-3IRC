/* Fichier: ex2.c
* Énigme
* auteur: Pierre MOLY
* Exercice 2
*/

#include "ex2.h"

int reading_line(int tab[SIZE_TAB], int nbr_elem, int tab_out[SIZE_TAB]){
    int index_tab_out = 0;
    int elem = tab[0];
    int cpt = 0;

    for (int position_tab = 0; position_tab < nbr_elem + 1; position_tab++){
        if (index_tab_out + 2 > SIZE_TAB ){
            return -1;
        } else {
            if (tab[position_tab] == elem){
                cpt++;
            } else {
                tab_out[index_tab_out] = cpt;
                tab_out[index_tab_out + 1] = elem;
                index_tab_out += 2;
                elem = tab[position_tab];
                cpt = 1;
            }
        }
    }

    return index_tab_out;
}

int main(){
    int tab[SIZE_TAB] = {1, 1, 2, 3};
    int tab_out[SIZE_TAB];
    int nbr_elem = 4;

    while(nbr_elem < SIZE_TAB){
        nbr_elem = reading_line(tab, nbr_elem, tab_out);

        if (nbr_elem == -1){
            return 0;
        }

        printf("nbr_elem: %d\n", nbr_elem);

        for (int i_display = 0; i_display < nbr_elem; i_display++){
            tab[i_display] = tab_out[i_display];
            printf("%d ", tab_out[i_display]);
        }

        printf("\n");
    }

    return 0;
}