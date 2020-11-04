// Filename: ruleta.cc
// Description: Class of type Ruleta
#include "ruleta.h" 
#include "persona.h"
#include "jugador.h" 
#include <fstream> 
#include <string>
#include <iterator>

using namespace std;

bool numeroRojo(int numero){

        if( numero == 1  | 3  | 5  | 7  | 9  | 12 
                    | 14 | 16 | 18 | 19 | 21 | 23 
                    | 25 | 27 | 30 | 32 | 34 | 36  ) { return true;}

        else { return false;}
    }

bool numeroNegro(int numero){

        if( numero == 2  | 4  | 6  | 8  | 10 | 11 
                    | 13 | 15 | 17 | 20 | 22 | 24 
                    | 26 | 28 | 29 | 31 | 33 | 35  ) { return true;}

        else { return false;}
    }

bool Ruleta::setBanca(int banca){ 

    if (banca>0) {

        banca_ = banca;
        return true; 
    }
    return false;
}


bool Ruleta::setBola(int bola){

    if (bola>=0 && bola<=36) {

        bola_ = bola;
        return true;
    }
    return false;
}


bool Ruleta::addJugador(Jugador jugador){

    for(list<Jugador>::iterator i = jugadores_.begin(); i != jugadores_.end(); i++){

        if(i->getDNI()==jugador.getDNI()) return false;
    }

    jugadores_.push_back(jugador);
    
    fstream f;
    string filename = jugador.getDNI()+".txt";
    f.open(filename, ios::app);
    f.close(); 
    return true;
}


int Ruleta::deleteJugador(string dni){

    if(jugadores_.empty()) return -1;

    for(list<Jugador>::iterator i = jugadores_.begin(); i != jugadores_.end(); i++){

        if (i->getDNI() == dni){

            jugadores_.erase(i);
            return 1;
        }
    }
    return -2;
}


int Ruleta::deleteJugador(Jugador jugador){

    if(jugadores_.empty()) return -1;

    for(list<Jugador>::iterator i = jugadores_.begin(); i != jugadores_.end(); i++){

        if(i->getDNI()==jugador.getDNI()){
            jugadores_.erase(i);
            return 1;
        }
    }
    return -2;
}


void Ruleta::escribeJugadores(){

    std::fstream f;

    f.open("jugadores.txt", std::ios::out);

    for(list<Jugador>::iterator i = jugadores_.begin(); i != jugadores_.end(); i++){

        f<<i->getDNI()<<","<<
           i->getCodigo()<<","<< 
           i->getNombre()<<","<<
           i->getApellidos()<<","<<
           i->getEdad()<<","<<
           i->getDireccion()<<","<<
           i->getLocalidad()<<","<<
           i->getProvincia()<<","<<
           i->getPais()<<","<<
           i->getDinero()<<std::endl;
    }
    f.close();
}


void Ruleta::leeJugadores(){

    jugadores_.empty();

    std::fstream f;

    f.open("jugadores.txt", std::ios::in);
    
    char dni       [255], codigo    [255], nombre    [255],
         apellidos [255], edad      [255], direccion [255],
         localidad [255], provincia [255], pais      [255],
         dinero    [255];
    
    string str_dni,       str_codigo,    str_nombre,
           str_apellidos, str_edad,      str_direccion,
           str_localidad, str_provincia, str_pais;
    
    while ( f.getline(dni, 255, ',') ){

        f.getline(codigo,    255, ',');
        f.getline(nombre,    255, ',');
        f.getline(apellidos, 255, ',');
        f.getline(edad,      255, ',');
        f.getline(direccion, 255, ',');
        f.getline(localidad, 255, ',');
        f.getline(provincia, 255, ',');
        f.getline(pais,      255, ',');
        f.getline(dinero,    255, ',');
    }
    
}

void Ruleta::getPremios(){

    std::fstream f;
    std::string filename;

    for(std::list<Jugador>::iterator jugador = jugadores_.begin(); jugador != jugadores_.end(); jugador++){

        jugador->setApuestas();
        
        std::list<Apuesta> apuestas = jugador->getApuestas();

        for(std::list<Apuesta>::iterator a = apuestas.begin(); a != apuestas.end(); a++){

            switch (a->tipo){
            
            case 1:

                if(getBola() == stoi(a->valor)){

                    jugador->setDinero( jugador->getDinero() + (35 * a->cantidad) );
                    setBanca( getBanca() - (35 * a->cantidad) );
                }

                else{

                    jugador->setDinero( jugador->getDinero() - a->cantidad );
                    setBanca( getBanca() + a->cantidad );
                }

                break;
            
            case 2:

                if( a->valor == "rojo" ){

                    if( numeroRojo( getBola() ) ){
                        
                        jugador->setDinero( jugador->getDinero() + a->cantidad );
                        setBanca( getBanca() - a->cantidad );
                    }

                    else{

                        jugador->setDinero( jugador->getDinero() - a->cantidad );
                        setBanca( getBanca() + a->cantidad );
                    }
                }
            
                if( a->valor == "negro" ){

                    if( numeroNegro( getBola() ) ){
                        
                        jugador->setDinero( jugador->getDinero() + a->cantidad );
                        setBanca( getBanca() - a->cantidad );
                    }

                    else{

                        jugador->setDinero( jugador->getDinero() - a->cantidad );
                        setBanca( getBanca() + a->cantidad );
                    }
                }

                break;

            case 3:

                if( a->valor == "par" ){

                    if( getBola()%2 == 0 && getBola() != 0 ){
                        
                        jugador->setDinero( jugador->getDinero() + a->cantidad );
                        setBanca( getBanca() - a->cantidad );
                    }

                    else{

                        jugador->setDinero( jugador->getDinero() - a->cantidad );
                        setBanca( getBanca() + a->cantidad );
                    }
                }
            
                if( a->valor == "impar" ){

                    if( getBola()%2 == 0 && getBola() != 0  ){
                        
                        jugador->setDinero( jugador->getDinero() + a->cantidad );
                        setBanca( getBanca() - a->cantidad );
                    }

                    else{

                        jugador->setDinero( jugador->getDinero() - a->cantidad );
                        setBanca( getBanca() + a->cantidad );
                    }
                }

                break;

            case 4:

                if( a->valor == "alto" ){

                    if( getBola() >= 19 && getBola() <= 36 ){
                        
                        jugador->setDinero( jugador->getDinero() + a->cantidad );
                        setBanca( getBanca() - a->cantidad );
                    }

                    else{

                        jugador->setDinero( jugador->getDinero() - a->cantidad );
                        setBanca( getBanca() + a->cantidad );
                    }
                }
            
                if( a->valor == "bajo" ){

                    if( getBola() >= 1 && getBola() <= 18  ){
                        
                        jugador->setDinero( jugador->getDinero() + a->cantidad );
                        setBanca( getBanca() - a->cantidad );
                    }

                    else{

                        jugador->setDinero( jugador->getDinero() - a->cantidad );
                        setBanca( getBanca() + a->cantidad );
                    }
                }

                break;
            }
        
        }
    
    }

}