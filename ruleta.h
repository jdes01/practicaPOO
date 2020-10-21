// Filename: ruleta.h
// Description: Class of type Ruleta

#ifndef RULETA_H 
#define RULETA_H
#include <list>

class Ruleta{ 
    
    private:

        int banca_;
        int bola_;
        std::list<Jugador> jugadores_; Crupier crupier_;

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

    inline Crupier getCrupier() const { return crupier_; }
    inline void setCrupier(const Crupier &crupier){ crupier_ = crupier; }
    inline std::list<Jugador> getJugadores() 
    const { return jugadores_; } 

    bool addJugador(const Jugador &j);
    int deleteJugador(std::string dni);
    int deleteJugador(const Jugador &j);
    void escribeJugadores(); 
    void leeJugadores();
    void giraRuleta(){ bola_ = rand()%37; } 
    void getPremios();

};

#endif

