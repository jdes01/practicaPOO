#ifndef RULETA_H 
#define RULETA_H

#include <list>
using namespace std;

#include "jugador.h"
#include "crupier.h"

class Ruleta { 
    
    private:

        int banca_;
        int bola_;
        list<Jugador> jugadores_;
        Crupier crupier_;

        int numeroJugadores_;
        int sumaDinero_;
        int numeroLanzamientos_;
        int profitBanca_;

    public:

    Ruleta(Crupier crupier) : crupier_(crupier){

        bola_ = -1; 
        banca_ = 1000000; 
        srand(time(NULL));
    }

    inline int getBanca() const { return banca_; } 
    inline int getBola() const { return bola_; }

    bool setBanca(int banca); 
    bool setBola(int bola);

    inline void setCrupier(Crupier crupier){ crupier_ = crupier; }
    inline Crupier getCrupier() const { return crupier_; }
    
    inline list<Jugador> getJugadores() const { return jugadores_; } 

    bool addJugador(Jugador jugador);

    int deleteJugador(string dni);
    int deleteJugador(Jugador jugador);

    void escribeJugadores(); 
    void leeJugadores();

    inline void giraRuleta(){ bola_ = rand()%37; } 

    void getPremios(); 

    bool numeroRojo(int numero);

    bool numeroNegro(int numero);

    // void getEstadoRuleta(int numeroJugadores, int sumaDinero){} 

};

#endif

