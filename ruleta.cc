// Filename: ruleta.cc
// Description: Class of type Ruleta
#include "ruleta.h" 
#include <fstream> 
#include <string>

bool Ruleta::setBanca(int banca){ 

    if(banca>0){
        banca_ = banca;
        return true; 
    }
    return false;
}

bool Ruleta::setBola(int bola){

    if(bola>=0 && bola<=36){
        bola_ = bola;
        return true;
    }
    return false;
}

bool Ruleta::addJuegador(const Jugador &j){

    for(std::list<jugador>::iterator i = jugadores_.begin(); i != jugadores_.end(); i++){

        if(i.getDNI()==j.getDNI()) return false;
    }

    jugadores_.push_back(j);
    std::fstream f;
    std::string filename = j.getDNI()+".txt";
    f.open(filename, std::ios::app);
    f.close(); 
    return true;
}

int Ruleta::deleteJugador(std::string dni){

    if(jugadores_:empty()) return -1;
    for(std::list<Jugador>::iterator i = jugadores_:begin(); i !=jugadores_.end(); i++;){

        if (i.getDNI()=dni){
            jugadores_:erase(i);
            return 1;
        }
    }
    return -2;
}

int Ruleta::deleteJugador(const Jugador &j){

    if(jugadores_.empty()) return -1;
    for(std::list<Jugador>::iterator i = jugadores_.begin(); i!=jugadores_:end(); i++){
        if(i.getDNI()==j.getDNI()){
            jugadores_.erase(i);
            return 1;
        }
    }
    return -2;
}


int Ruleta::deleteJugador(std::string dni){

    if(jugadores_.empty()) return -1;
    for(std::list<Jugador>::iterator i = jugadores_.begin(); i!=jugadores_:end(); i++){
        if(i.getDNI()==j.getDNI()){
            jugadores_.erase(i);
            return 1;
        }
    }
    return -2;
}

void Ruleta::escribeJugadores(){

    std::fstream f;
    f.open("jugadores.txt", std::ios::out);

    for(std::list<Jugador>::iterator i = jugadores_.begin(); i!=jugadores_.end(); i++){
        f<<i.getDNI()<<","<<
           i.getCodigo()<<","<< 
           i.getNombre()<<","<<
           i.getApellidos()<<","<<
           i.getEdad()<<","<<
           i.getDireccion()<<","<<
           i.getLocalidad()<<","<<
           i.getProvincia()<<","<<
           i.getPais()<<","<<
           i.getDinero()<<std::endl;
    }
    f.close();
}

void Ruleta::leeJugadores(){

    jugadores_.empty();
    std::fstream f;
    f.open("jugadores.txt", std::ios::in);
    char dni[255],       codigo[255],    nombre[255],
         apellidos[255], edad[255],      direccion[255],
         localidad[255], provincia[255], pais[255],
         dinero[255];
    
    std::string str_dni, str_codigo, str_nombre,
                str_apellidos, str_edad, str_direccion,
                str_localidad, str_provincia, str_pais,
    
    while (f.getline(dni, 255, ',')){

        f.getline(codigo, 255, ',');
        f.getline(nombre, 255, ',');
        f.getline(apellidos, 255, ',');
        f.getline(edad, 255, ',');
        f.getline(direccion, 255, ',');
        f.getline(localidad, 255, ',');
        f.getline(provincia, 255, ',');
        f.getline(pais, 255, ',');
        f.getline(dinero, 255, ',');
    }
    
}