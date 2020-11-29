#include "ruleta.h"
#include "crupier.h"
#include "jugador.h"
#include "persona.h"
#include "dados.h"

#include <list>
using namespace std;

int main(){

    Crupier crupier("1111", "crup1");
    Ruleta ruleta(crupier);

    Jugador jugador1("2222", "jug1");
    Jugador jugador2("3333", "jug2");

    string dni;
    list<Jugador> jugadores;

    int nLanzamientos, nJugadores, sumaDinero, profitBanca;

    int opt;

while (opt!=8) {

    cout << endl << "----------------------------" << endl;
    cout << endl << "      Main Menu   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << endl << "      1: Cargar jugadores   " << endl;
    cout << endl << "      2: Guardar jugadores   " << endl;
    cout << endl << "      3: Ver ruleta   " << endl;
    cout << endl << "      4: Girar ruleta   " << endl;
    cout << endl << "      5:    " << endl;
    cout << endl << "----------------------------" << endl;

    cin >> opt;
    cout << "\n" << endl;

    switch (opt) {

        case 1:
            
            ruleta.leeJugadores();
            break;

        case 2:
            
            ruleta.escribeJugadores();
            break;

        case 3:

            ruleta.getEstadoRuleta(nLanzamientos, nJugadores, sumaDinero, profitBanca);

            cout<<"Jugadores:"<<nJugadores<<endl;
            cout<<"Lanzamientos:"<<nLanzamientos<<endl;
            cout<<"Dinero:"<<sumaDinero<<endl;
            cout<<"Beneficio de la banca:"<<profitBanca<<endl;
            break;

        case 4:

            ruleta.giraRuleta();
            ruleta.getPremios();
            jugadores = ruleta.getJugadores();

            cout<<"Bola :"<<ruleta.getBola()<<endl;

            for(auto i = jugadores.begin(); i != jugadores.end(); i++){

                cout<<"El jugador con el dni "<<(i->getDNI())<<" ha ganado "<<(i->getDinero())<<"$"<<endl;
            }

            cout<<"La banca tiene "<<ruleta.getBanca()<<" $"<<endl;
    }


}

    return 0;
}

