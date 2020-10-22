#ifndef jugador_h
#define jugador_h

#include "persona.h" 

#include <fstream>
#include <string>
#include <list>
using std::string;
using namespace std;


struct Apuesta{
    int tipo;
    int cantidad;
    string valor;
};

class Jugador: public Persona{

    private: 
    
        int dinero_;
        string codigo_;
        list<Apuesta> apuestas_; 
        Persona persona;

    public:

        Jugador( string codigo = 0,
                 string dni="",
                 string nombre="",
                 string apellidos="",
                 string direccion="",
                 string localidad="", 
                 string provincia="",
                 string pais="",
                 int edad=0 ) : codigo_(codigo), persona(dni) { dinero_ = 1000; }

    void   setCodigo (string codigo) { codigo_ = codigo; }
    string getCodigo () { return codigo_; }

    int    getDinero () { return dinero_; }
    void   setDinero (int dinero) { dinero_ = dinero; }

    list<Apuesta> getApuestas(){ return apuestas_;}
    void setApuestas(){ }
    
    };


#endif