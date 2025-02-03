/* Fichier: ex1.c
* First factor decomposition
* auteur: Pierre MOLY
* Exercice 1
*/

#include "ex1.h"

int smaller_divisor(int number){
    int smaller = number;
    int i = 2;
    while (i < smaller){
        if (smaller % i == 0){
            smaller = i;
        }
        i++;
    }
    return smaller;
}

int main(){
    int user_number;
    int tab_result[100];
    int index_tab = 0;
    int smaller_div_user = 0;
    puts("Entrez un nombre:");
    scanf("%d", &user_number);

    while (user_number != smaller_div_user && user_number > 1){
        smaller_div_user = smaller_divisor(user_number);
        tab_result[index_tab] = smaller_div_user;
        user_number = user_number / smaller_div_user;
        index_tab++;
    }

    for(int i = 0; i < index_tab; i++){
        printf("%d ", tab_result[i]);
    }
    printf("\n");

    return 0;
}