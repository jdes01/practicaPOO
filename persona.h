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

        void   setDNI (string dni) { dni_ = dni; }
        string getDNI () {return dni_; };

        void   setNombre (string nombre) { nombre_ = nombre; }
        string getNombre () {return nombre_; }

        void   setApellidos (string apellidos) { apellidos_ = apellidos; }
        string getApellidos () { return apellidos_; }

        bool   setEdad (int edad) { edad_=edad; if(edad>=0){return true;} return false; }
        int    getEdad () { return edad_; }

        void   setDireccion (string direccion) { direccion_ = direccion; }
        string getDireccion () { return direccion_; }

        void   setLocalidad (string localidad) { localidad_ = localidad; }
        string getLocalidad () { return localidad_; }

        void   setProvincia (string provincia) { provincia_ = provincia; }
        string getProvincia () { return provincia_; }

        void   setPais (string pais) { pais_ = pais; }
        string getPais () { return pais_; }
        
        string getApellidosyNombre () { return apellidos_ + ", " + nombre_; }
        bool   mayor () { }
  

};

#endif
