#ifndef __HACHAGE_H__
#define __HACHAGE_H__
#include "Reseau.h"

//4.1
typedef struct tableHachage {
    int taille;//taille de la table d'hachage
    int m;//nombre d'élèments 
    CellNoeud *tab;
} TableHachage;

//4.2 
int f1(double cle, double cle2);
//4.3
int f2(double cle, int m);

//4.5
Reseau* reconstitueReseauHachage(Chaines *C, int M); 

#endif
