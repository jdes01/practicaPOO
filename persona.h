#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>
using std::string;

class Persona{

    private:

        string dni_;
        string nombre_;
        string apellidos_;
        int edad_;
        string direccion_;
        string localidad_;
        string provincia_;
        string pais_;

    public:

        Persona(string dni="",       string nombre="",    string apellidos="",
                string direccion="", string localidad="", string provincia="", 
                string pais="",      int edad=0){

                    dni_       = dni;
                    nombre_    = nombre;
                    apellidos_ = apellidos;
                    edad_      = edad;
                    direccion_ = direccion;
                    localidad_ = localidad;
                    provincia_ = provincia;
                    pais_      = pais;
                    
        }

        inline void   setDNI (string dni) { dni_ = dni; }
        inline string getDNI () {return dni_; };

        inline void   setNombre (string nombre) { nombre_ = nombre; }
        inline string getNombre () {return nombre_; }

        inline void   setApellidos (string apellidos) { apellidos_ = apellidos; }
        inline string getApellidos () { return apellidos_; }

        inline bool   setEdad (int edad) { edad_=edad; if(edad>=0){return true;} return false; }
        inline int    getEdad () { return edad_; }

        inline void   setDireccion (string direccion) { direccion_ = direccion; }
        inline string getDireccion () { return direccion_; }

        inline void   setLocalidad (string localidad) { localidad_ = localidad; }
        inline string getLocalidad () { return localidad_; }
 
        inline void   setProvincia (string provincia) { provincia_ = provincia; }
        inline string getProvincia () { return provincia_; }

        inline void   setPais (string pais) { pais_ = pais; }
        inline string getPais () { return pais_; }

        inline string getApellidosyNombre () { return apellidos_ + ", " + nombre_; }
  
        inline bool   mayor () { if(edad_>=18){return true;} return false; }
  

};

#endif
