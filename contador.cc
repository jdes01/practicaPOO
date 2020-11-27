#include "contador.h"

Contador::Contador(int valor, int min, int max) {

    if( valor < min || valor > max || min>max ) { valor =0; min = 0; max = 1000; }

    valor_ = valor;
    min_ = min;
    max_ = max;

    lista_.push_back(*this);
} 

void Contador::comprobar() {

    if( valor_ > max_ ) { valor_ = max_; }
    if( valor_ < min_ ) { valor_ = min_; }

    lista_.push_back(*this);
}

Contador Contador::operator=(const int &n) {

    this->valor_ = n;

    comprobar();
    return *this;
}

Contador Contador::operator=(const Contador &contador) {

    this->valor_=contador.valor_;                       
    this->min_=contador.min_;     
    this->max_=contador.max_;

    comprobar();

    this->lista_ = contador.lista_;
    lista_.push_back(*this);

    return *this;
}

Contador Contador::operator++(void) {

    ++this->valor_;

    comprobar();
    return *this;
}

Contador Contador::operator++(int) {

    Contador aux = *this;

    ++this->valor_;    

    comprobar();
    return aux;                                     
}

Contador Contador::operator--(void) { 

    --this->valor_;   

    comprobar();
    return *this;
}

Contador Contador::operator--(int) {

    Contador aux = *this;

    --this->valor_;

    comprobar();
    return aux;
}

Contador Contador::operator+(const int &n) {

    this->valor_ = this->valor_ + n;

    comprobar();
    return *this;
}

Contador operator+(const int &n, const Contador &contador) {

    Contador aux;

    aux.valor_ = n + contador.valor_;                      
    aux.max_ = contador.max_;                              
    aux.min_ = contador.min_;  

    aux.comprobar();
    return aux;
}

Contador Contador::operator-(const int &n) {

    this->valor_ = this->valor_ - n;                

    comprobar();
    return *this;
}

Contador operator-(const int &n, const Contador &contador) {

    Contador aux;

    aux.valor_ = n - contador.valor_;                      
    aux.max_ = contador.max_;                              
    aux.min_ = contador.min_;                              

    aux.comprobar();
    return aux;
}

bool Contador::undo(const int &n) {

    if ( n>= (int)lista_.size() || n<1 ) return false;
    
    for(int i=0; i<n; i++) lista_.pop_back();
    
    *this = lista_.back();                          
    return true;
}