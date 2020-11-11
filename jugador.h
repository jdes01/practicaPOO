#ifndef JUGADOR_H
#define JUGADOR_H

#include "persona.h" 

#include <fstream>
#include <string>
#include <list>

using std::string;
using namespace std;

// estructura Apuesta : con parametros 'tipo', 'cantidad' y 'valor'
struct Apuesta{
    
    int tipo;
    int cantidad;
    string valor;
};

// la clase Jugador es una persona que tiene como parametros los de persona ademas de un codigo identificador

class Jugador: public Persona{

    private: 
    
        int dinero_;
        string codigo_;

        list<Apuesta> apuestas_; 

        Persona persona;

    public:

        // el constructor de la clase jugador recibe como parametros obligatorios la persona y su codigo, como parametros opcionales
        // los parametros de la clase persona (nombre, dni, etc) que seran asignados en caso de ser recibidos. Además, inicializa
        // el 'dinero' del jugador a 1000.

        Jugador( string codigo = 0,   string dni="",       string nombre="",
                 string apellidos="", string direccion="", string localidad="", 
                 string provincia="", string pais="",      int    edad=0 ) : codigo_(codigo), persona(dni) { dinero_ = 1000; }

        // funciones setXXXX() : asignan el parametro XXXX recibido por la funcion a la persona
        // funciones getXXXX() : devuelven el parametro XXXX de la persona 

        inline string getCodigo () const { return codigo_; }
        inline int    getDinero () const { return dinero_; }

        inline list<Apuesta> getApuestas() const { return apuestas_;}

        inline void setCodigo (string codigo) { codigo_ = codigo; }
        inline void setDinero (int dinero)    { dinero_ = dinero; }
        
        // getApuestas() devuelve la lista de apuestas que el jugador lleva realizadas

        void setApuestas();
};


#endif