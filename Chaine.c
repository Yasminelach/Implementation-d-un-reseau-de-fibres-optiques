#include "Chaine.h"
#include "SVGwriter.c"
#include <math.h>

void vider_newline(FILE *f) {
  int c = getc(f);
  while (c != '\n') {
    c = getc(f);
  }
}

Chaines *lectureChaine(FILE *f) {
  Chaines *chaines = malloc(sizeof(Chaines));
  if (chaines == NULL) {
    return NULL;
  }
  int nbChaines;
  int gamma;

  fscanf(f, "NbChain: %d\n", &nbChaines);
  fscanf(f, "Gamma: %d\n", &gamma);
  vider_newline(f);

  chaines->nbChaines = nbChaines;
  chaines->gamma = gamma;
  chaines->chaines = NULL;

  for (int i = 0; i < nbChaines; i++) {
    CellChaine *cell = malloc(sizeof(CellChaine));
    if (cell == NULL) {
      // TODO: Libérer mémoire
    }

    int numChaine;
    int nbPoints;

    fscanf(f, "%d %d", &numChaine, &nbPoints);

    cell->numero = numChaine;
    cell->points = NULL;

    for (int j = 0; j < nbPoints; j++) {
      CellPoint *point = malloc(sizeof(CellPoint));
      if (point == NULL) {
        // TODO: Libérer mémoire
      }

      fscanf(f, "%lf %lf", &point->x, &point->y);
      point->suiv = cell->points;
      cell->points = point;
    }

    cell->suiv = chaines->chaines;
    chaines->chaines = cell;
    vider_newline(f);
  }

  return chaines;
}

void ecrireChaines(Chaines *C, FILE *f) {
  fprintf(f, "NbChain: %d\n", C->nbChaines);
  fprintf(f, "Gamma: %d\n", C->gamma);
  fprintf(f, "\n");

  for (CellChaine *c = C->chaines; c != NULL; c = c->suiv) {
    int nbPoints = 0;
    CellPoint *counter = c->points;

    while (counter != NULL) {
      nbPoints++;
      counter = counter->suiv;
    }

    fprintf(f, "%d %d", c->numero, nbPoints);

    for (CellPoint *point = c->points; point != NULL; point = point->suiv) {
      fprintf(f, "%lf %lf", point->x, point->y);
    }
    fprintf(f, "\n");
  }
}

void afficheChainesSVG(Chaines *C, char *nomInstance) {
  SVGwriter *svg = malloc(sizeof(SVGwriter));
  if (svg == NULL) {
    return;
  }

  SVGinit(svg, nomInstance, 1920, 1080);
  SVGlineRandColor(svg);
  for (CellChaine *c = C->chaines; c != NULL; c = c->suiv) {
    CellPoint *p1 = c->points;
    for (CellPoint *p2 = p1->suiv; p1 != NULL && p2 != NULL;
         p1 = p1->suiv, p2 = p1->suiv) {
      SVGpoint(svg, p1->x, p1->y);
      SVGpoint(svg, p2->x, p2->y);
      SVGline(svg, p1->x, p1->y, p2->x, p2->y);
    }

    if (p1 != NULL) {
      SVGpoint(svg, p1->x, p1->y);
    }
  }

  SVGfinalize(svg);
}

double longueurChaine(CellChaine *c) {
  double somme = 0;
  for (CellPoint *p1 = c->points, *p2 = p1->suiv; p1 != NULL && p2 != NULL;
       p1 = p1->suiv, p2 = p2->suiv) {
    somme += sqrt(pow((p2->x - p1->x), 2) + pow((p2->y - p1->y), 2));
  }

  return somme;
}

double longueurTotale(Chaines *C) {
  double somme = 0;
  for (CellChaine *c = C->chaines; c != NULL; c = c->suiv) {
    somme += longueurChaine(c);
  }
  return somme;
}

int comptePointsTotal(Chaines *C) {
  int total = 0;
  for (CellChaine *c = C->chaines; c != NULL; c = c->suiv) {
    for (CellPoint *p = c->points; p != NULL; p = p->suiv) {
      total++;
    }
  }

  return total;
}

Chaines* generationAleatoire(int nbChaines,int nbPointsChaine,int xmax,int ymax){
	Chaines** c=(Chaines**)malloc(nbChaines * sizeof(Chaines*));
	*c->nbChaines = nbChaines;      
	*c->gamma = nPointschaine               
	for(int i=0;i<nbChaines;i++){		
		c[i]->chaines->numero = i;
		c[i]->chaines->points->x = rand()*xmax;
		c[i]->chaines->points->y = rand()*ymax;
	}
	int i = 0
	if(i<nbChaines){
		c[i]->chaines->suiv = c[i+1];
		c[i]->chaines->points->suiv = c[i+1]->chaines->points;
		i++;	
	} 
	c[nbChaines]->chaines->suiv = NULL;
	c[nbChaines]->chaines->points->suiv = NULL;
}
