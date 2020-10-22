// dados.h
// La clase dados representa el lanzamiendo de 2 dados

#ifndef DADOS_H
#define DADOS_H

class Dados
{
    private:
        int d1_;
        int d2_;
        int contador1_=0;
        int contador2_=0;
    public:
        Dados(); //el constructor no devuelve nada
        int  getDado1(); //devuelve el valor del primer dado
        int  getDado2(); //devuelve el valor del segundo dado
        bool setDado1(int n); //recibe un entero como único parámetro, y lo asigna al dado 1 si dicho entero está entre 1 y 6, en cuyo caso devuelve true. En caso contrario no lo asigna y devuelve false
        bool setDado2(int n); //igual a la anterior para el segundo dado.
        int  getSuma(); //devuelve el valor de la suma de los dos dados
        void lanzamiento(); //obtiene un nuevo valor aleatorio para los dos dados
        int getLanzamientos1();
        int getLanzamientos2();
        int getMedia();

};

#endif