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

        int nLanzamientos_;
        int nJugadores_;
        int sumaDinero_;
        int profitBanca_;

        list<Jugador> jugadores_;
        Crupier crupier_;

    public:

        // el constructor de la ruleta recibe como parametro obligatorio el crupier (asignandolo al crupier encargado de la ruleta)
        // y de forma automatica inicia el valor de la bola a -1, el dinero de la banca a 1000000 y la semilla de la funcion srand()

        Ruleta(Crupier crupier) : crupier_(crupier){

            bola_ = -1;
            nLanzamientos_ = 0;
            sumaDinero_ = 0;
            banca_ = 1000000; 
            profitBanca_ = 0;
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
        
        bool setBola(int const &bola);
        bool setBanca(int banca);
        
        // funcion giraRuleta : le asigna a la bola un numero aleatorio entre 0 y 36

        inline void giraRuleta(){ bola_ = rand()%37; nLanzamientos_++;}

        bool addJugador(Jugador jugador);

        int deleteJugador(string dni);
        int deleteJugador(Jugador jugador);

        void escribeJugadores(); 
        void leeJugadores();  

        bool numeroRojo(int const &numero);
        bool numeroNegro(int const &numero);
        bool esPar(int const &valor);
        bool esAlto(int const &valor);

        void getEstadoRuleta(int &nJugadores, int &sumaDinero, int &numeroLanzamientos, int &profitBanca); 

};

#endif

