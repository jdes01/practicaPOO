#ifndef CRUPIER_H
#define CRUPIER_H

#include "persona.h" 

#include <string>
#include <iostream>

using std::string;

// La clase crupier es una persona que tiene como parametros los de persona, ademas de un codigo personal.

class Crupier: public Persona{

    private: 
    
        string codigo_;

    public:

        // el constructor de la clase crupier recibe como parametros obligatorios el codigo y el dni de la persona, y asigna los
        // parametros de persona en caso de ser recibidos.

        inline Crupier (string dni,           string codigo,       string nombre="", 
                        string apellidos="",  int edad=0,          string direccion="", 
                        string localidad ="", string provincia="", string pais= "" ) : Persona(
                            
                            dni, nombre, apellidos, edad, direccion, localidad, provincia, pais){
           
                                codigo_=codigo;
                            };

        // funciones setXXXX() : asignan el parametro XXXX recibido por la funcion a la persona
        // funciones getXXXX() : devuelven el parametro XXXX de la persona

        inline void   setCodigo (string codigo) { codigo_ = codigo; }
        inline string getCodigo () const { return codigo_; }
};

#endif