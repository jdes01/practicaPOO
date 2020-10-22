#include "jugador.h" 

#include <fstream>
#include <string>
using namespace std;
using std::string;
#define MAX 255


    void Jugador::setApuestas(){ 

        apuestas_.clear();
        string nombrefichero=getDNI()+".txt";
        fstream f;
        f.open(nombrefichero, fstream::in);

        if ( f.is_open() ){

            char tipo[MAX];
            char valor[MAX];
            char cantidad[MAX];

            while ( f.getline(tipo, MAX, ',') ) {

                f.getline(valor,    MAX, ',' );
                f.getline(cantidad, MAX, ',' );

                Apuesta a = { atoi(tipo), atoi(cantidad), valor };

                apuestas_.push_back(a);
            }
        }

        else { cout<<"ERROR AL ABRIR EL FICHERO";}

    }
    
