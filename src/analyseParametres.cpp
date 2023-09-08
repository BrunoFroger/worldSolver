//-----------------------------------------
//
//          analyseParametres.cpp
//
//-----------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/variables.hpp"
#include "../inc/aide.hpp"


void analyseParametres(int argc, char **argv){
    if (argc > 1) {
        for (int i = 1 ; i < argc ; i++){
            //printf("analyse du parametre <%s>\n", argv[i]);
            if (argv[i][0] == '-'){
                switch(argv[i][1]){
                    case 'b':
                    case 'B':
                        i++;
                        strcpy(mot, argv[i]);
                        break;
                    case 'n':
                    case 'N':
                        i++;
                        nbLettres = atoi(argv[i]);
                        //printf("Taille du mot = %d\n", nbLettres);
                        break;
                    case 'm':
                    case 'M':
                        i++;
                        strcpy(lettresMalPlacees, argv[i]);
                        break;
                    case 'x':
                    case 'X':
                        i++;
                        strcpy(lettresIgnorees, argv[i]);
                        break;
                    default:
                        printf("option %s inconnue \n", argv[i]);
                }
            }
        }
    } else {
        printf("pas de parametres\n");
        aide();
    }
    //printf("fin analyse parametres\n");
}