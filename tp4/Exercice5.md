# Analyse de Code:
- ## Cas n°1:
```
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    int i, n=0;
    pid_t fils_pid;

    for (i=1; i< 5; i++) {
        fils_pid = fork();

        if (fils_pid > 0) {
            n = i*2;
            break;
        }
    }

    printf("%d\n", n);
    return 0;
}
```

- ___Dans le block d’exécution du if (ligne 12 et 13). Dans quel processus se trouve-t-on ? (père ou fils)___

Nous sommes dans le processus père.

- ___Ce programme est-il déterministe ? Justifiez___

Nan ce programme n'est pas deterministe car les processus fils et processus père lances des processus donc ils peuvent être lancé dans des ordres différents et ne pas print la même chose.

- ___Si le programme est déterministe: Indiquez exactement ce qui sera affiché lors de son exécution. Si le programme n’est pas déterministe: Indiquez un des affichages possible, Faîtes en sorte de rendre ce programme déterministe, Indiquez ce qui sera affiché alors.___

Un des affichages possibles est
```
2
4
6
8
0
```
pour rendre le programme deterministe il faut ajouter ` wait(NULL)` à la ligne 12. Et avec cet ajout l'affichage sera toujours:
```
0
8
6
4
2
```

- ___L’appel à fork() peut-il échouer ? Pourquoi ?___

Fork() peut échouer principalement à cause des limitations du système (nombre de processus, mémoire insuffisante, restrictions administratives)

- ## Cas n°2:
```
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    int i = 0;
    for (i=0 ; i<4 ; i++)
        if (fork())
            break;
    srand(getpid());
    int delai = rand()%4;
    sleep(delai);
    printf("Je suis %c, j'ai dormi %d s\n",'A'+i,delai);
    return 0;
 }
```
- ___Donnez l’arbre des processus générés par ce
programme___
```
P (i=0)
│
├── F1 (i=1)
│   │
│   ├── F2 (i=2)
│   │   │
│   │   ├── F3 (i=3)
│   │   │   │
│   │   │   ├── F4 (i=4)
```

- ___Ce programme est-il déterministe ?___

Ce programme n'est pas deterministe.

-___Sans modifier les lignes 1 à 12, modifiez ce programme pour qu’il produise un affichage dans l’ordre alphabétique inverse (EDCBA)___
```
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>  // Ajout de l'en-tête pour wait()

int main(void) {
    int i = 0;
    for (i = 0; i < 4; i++)
        if (fork())
            break;

    srand(getpid());
    int delai = rand() % 4;
    sleep(delai);

    // Attendre les processus enfants pour assurer l'ordre inverse
    while (wait(NULL) > 0);

    printf("Je suis %c, j'ai dormi %d s\n", 'A' + i, delai);
    return 0;
}
```

