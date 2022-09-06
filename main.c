#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Le tableau argument contiendra les arguments passées en parametre
char * arguments[50];


int main(int argc, char const *argv[]){
    
    
    //on parcours tous les argements passés et on les insere dans notre tableau argument
    for (int i = 0; i < argc; i++)
    {
        //allocation dynamique de la memoire en fonction des caractère d echasue arguments
        arguments[i] = malloc(sizeof(strlen(argv[i] + 1)));
        strcpy(arguments[i], argv[i]); 

    
    }
    
    return 0;
}