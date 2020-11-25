#include "ruleta.h"
#include "crupier.h"
#include "jugador.h"
#include "persona.h"
#include "dados.h"

int main(){

    Crupier crupier("codigo", "dni", "hola");

    int opt;

    cout << endl << "----------------------------" << endl;
    cout << endl << "      Main Menu   " << endl;
    cout << endl << "----------------------------" << endl;
    cout << endl << "      1: adj   " << endl;
    cout << endl << "      Main Menu   " << endl;
    cout << endl << "      Main Menu   " << endl;
    cout << endl << "      Main Menu   " << endl;
    cout << endl << "----------------------------" << endl;

    cin >> opt;
    cout << "\n" << endl;

    switch (opt) 
    {
        case 1:
            cout << endl << crupier.getCodigo() << endl;
            break;
        case 2:
            //Code
            break;
        case 0:
            exit(1);
        default:
            break;
    }
}

