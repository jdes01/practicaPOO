#ifndef CONTADOR_H 
#define CONTADOR_H

#include <list>

using namespace std;

class Contador { 
    
    private:

        int valor_;
        int min_;
        int max_;

        list<Contador> lista_;

        void comprobar();

    public:

        Contador(int valor = 0, int min = 0, int max = 1000);

        inline int get() const {return valor_;}

        Contador operator=(const int &n);
        Contador operator=(const Contador &contador);

        Contador operator++(int);  //Aumenta y devuelve
        Contador operator++(void); //Devuelve y aumenta
        
        Contador operator--(int);
        Contador operator--(void);

        Contador operator+(const int &n);                               
        friend Contador operator+(const int &n, const Contador &x);     

        Contador operator-(const int &n);                               
        friend Contador operator-(const int &n, const Contador &contador);     

        bool undo(const int &n=1);                                                          
};

#endif
