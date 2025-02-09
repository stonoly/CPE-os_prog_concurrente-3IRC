/* Fichier: ex4.c
 * Insertion sorting
 * auteur: Pierre MOLY
 * Exercice 4
 */

#include "ex4.h"

int index_to_insert(int tab[100], int new_item, int size_tab){
    int index = 0;

    while (tab[index] < new_item && index < size_tab){
        index++;
    }
    return index;
}

int insertion(int tab[100], int new_item, int index_to_insert, int size_tab){
    int size_tab_copy = size_tab;
    while(index_to_insert - 1 < size_tab_copy){
        tab[size_tab_copy + 1] = tab[size_tab_copy];
        size_tab_copy -= 1;
    }
    tab[index_to_insert] = new_item;
    size_tab++;
    return size_tab;
}

int main(){

    int tab[100] = {38, 39, 40, 42, 48, 49, 51, 55, 62};
    int size_tab = 9;

    int position_to_insert = index_to_insert(tab, 50, size_tab);
    printf("position_to_insert: %d\n", position_to_insert);

    size_tab = insertion(tab, 50, position_to_insert, size_tab);

    for (int i = 0; i < size_tab; i++){
        printf("tab[%d] = %d\n", i, tab[i]);
    }

    return 0;
}
