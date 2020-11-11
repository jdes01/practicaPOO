#ifndef RULETA_H 
#define RULETA_H

#include "jugador.h"
#include "crupier.h"
#include <list>

using namespace std;

// La clase ruleta describe el funcionamiento de la ruleta del casino. Tiene como parametros a la 'banca' (dinero que esta posee),
// la bola con la que se juega (valor de donde esta cae)
// Ademas, cuenta con una lista de jugadores (cada uno una 'persona' 'jugador') y un crupier (cada uno una 'persona' 'crupier').

class Ruleta { 
    
    private:

        int banca_;
        int bola_;
        int nLanzamientosBola_;

        list<Jugador> jugadores_;
        Crupier crupier_;

    public:

        // el constructor de la ruleta recibe como parametro obligatorio el crupier (asignandolo al crupier encargado de la ruleta)
        // y de forma automatica inicia el valor de la bola a -1, el dinero de la banca a 1000000 y la semilla de la funcion srand()

        Ruleta(Crupier crupier) : crupier_(crupier){

            bola_ = -1;
            nLanzamientosBola_ = 0;
            banca_ = 1000000; 
            srand(time(NULL));
        }

        // funciones setXXXX() : asignan el parametro XXXX recibido por la funcion a la persona
        // funciones getXXXX() : devuelven el parametro XXXX de la persona

        inline int     getBanca ()  const { return banca_; }
        inline Crupier getCrupier() const { return crupier_; }
        inline int     getBola ()   const { return bola_; }

        void getPremios();

        inline list<Jugador> getJugadores () const { return jugadores_; }

        inline void setCrupier (Crupier crupier) { crupier_ = crupier; }
        
        bool setBola(int bola, int *nLanzamientosBola_);
        bool setBanca(int banca);
        
        // funcion giraRuleta : le asigna a la bola un numero aleatorio entre 0 y 36

        inline void giraRuleta(){ bola_ = rand()%37; }

        bool addJugador(Jugador jugador);

        int deleteJugador(string dni);
        int deleteJugador(Jugador jugador);

        void escribeJugadores(); 
        void leeJugadores();  

        bool numeroRojo(int numero);
        bool numeroNegro(int numero);

        void getEstadoRuleta(int *numeroJugadores, int *sumaDinero, int *numeroLanzamientos, int *profitBanca); 

};

#endif

