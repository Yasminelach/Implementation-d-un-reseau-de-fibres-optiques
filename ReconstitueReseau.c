#include <stdio.h>
#include <stdlib.h>
#include "Reseau.c"
#include "Chaine.c"



int main(int argc, char** argv){
    if(argc == 3){
        if(argv[2]=="0"){
            FILE* f =fopen(argv[1],"r");
            reconstitueReseauListe(lectureChaine(f));
        }
        if(argv[2]=="1")
        if(argv[2]=="2") 
        return 0;
    }
    return 1;
}