#include "ruleta.h" 
#include "persona.h"
#include "jugador.h" 

#include <fstream> 
#include <string>      
#include <iterator>

using namespace std;

// recibe un numero y devuelve true o false en funcion de si este es rojo o no en la ruleta

bool Ruleta::numeroRojo(int numero){

        if (numero == 1  || 3  || 5  || 7  || 9  || 12 
                   || 14 || 16 || 18 || 19 || 21 || 23 
                   || 25 || 27 || 30 || 32 || 34 || 36  ) { return true;}

        else { return false;}
    }

// recibe un numero y devuelve true o false en funcion de si este es negro o no en la ruleta

bool Ruleta::numeroNegro(int numero){

        if( numero == 2  || 4  || 6  || 8  || 10 || 11 
                   || 13 || 15 || 17 || 20 || 22 || 24 
                   || 26 || 28 || 29 || 31 || 33 || 35  ) { return true;}

        else { return false;}
    }


bool Ruleta::setBanca(int banca){ 

    if (banca>0) {

        banca_ = banca;
        return true; 
    }

    return false;
}


bool Ruleta::setBola(int bola, int * nLanzamientosBola_){


    if (bola>=0 && bola<=36) {

        * nLanzamientosBola_ ++;
        bola_ = bola;
        return true;
    }

    return false;
}

// funcion addJugador : esta recibe un 'jugador', compara con la lista 'jugadores' de la partida (ruleta) actual, 
// añadiendolo e caso de no existir. Devolvera true si fue añadido con exito y false si ya existia en la lista.
//

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

// funcion deleteJugador : recibe el dni de un 'jugador', busca en la lista de 'jugadores' y devuelve -1 si la lista esta vacia,
// 1 si el jugador aparecia en la lista (ademas de borrarlo), y -2 si la lista no esta vacia pero no encuentra al jugador en esta.

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

// funcion deleteJugador : recibe un 'jugador', busca en la lista de 'jugadores' y devuelve -1 si la lista esta vacia,
// 1 si el jugador aparecia en la lista (ademas de borrarlo), y -2 si la lista no esta vacia pero no encuentra al jugador en esta.

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

// funcion escribeJugadores : abre el fichero "jugadores.txt" y escribe todos los atributos de dicho jugador (tanto los de jugador
// como los de persona).

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

// abre el archivo "jugadores.txt" de la ruleta (partida) actual e imprime los jugadores con sus atributos.

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


void Ruleta::getPremios() {

    std::fstream f;
    std::string filename;

    // recorre la lista de jugadores

    for(std::list<Jugador>::iterator jugador = jugadores_.begin(); jugador != jugadores_.end(); jugador++){

        // cada jugador añade sus apuestas a la lista de apuestas

        jugador->setApuestas();
        
        std::list<Apuesta> apuestas = jugador->getApuestas();

        // recorre la lista de apuestas

        for(std::list<Apuesta>::iterator a = apuestas.begin(); a != apuestas.end(); a++){

            // en funcion del 'tipo' de apuesta

            switch (a->tipo){
            
            case 1:

                // si la bola cae en el numero que coincide con el valor de la apuesta el jugador gana 35 * cantidad apostada

                if(getBola() == stoi(a->valor)){

                    jugador->setDinero( jugador->getDinero() + (35 * a->cantidad) );
                    setBanca( getBanca() - (35 * a->cantidad) );
                }

                // si no cae en el numero elegido perdera toda la cantidad apostada (ganada por la banca)

                else{

                    jugador->setDinero( jugador->getDinero() - a->cantidad );
                    setBanca( getBanca() + a->cantidad );
                }

                break;
            
            case 2:

                // si la bola cae en un numero con el color rojo el jugador gana toda la cantidad, si no la pierde

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

                // si la bola cae en un numero con el color negro el jugador gana toda la cantidad, si no la pierde
            
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

                // si la bola cae en un numero par el jugador se lleva todo el dinero, si no lo pierde todo

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
            
                // si la bola cae en un numero par el jugador se lleva todo el dinero, si no lo pierde todo

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

                // si el jugador aposto por que el valor seria alto y este supera o iguala los 19, se lleva todo el dinero apostado

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
            
                // si el jugador aposto por que el valor seria bajo y este es menor o igual que 18, se lleva todo el dinero apostado

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


void Ruleta::getEstadoRuleta(int *numeroJugadores = 0, int *sumaDinero = 0, int *numeroLanzamientos = 0, int *profitBanca = 0){

    *numeroJugadores = jugadores_.size();
    
    for(std::list<Jugador>::iterator jugador = jugadores_.begin(); jugador != jugadores_.end(); jugador++){

        *sumaDinero = *sumaDinero + jugador->getDinero();
        
    }
    
    *sumaDinero = *sumaDinero + banca_;

    *numeroLanzamientos = nLanzamientosBola_;

    *profitBanca = banca_ - 1000000;
}