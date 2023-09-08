//-----------------------------------------
//
//          saisieParametres.cpp
//
//-----------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/variables.hpp"


void saisieParametres(void){
    char saisie[20];
    if (nbLettres == 0){
        printf("Nombre de lettres du mot : ");
        fgets(saisie, 20, stdin);
        nbLettres = atoi(saisie);
    }
    if (strcmp(mot, "") == 0){
        printf("saisir mot a analyser ; format x..x., ou x represente les lettres connues bien placées et . les lettres inconnues\n");
        printf("votre mot : ");
        fgets(mot, 50, stdin);
    }
    if (strcmp(lettresMalPlacees, "") == 0){
        printf("saisir la liste des lettres mal placées\n");
        printf("votre mot : ");
        fgets(lettresMalPlacees, 50, stdin);
    }
    if (strcmp(lettresIgnorees, "") == 0){
        printf("saisir la liste des lettres qui ne sont pas dans le mot\n");
        printf("votre mot : ");
        fgets(lettresIgnorees, 50, stdin);
    }
}
