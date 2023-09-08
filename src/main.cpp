//-----------------------------------------
//
//          main.cpp
//
//-----------------------------------------

#include "stdio.h"
#include <string.h>
#include <cctype>

#include "../inc/analyseParametres.hpp"
#include "../inc/saisieParametres.hpp"

int nbLettres = 0;
char mot[20] = "";
char lettresMalPlacees[26] = "";
char lettresIgnorees[26] = "";
FILE *fic;
char dictionnaire[25] = "datas/ods6.txt";
//char dictionnaire[50] = "datas/liste_mots_test.txt";
char ligne[100];
char listeMotsValides[1000][50];
int idxMotvalide = 0;
int nbMotsOK = 0;

int main(int argc, char **argv){
    char a,b,c;
    bool result;

    printf("Solveur de mots\n");
    analyseParametres(argc, argv);
    saisieParametres();
    
    printf("lettres bien placées : <%s>\n", mot);
    printf("lettres mal placées <%s>\n", lettresMalPlacees);
    printf("lettres ignorées <%s> \n", lettresIgnorees);
    fic = fopen(dictionnaire,"r");
    if (fic == NULL){
        printf("impossible d'ouvrir le dictionnaire\n");
        return -1;
    }
    printf("===========================\n");
    printf("recherche de correspondance\n");

    while (!feof(fic)){
        fgets(ligne, 100, fic);
        result = true;
        if (ligne[strlen(ligne) - 1] == '\n') ligne[strlen(ligne) - 1] = '\0';
        if (strlen(ligne) != nbLettres) continue;
        //printf("---------------------------\n");
        //printf("Test du mot <%s> du dictionnaire\n", ligne);

        // recherche des lettres bien placées
        for (int i = 0 ; i < nbLettres ; i++){
            a = tolower(mot[i]);
            b = tolower(ligne[i]);
            //printf("Comparaison de %c et %c\n", a, b);
            if (a != '.'){
                if (a != b){
                    // les lettres bien placées ne match pas
                    result = false;
                    break;
                }
            }
        }
        if (!result){
            //printf("une des lettres bien placees ne convient pas dans <%s> => <%s>\n", ligne, mot);
            continue;
        }

        //recherche des lettres ignorées
        for (int i = 0 ; i < nbLettres ; i++){
            a = tolower(ligne[i]);
            for (int j = 0 ; j < strlen(lettresIgnorees) ; j++){
                c = tolower(lettresIgnorees[j]);
                if (a == c){
                    //printf("dans ligne= %s => ligne[%d]=%c / ignorees[%d]=%c \n", ligne, i, a, j, c);
                    result = false;
                    break;
                }
            }
            if (!result){
                break;
            } 
        }
        if (!result){
            //printf("une des lettres ignoree ne convient pas dans <%s> => <%s>\n", ligne, mot);
            continue;
        }

        // test des lettres mal placées
        char *tmp = lettresMalPlacees;
        char tmpLigne[100];
        int nbLettresMalPlacees = strlen(lettresMalPlacees);
        strcpy(tmpLigne, ligne);
        //printf("test lettres mal placees dans <%s>\n", tmpLigne);
        while (strlen(tmp) > 0){
            c = tolower(tmp[0]);
            //printf("test lettre %c\n", c);
            for (int i = 0; i < strlen(tmpLigne) ; i++){
                a = tolower(tmpLigne[i]);
                //printf("comparaison de %c et %c\n", a, c);
                if (a == c){
                    tmpLigne[i] = '.';
                    nbLettresMalPlacees--;
                    //printf("une des lettres mal placee convient : %c\n", a);
                    break;
                } 
            }
            tmp++;
        }
        result = (nbLettresMalPlacees == 0);

        if (!result){
            //printf("une des lettres mal placées ne convient pas dans <%s> => <%s>\n", ligne, mot);
            continue;
        }

        if (result){
            printf("le mot <%s> semble convenir\n", ligne);
            nbMotsOK++;
        }
    }

    printf("fin de recherche\n");

    printf("%d mots correspondent a vos critères\n", nbMotsOK);
    fclose(fic);
}