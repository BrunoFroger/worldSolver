//-----------------------------------------
//
//          aide.cpp
//
//-----------------------------------------

#include <stdio.h>

void aide(void){
    printf("WorldSolver\n");
    printf("Ce programme permet de chercher des mots dont vous connaissez certaines caracteristiques\n");
    printf("    - nombre de lettres (-n valeur)\n");
    printf("    - lettres bien placées (-b xx..x.x)\n");
    printf("    - lettres mal placées (-m xxx)\n");
    printf("    - lettres qui ne sont pas dans le mot (-x xxx)\n");
    printf("\n");
    printf("syntaxe :\n");
    printf("worldSolver [options]\n");
    printf("    -n valeur : nombre de lettres\n");
    printf("    -b x..x.x : mot avec les lettres bien placées connues ; le '.' remplace les lettres inconnues\n");
    printf("    -m xxxx : liste des lettres incluses mais mal placées\n");
    printf("    -x xxxx : liste des lettres exlues\n");
    printf("\n");
}