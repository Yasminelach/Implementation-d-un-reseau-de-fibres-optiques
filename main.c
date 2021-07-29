#include "ArbeQuat.h"
#include <stdio.h>
#include < time.h >


int main(int argc,char** argv){
	clock_t temps_initial ;
	clock_t temps_final ;
	double temps_cpu ;fct ( n ) ;

	//Récupérer Chaines
	File *f = fopen(argv[0],"r");

	temps_initial = clock () ; //Nombre de ‘‘ticks’’ consomm’es par le programme jusqu’ici
	Chaines* c = lectureChaines(f);
 	temps_final = clock () ; //Nombre de ‘‘ticks’’ consomm’es par le programme jusqu’ici
	temps_cpu = (( double ) ( temps_final - temps_initial ) ) / CLOCKS_PER_SEC ;
	printf (”%d %f ”,n , temps_cpu ) ;

	//3-ReconstitueReseauListe
	temps_initial = clock () ; //Nombre de ‘‘ticks’’ consomm’es par le programme jusqu’ici
	Reseau* R = reconstitueReseauListe(c);	
 	temps_final = clock () ; //Nombre de ‘‘ticks’’ consomm’es par le programme jusqu’ici
	temps_cpu = (( double ) ( temps_final - temps_initial ) ) / CLOCKS_PER_SEC ;
	printf (”%d %f ”,n , temps_cpu ) ;
	
	//2-reconstitueReseauHachage
	temps_initial = clock () ; //Nombre de ‘‘ticks’’ consomm’es par le programme jusqu’ici
	Reseau* R = reconstitueReseauHachage(c,m);
 	temps_final = clock () ; //Nombre de ‘‘ticks’’ consomm’es par le programme jusqu’ici
	temps_cpu = (( double ) ( temps_final - temps_initial ) ) / CLOCKS_PER_SEC ;
	printf (”%d %f ”,n , temps_cpu ) ;

	//3-reconstitueReseauArbre
	temps_initial = clock () ; //Nombre de ‘‘ticks’’ consomm’es par le programme jusqu’ici
	Reseau* R = reconstitueReseauArbre(c);
 	temps_final = clock () ; //Nombre de ‘‘ticks’’ consomm’es par le programme jusqu’ici
	temps_cpu = (( double ) ( temps_final - temps_initial ) ) / CLOCKS_PER_SEC ;
	printf (”%d %f ”,n , temps_cpu ) ;
}