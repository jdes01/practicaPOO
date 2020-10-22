#ifndef crupier_h
#define crupier_h

#include "persona.h" 

#include <string>
#include <iostream>
using std::string;

class Crupier: public Persona{

    private: 
    
        string codigo_;
        Persona persona;

    public:

        Crupier( string codigo = "",
                 string dni="",
                 string nombre="",
                 string apellidos="",
                 string direccion="",
                 string localidad="",
                 string provincia="",
                 string pais="",
                 int edad=0 ) : codigo_(codigo), persona(dni) { }

        inline void   setCodigo (string codigo) { codigo_ = codigo; }
        inline string getCodigo ()              { return codigo_; }

};


#endif