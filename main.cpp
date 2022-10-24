# include<iostream>
# include<cstdlib>
#include "rlutil.h"
#include <stdlib.h>
#include "math.h"

using namespace std;
using namespace rlutil;


int main() {
    char pName;
    int dados [6] = {0, 0, 0, 0, 0, 0};
    int dadosIguales = 0;

    cout << "Modo de juego 1 jugador" << endl;
    cout << "Ingrese nombre del jugador: ";
    cin >> pName;

    cout << "Space para tirar los dados o Escape para salir" << endl;

    char k = getkey();

    while (k != 0) {
        srand(time(NULL));

        if (k == KEY_SPACE) {
            for (int d = 0; d < 6; d++) {
                dados[d] = 1 + rand() % 6;
                cout << dados[d] << endl;
            }
        }

         int n = sizeof(dados)/sizeof(dados[0]);

        dadosIguales = 0;
        sort(dados, dados + n);

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if (i != j & i < j) {
                    cout  << "i != j para i: ";
                    cout << i << endl;
                    cout  << "i != j para j: ";
                    cout << j << endl;
                    if (dados[i] == dados[j]) {
                        dadosIguales++;
                        cout << " este se conto" << endl;
//                        cout << "dado en i: ";
//                        cout << dados[i] << endl;
//                        cout << "dado en j: ";
//                        cout << dados[j] << endl;
                    }
                }
            }
        }

        cout << "Cantidad de dados iguales: " + to_string(dadosIguales) << endl;

        cout << "Space para tirar los dados o Escape para salir" << endl;

        k = getkey();
    }

    cout << "Juego terminado" << endl;

    return 0;
}
