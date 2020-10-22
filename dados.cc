#include <stddef.h>
#include "dados.h"
#include <cstdlib>
#include <ctime>

Dados::Dados(){ srand(time(NULL));     
    d1_=1;
    d2_=1;
}

void Dados::lanzamiento(){

    d1_=(rand()%6)+1;
    d2_=(rand()%6)+1;
    contador1_++;
    contador2_++;
}

int Dados::getDado1(){ return d1_; }
int Dados::getDado2(){ return d2_; }

bool Dados::setDado1(int n){ 
    
    if ( (1<=n) && (n<=6) ){ d1_=n; return true; }
    return false;
    contador1_++;

}

bool Dados::setDado2(int n){ 
    
    if ( (1<=n) && (n<=6) ){ d2_=n; return true; }
    return false;
    contador2_++;

}

int Dados::getSuma(){ return d1_ + d2_ ;}

int Dados::getLanzamientos1(){ return contador1_;}
int Dados::getLanzamientos2(){ return contador2_;}

int Dados::getMedia(){return (d1_ + d2_)/2 ;}


