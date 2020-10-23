#ifndef persona_h
#define persona_h

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
                string pais="",      int edad=0) : dni_(dni) {

                    nombre_    = nombre;
                    apellidos_ = apellidos;
                    edad_      = edad;
                    direccion_ = direccion;
                    localidad_ = localidad;
                    provincia_ = provincia;
                    pais_      = pais;
                    
        }

        inline void   const setDNI (string dni) { dni_ = dni; }
        inline string const getDNI () {return dni_; };
  
        inline void   const setNombre (string nombre) { nombre_ = nombre; }
        inline string const getNombre () {return nombre_; }
  
        inline void   const setApellidos (string apellidos) { apellidos_ = apellidos; }
        inline string const getApellidos () { return apellidos_; }
  
        inline bool   const setEdad (int edad) { edad_=edad; if(edad>=0){return true;} return false; }
        inline int    const getEdad () { return edad_; }
  
        inline void   const setDireccion (string direccion) { direccion_ = direccion; }
        inline string const getDireccion () { return direccion_; }
  
        inline void   const setLocalidad (string localidad) { localidad_ = localidad; }
        inline string const getLocalidad () { return localidad_; }
  
        inline void   const setProvincia (string provincia) { provincia_ = provincia; }
        inline string const getProvincia () { return provincia_; }
  
        inline void   const setPais (string pais) { pais_ = pais; }
        inline string const getPais () { return pais_; }
          
        inline string const getApellidosyNombre () { return apellidos_ + ", " + nombre_; }
        inline bool   const mayor () { if(edad_>=18) return true; return false; }
  

};

#endif
