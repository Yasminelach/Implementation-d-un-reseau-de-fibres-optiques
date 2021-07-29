#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Chaine.h"
#include "Chaine.c"

int main(){
    FILE *f = fopen("00014_burma.cha","r");
    afficheChainesSVG(lectureChaine(f),"instance_1");
}