#include "ArbreQuat.h"

void chaineCoordMinMax(Chaines* C, double* xmin, double* ymin, double* xmax, double* ymax){
    if (C){
        if (C->nbChaines == 0 ){
            return; //test si la chaine ne contient aucun element 
        }
        CellChaine *tmp = C->chaines;
        *xmin = tmp->points->x;
        *ymin = tmp->points->y;
        *xmax = *xmin ;
        *ymax = *ymin ;
        tmp=tmp->suiv;
        while(tmp){
            if (tmp->points->x < *xmin) *xmin = tmp->points->x;
            if (tmp->points->y < *ymin) *ymin = tmp->points->y;
            if (tmp->points->x > *xmax) *xmax = tmp->points->x;
            if (tmp->points->y > *ymax) *ymax = tmp->points->y;
            tmp=tmp->suiv;
        } 
    }
}
ArbreQuat* creerArbreQuat(double xc, double yc, double coteX, double coteY){
    ArbreQuat* abr = (ArbreQuat*)malloc(sizeof(ArbreQuat));
    if (abr){
        abr->xc = xc;
        abr->yc = yc;
        abr->coteX = coteX;
        abr->coteY = coteY;
        abr->noeud = NULL;
        abr->ne = NULL;
        abr->no = NULL;
        abr->se = NULL;
        abr->so = NULL;
    }
}
void insererNoeudArbre(Noeud* n, ArbreQuat** a, ArbreQuat* parent){
	Noeud* tmp = n;
	tmp -> x
	tmp -> y
}