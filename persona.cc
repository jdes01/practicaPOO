#include "persona.h"
#include <string>

Persona::Persona( string dni,        string nombre,
                  string apellidos,  int    edad, 
                  string direccion,  string localidad, 
                  string provincia,  string pais ){ 
                      
                     dni_       = dni; 
                     nombre_    = nombre;
                     apellidos_ = apellidos;
                     edad_      = edad;
                     direccion_ = direccion;
                     localidad_ = localidad;
                     provincia_ = provincia;
                     pais_      = pais;
                }