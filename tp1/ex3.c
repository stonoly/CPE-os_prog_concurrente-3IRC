/* Fichier: ex3.c
 * Intersection of two lines
 * auteur: Pierre MOLY
 * Exercice 3
 */

#include "ex3.h"

float coefficient(float x1, float x2, float y1, float y2){
    return (x2 == x1) ? INFINITY : (y2 - y1) / (x2 - x1);
}

float ordonnee(float x, float y, float a){
    return (a == INFINITY) ? x : y - (a * x);
}

void intersection(float a1, float a2, float b1, float b2, float *x, float *y){
    if (a1 == a2) {
        if (b1 == b2) {
            printf("Les droites sont confondues.\n");
        } else {
            printf("Les droites sont parallèles et n'ont pas d'intersection.\n");
        }
        *x = NAN;
        *y = NAN;
        return;
    }

    if (a1 == INFINITY) {
        *x = b1;
        *y = a2 * (*x) + b2;
    } else if (a2 == INFINITY) {
        *x = b2;
        *y = a1 * (*x) + b1;
    } else {
        *x = (b2 - b1) / (a1 - a2);
        *y = a1 * (*x) + b1;
    }
}

int main(){
    float P1x = 1, P1y = 3, P2x = 1, P2y = 3;
    float P3x = -2, P3y = -1, P4x = 0, P4y = 3;

    float a1 = coefficient(P1x, P2x, P1y, P2y);
    float b1 = ordonnee(P1x, P1y, a1);

    float a2 = coefficient(P3x, P4x, P3y, P4y);
    float b2 = ordonnee(P3x, P3y, a2);

    float x, y;
    intersection(a1, a2, b1, b2, &x, &y);

    printf("a1 = %f, b1 = %f\n", a1, b1);
    printf("a2 = %f, b2 = %f\n", a2, b2);
    if (!isnan(x) && !isnan(y)) {
        printf("Intersection: x = %f, y = %f\n", x, y);
    }

    return 0;
}
