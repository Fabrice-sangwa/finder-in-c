#include <stdio.h>
#include <stdlib.h>
#include <finder.h>


int verfieroption(char * option){
    
    if(option == NULL){
        return 0;
    }
    return option[0] == '-';
}


