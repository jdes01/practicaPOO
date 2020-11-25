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
    sumatorio1_ += n;

    for (int i = 5; i > 1; i--) { ultimos1_[i] = ultimos1_[i-1]; }

    ultimos1_[0]=n;

    if ( (1<=n) && (n<=6) ){ d1_=n; return true; }
    return false;
}

bool Dados::setDado2(int n){ 
    
    contador2_++;
    sumatorio2_ += n;

    for (int i = 5; i > 1; i--) { ultimos2_[i] = ultimos2_[i-1]; }

    ultimos2_[0]=n;

    if ( (1<=n) && (n<=6) ){ d2_=n; return true; }
    return false;
}

void Dados::getUltimos1(int vector[]){

    for (int i = 0; i < 5; i++){ vector[i]=ultimos1_[i]; }   
}

void Dados::getUltimos2(int vector[]){

    for (int i = 0; i < 5; i++){ vector[i]=ultimos2_[i]; }
}




