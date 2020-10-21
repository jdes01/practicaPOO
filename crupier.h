#include "persona.h" 

#ifndef CRUPIER_H
#define CRUPIER_H

#include <string>
#include <iostream>
using std::string;

class Crupier: private Persona{

    private: string codigoEmpleado_;

    public:

        Crupier(string codigoEmpleado = "", string dni="",       string nombre="",
                string apellidos="",        string direccion="", string localidad="", 
                string provincia="",        string pais="",      int edad=0){

                    codigoEmpleado_ = codigoEmpleado;                     
        }

};


#endif