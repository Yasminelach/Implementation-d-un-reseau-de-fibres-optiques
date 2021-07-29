 #include "Hachage.h"
#include <math.h>
#include "Reseau.c"



int cle(CellNoeud **n){
  return (int) n->nd->y +  (n->nd->x + n->nd->y)*(n->nd->x + n->nd->y + 1)/2
}
int h(double cle, int m){
    float A = (sqrt(5)-1)/2;
    return (int)m*(cle*A-(int)(cle*A));
}

Noeud* rechercheCreeNoeudHachage(Reseau* R, TableHachage*H, double x, double y){
    CellNoeud * c = H->tab;
    while (c->suiv){
        if(c->nd->x == x && c->nd->y == y){
            return c->nd;
        }
        c=c->suiv;
    }
    Noeud* n=(Noeud*)malloc(sizeof(Noeud));
    n = rechercheCreeNoeudListe(R, x, y);
    H->m ++;
    //sortie de boucle on ajoute un Noeud et une CellNoeud
    CellNoeud* c2=(CellNoeud*)malloc(sizeof(CellNoeud));
    while(c->suiv){
        c=c->suiv;
    }
    c2->nd=n;
    c->suiv=c2;
    }
}

Reseau* reconstitueReseauHachage(Chaines *C, int M){
  Reseau* R = (Reseau*)malloc(sizeof(Reseau));
  R->noeuds = (CellNoeud*)malloc(sizeof(CellNoeud));
  R->commodites = NULL; //on alloue la mémoir dans la boucle 
  R->gamma = C->gamma;
  R->nbNoeuds = 0; //au début, le réseau est vide
  CellCommodite* com_tmp ;
  CellChaine* c_tmp = C->chaines;
  CellPoint* p_tmp;
  
	int i=0;
	while(c_tmp){
    		p_tmp = c_tmp->points;
    		CellNoeuds*** tab = (CellNoeuds***)malloc(sizeof(CellNoeuds**)); 
    		int* tab2;
    		while (p_tmp){
        		rechercheCreeNoeudListe(R,p_tmp->x, p_tmp->y);
        		R->nbNoeuds++; 
			int cle = cle(p_tmp);
			tab[i]=p_tmp;
			tab2[i]=cle;
			p_tmp=p_tmp->suiv;
			i++
     		}
     	c_tmp = c_tmp->suiv;
	} 
	R->
