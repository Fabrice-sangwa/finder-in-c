#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <finder.h>


int verfieroption(char * option){
    
    if(option == NULL){
        return 0;
    }
    return option[0] == '-';
}

Argument * initialiserArgument(char * optioncourte, char *optionLong , char * valeur){

    Argument *arg = (Argument *) malloc(sizeof(struct Argument)); 
    arg->optionC = optioncourte;
    arg->optionL = optionLong;
    arg->valeur = valeur; 

    return arg; 
}


ListeSc * initialiserListe(){

    ListeSc * liste = (ListeSc *) malloc(sizeof(struct ListeSc));
    liste->valeur = NULL;
    liste->suivant = NULL; 

    return liste; 

}



void ajouter(ListeSc * liste, Argument * argument ){

    if(liste == NULL)
        return;

    if(liste->valeur == NULL){
        liste->valeur = argument;
        
    }  else if (liste->suivant == NULL){

        ListeSc *  l = initialiserListe();
        l->valeur = argument;
        liste->suivant = l;
    

    } else {

        ListeSc * l = initialiserListe();
        l->valeur = argument;

        l->suivant = liste->suivant;
        liste->suivant = l;
       
    }
    
}


ListeSc * genererArgument(int argc, char const *argv[]){
    Argument * a;
    ListeSc *  l = argumentpredefini() ;
    if (argc < 2)
        return l;
    for (int i = 0; i < argc; i++)
    {
    
        if (verfieroption(argv[i])){
            
            a =  argumentExiste(l,argv[i]);
            if( a != NULL){
                if (!verfieroption(argv[i + 1])){


                }
            }
        }
    }
    


}

ListeSc * argumentpredefini(){

    ListeSc *  l = initialiserListe();

    ajouter(l, initialiserArgument("-o", "--octet", NULL));
    ajouter(l, initialiserArgument("-n", "--name", NULL));
    ajouter(l, initialiserArgument("-e", "--extension", NULL));
    ajouter(l, initialiserArgument("-t", "--temps", NULL));
    ajouter(l, initialiserArgument("-m", "--mega", NULL));
    ajouter(l, initialiserArgument("-f", "--fichier", NULL));
    ajouter(l, initialiserArgument("-d", "--destination", NULL));
    
    return l;
}

Argument * argumentExiste(ListeSc * liste, char * option){
    Argument * a;
    ListeSc * l = liste;
    if(l  == NULL || l->valeur == NULL)
        return NULL;
    
     

    if (l->suivant == NULL){
        a = (Argument*) l->valeur;
        if(strcmp(option, a->optionC) == 0 || strcmp(option, a->optionL) == 0){
            return a;
        } 

    }else{
       while (l != NULL){
        a = (Argument*) l->valeur;
        if(strcmp(option, a->optionC) == 0 || strcmp(option, a->optionL) == 0){
            return a;
        } 
        l = l->suivant;
       }
       
        
    }
    return NULL;


}


void viderliste(ListeSc * liste); 
int taille(ListeSc * liste);

