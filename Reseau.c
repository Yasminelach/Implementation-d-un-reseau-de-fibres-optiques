#include "Reseau.h"

//2.1
Noeud* rechercheCreeNoeudListe(Reseau *R, double x, double y){
  //on recupere une cellnoeud dans R
  CellNoeud* c=R->noeuds;;

  //on verifie la premiere CellNoeud
  if(c->nd->x==x && c->nd->y==y){
    return c->nd;
  }
  //on utilise c->suiv pour pouvoir ajouter un noeud si on doit le créer
  while(c->suiv){
    if(c->nd->x==x && c->nd->y==y){
      return c->nd;
    }
    c=c->suiv;
  }
  //sortie de boucle on ajoute un Noeud et une CellNoeud
  CellNoeud* c2=(CellNoeud*)malloc(sizeof(CellNoeud));
  Noeud* n=(Noeud*)malloc(sizeof(Noeud));
  n->num=R->nbNoeuds; R->nbNoeuds+=1;
  n->x=x; n->y=y;
  c2->nd=n;
  c->suiv=c2;
}

//2.2
Reseau* reconstitueReseauListe(Chaines *C){
  Reseau* R = (Reseau*)malloc(sizeof(Reseau));
  R->noeuds = (CellNoeud*)malloc(sizeof(CellNoeud));
  R->commodites = NULL; //on alloue la mémoir dans la boucle 
  R->gamma = C->gamma;
  R->nbNoeuds = 0; //au début, le réseau est vide
  CellCommodite* com_tmp ;
  CellChaine* c_tmp = C->chaines;
  CellPoint* p_tmp;
  while(c_tmp){
    p_tmp = c_tmp->points;
    if (p_tmp){
        rechercheCreeNoeudListe(R,p_tmp->x, p_tmp->y);
        com_tmp = (CellCommodite*)malloc(sizeof(CellCommodite));;
        com_tmp->extrA = (Noeud*)malloc(sizeof(Noeud));
        com_tmp->extrA->num = c_tmp->numero;
        com_tmp->extrA->x = p_tmp->x;
        com_tmp->extrA->y =p_tmp->y;
        com_tmp->suiv = NULL;
        R->nbNoeuds++; 
        while(p_tmp->suiv){
               rechercheCreeNoeudListe(R,p_tmp->suiv->x, p_tmp->suiv->y);
               p_tmp = p_tmp->suiv;
               R->nbNoeuds++;
        }
        com_tmp->extrB = (Noeud*)malloc(sizeof(Noeud));
        com_tmp->extrB->num = c_tmp->numero;
        com_tmp->extrB->x = p_tmp->x;
        com_tmp->extrB->y =p_tmp->y;
        com_tmp = com_tmp->suiv;        
     }
     c_tmp = c_tmp->suiv;
  }
  return R;
}

int nbCommodites(Reseau *R){
  int counter = 0;
  CellCommodite* c = R->commodites;
  while(c){
    counter++;
    c=c->suiv;
  }
  return counter;
}

int nbLiaisons(Reseau *R){
  int counter = 0;
  CellCommodite* c = R->commodites;
  while(c){
    CellNoeud* n = R->noeuds;
    while(n->nd != c->extrA){
      n=n->suiv;
    }
    if(n->nd == c->extrA){
      while(n->nd != c->extrB){
        counter++;
        n=n->suiv;
      }
    }
    c=c->suiv;
  }
  return counter;
}

void ecrireReseau(Reseau *R, FILE *f){
  if(R){
    fprintf(f, "NbNoeuds: %d\n", R->nbNoeuds);
    fprintf(f, "NbLiaisons: %d\n", nbLiaisons(R));
    fprintf(f, "NbCommodites: %d\n", nbCommodites(R));
    fprintf(f, "Gamma: %d\n", R->gamma);
    fprintf(f, "\n");
    for(int i = 0; i < R->nbNoeuds; i++){
      fprintf(f, "v %d %lf %lf\n", R->noeuds->nd->num,R->noeuds->nd->x,R->noeuds->nd->y);
      R->noeuds=R->noeuds->suiv;
    }
    fprintf(f, "\n");
    CellCommodite* c = R->commodites;
    while(c){
      CellNoeud* n = R->noeuds;
      while(n->nd != c->extrA){
        n=n->suiv;
      }
      CellNoeud* prec = n;
      if(n->nd == c->extrA){
        while(n->nd != c->extrB){
          n=n->suiv;
          fprintf(f, "l %d %d\n",prec->nd->num,n->nd->num);
          prec=prec->suiv; 
        }
      }
      c=c->suiv;
    }
    fprintf(f, "\n");
    for(int i = 0; i < nbCommodites(R); i++){
      fprintf(f, "k %d %d \n", R->commodites->extrA->num,R->commodites->extrB->num);
      R->commodites=R->commodites->suiv;
    }
  }
}

void afficheReseauSVG(Reseau *R, char* nomInstance){
    CellNoeud *courN,*courv;
    SVGwriter svg;
    double maxx=0,maxy=0,minx=1e6,miny=1e6;

    courN=R->noeuds;
    while (courN!=NULL){
        if (maxx<courN->nd->x) maxx=courN->nd->x;
        if (maxy<courN->nd->y) maxy=courN->nd->y;
        if (minx>courN->nd->x) minx=courN->nd->x;
        if (miny>courN->nd->y) miny=courN->nd->y;
        courN=courN->suiv;
    }
    SVGinit(&svg,nomInstance,500,500);
    courN=R->noeuds;
    while (courN!=NULL){
        SVGpoint(&svg,500*(courN->nd->x-minx)/(maxx-minx),500*(courN->nd->y-miny)/(maxy-miny));
        courv=courN->nd->voisins;
        while (courv!=NULL){
            if (courv->nd->num<courN->nd->num)
                SVGline(&svg,500*(courv->nd->x-minx)/(maxx-minx),500*(courv->nd->y-miny)/(maxy-miny),500*(courN->nd->x-minx)/(maxx-minx),500*(courN->nd->y-miny)/(maxy-miny));
            courv=courv->suiv;
        }
        courN=courN->suiv;
    }
    SVGfinalize(&svg);
}



























//comfort
