#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//La tructure coniendra les arguments en version longue et en version courte
typedef struct Argument{
    char * optionL;
    char * optionC;
    char * valeur; 
}Argument;


//La liste simplement chainée qui a l'avantage de la fmexibilité au lieu d'un tableau
typedef struct ListeSc{
    
    void * valeur;
    struct ListeSc * suivant;  
    
}ListeSc;


//Les fonctions de la liste chainée et de la structure argument
ListeSc * initialiserListe();
Argument * initialiserArgument(char * optioncourte, char *optionLong , char * valeur);


void ajouter(ListeSc * liste, Argument * argument );
void viderliste(ListeSc * liste); 


ListeSc * genererArgument(int argc, char const *argv[]);
ListeSc * argumentpredefini();



//int taille(ListeSc * liste);


int verfieroption(char * option);
Argument * argumentExiste(ListeSc * liste, char * option);





