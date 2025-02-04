/* Fichier: ex3.c
* Intersection of two lines
* auteur: Pierre MOLY
* Exercice 3
*/

#include "ex3.h"

float coefficient(float x1, float x2, float y1, float y2){
    return (x2 == x1) ? INFINITY : (y2 - y1)/(x2 - x1);
}

float ordonnée(float x, float y, float a){
    return y - (a * x);
}

int main(){
    float P1x = 1;
    float P1y = 2;
    float P2x = 2;
    float P2y = 0;

    float P3x = 1;
    float P3y = 3;
    float P4x = 3;
    float P4y = 2;

    float a1;
    float b1;

    float a2;
    float b2;

    a1 = coefficient(P1x, P2x, P1y, P2y);
    b1 = ordonnée(P1x, P1y, a1);

    a2 = coefficient(P3x, P4x, P3y, P4y);
    b2 = ordonnée(P3x, P3y, a2);


    printf("a1 = %f\n", a1);
    printf("b1 = %f\n", b1);

    printf("a2 = %f\n", a2);
    printf("b2 = %f\n", b2);

    return 0;
}