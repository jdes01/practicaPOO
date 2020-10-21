#ifndef jugador_h
#define jugador_h

#include "persona.h" 

#include <string>
#include <iostream>
#include <list>
using std::string;


struct Apuesta{
    int tipo;
    int cantidad;
    string valor;
};

class Jugador: public Persona{

    private: 
    
    int dinero_;
    string codigo_;
    std::list<Apuesta> apuestas_; 

    public:

        Jugador(string codigo = 0,  string dni="",       string nombre="",
                string apellidos="", string direccion="", string localidad="", 
                string provincia="", string pais="",      int edad=0): Persona(dni, nombre, apellidos, edad, direccion, localidad, provincia, pais){

                    dinero_ = 1000;    
                    codigo_ = codigo;
        }

    void   setCodigo (string codigo) { codigo_ = codigo; }
    string getCodigo () { return codigo_; }

    void   setDinero (int dinero) { dinero_ = dinero; }
    int getDinero () { return dinero_; }
    
    };


#endif