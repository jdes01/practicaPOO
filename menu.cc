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

    int opt=0;

while (opt!=7) {

    cout << endl << "----------------------------" << endl;
    cout << endl << "      Main Menu   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << endl << "      1: Cargar jugadores   " << endl;
    cout << endl << "      2: Guardar jugadores   " << endl;
    cout << endl << "      3: Ver ruleta   " << endl;
    cout << endl << "      4: Girar ruleta   " << endl;
    cout << endl << "      5: Eliminar jugador   " << endl;
    cout << endl << "      6: Añadir jugador   " << endl;
    cout << endl << "      7: Salir   " << endl;
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
            break;

        case 5:

            cout<<"Dni del jugador a eliminar:"<<endl;
            cin>>dni;

            if(ruleta.deleteJugador(dni) == 1) { cout<<"Eliminado"<<endl; }
            if(ruleta.deleteJugador(dni) == -1){ cout<<"Lista vacia"<<endl; }
            if(ruleta.deleteJugador(dni) == -2){ cout<<"Jugador no encontrado"<<endl; }
            break;

        case 6:

            ruleta.addJugador(jugador1);
            ruleta.addJugador(jugador2);

            cout<<"jugadores añadidos"<<endl;   
            break;

        case 7:

            cout<<"fin del programa"<<endl;
            break;

        default:
            break;    
    }


}

    return 0;
}

