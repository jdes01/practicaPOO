#ifndef DADOS_H
#define DADOS_H

// La clase dados contiene 2 dados y sus respectivos contadores (por cada tirada)
class Dados {

    private:

        int d1_;
        int d2_;
        int contador1_=0;
        int contador2_=0;

    public:

        Dados::Dados(){         //el constructor inicia la semilla de la funcion srand() y pone los dos dados a 1

            srand(time(NULL));    

            d1_=1;
            d2_=1;
        }
      
        inline int getDado1() const { return d1_; }  //devuelve el valor del primer dado
        inline int getDado2() const { return d2_; }  //devuelve el valor del segundo dado

        inline int getSuma() const { return d1_ + d2_ ;}  //devuelve el valor de la suma de los dos dados

        bool setDado1(int n);   //recibe un entero como único parámetro, y lo asigna al dado 1 si dicho entero está entre 1 y 6, 
        bool setDado2(int n);       //en cuyo caso devuelve true. En caso contrario no lo asigna y devuelve false
           
        void lanzamiento();  //obtiene un nuevo valor aleatorio para los dos dados

        inline int getLanzamientos1() const { return contador1_;}  //devuelven el contador de cada dado (su numero de lanzamientos)
        inline int getLanzamientos2() const { return contador2_;}  //

        inline int getMedia() const {return (d1_ + d2_)/2 ;}  //devuelve la media del valor actual de ambos dados

};

#endif