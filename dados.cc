#include <stddef.h>
#include "dados.h"
#include <cstdlib>
#include <ctime>

void Dados::lanzamiento(){

    contador1_++;
    contador2_++;

    d1_=(rand()%6)+1;
    d2_=(rand()%6)+1;
}



bool Dados::setDado1(int n){ 
    
    contador1_++;

    if ( (1<=n) && (n<=6) ){ d1_=n; return true; }
    return false;
}

bool Dados::setDado2(int n){ 
    
    contador2_++;
    
    if ( (1<=n) && (n<=6) ){ d2_=n; return true; }
    return false;
}




