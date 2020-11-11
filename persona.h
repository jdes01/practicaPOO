#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>
using std::string;

// la clase persona tiene parametros como el dni, nombre y apellidos, edad, etc

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

        //el constructor Persona recibe como parametro obligatorio el dni (y se lo asigna) y asigna el resto de parametros en
        //caso de ser recibidos.

        Persona( string dni="",        string nombre="",
                 string apellidos="",  string direccion="", 
                 string localidad="",  string provincia="", 
                 string pais="",       int    edad=0 ) : dni_(dni) {

                    nombre_    = nombre;
                    apellidos_ = apellidos;
                    edad_      = edad;
                    direccion_ = direccion;
                    localidad_ = localidad;
                    provincia_ = provincia;
                    pais_      = pais;
                }

        // funciones setXXXX() : asignan el parametro XXXX recibido por la funcion a la persona
        // funciones getXXXX() : devuelven el parametro XXXX de la persona 

        inline void setDNI       (string dni)       { dni_ = dni; }   
        inline void setNombre    (string nombre)    { nombre_ = nombre; }   
        inline void setApellidos (string apellidos) { apellidos_ = apellidos; }
        inline bool setEdad      (int edad)         { edad_=edad; if(edad>=0){return true;} return false; }
        inline void setDireccion (string direccion) { direccion_ = direccion; }  
        inline void setLocalidad (string localidad) { localidad_ = localidad; }
        inline void setProvincia (string provincia) { provincia_ = provincia; }
        inline void setPais      (string pais)      { pais_ = pais; }

        inline string getDNI ()       const {return dni_; };                  
        inline string getNombre ()    const {return nombre_; }
        inline string getApellidos () const { return apellidos_; } 
        inline int getEdad ()         const { return edad_; }
        inline string getDireccion () const { return direccion_; } 
        inline string getLocalidad () const { return localidad_; }
        inline string getProvincia () const { return provincia_; }
        inline string getPais () const { return pais_; }
          
        // funcion getApellidosyNombre() : devuelve ambos parametros concatenados de la forma " 'apellido', 'nombre' "

        inline string getApellidosyNombre () const { return apellidos_ + ", " + nombre_; }

        // funcion mayor() : devuelve true si es mayor de edad y false si es menor.

        inline bool mayor () { if(edad_>=18) return true; return false; }
};

#endif
