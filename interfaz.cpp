# include<iostream>
#include "rlutil.h"

using namespace std;
using namespace rlutil;

void mensajeTurno() {

}

void interfaz(string pName, int nRonda, int puntajeTotal, int puntajeRonda, int nTiro, string msjPuntaje, int dados[6]) {
    string saltoLinea = "----------------------------------------------------";
    string separador = " | ";

    rlutil::cls();
    cout << "TURNO DE " << pName;
    cout << separador;
    cout << "RONDA N° " << nRonda;
    cout << separador;
    cout << "PUNTAJE TOTAL " << puntajeTotal << " PUNTOS" << endl << endl;

    cout << saltoLinea << endl << endl;

    cout << "PUNTAJE DE LA RONDA: " << puntajeRonda << " PUNTOS" << endl;
    cout << "LANZAMIENTO N° " << nTiro << endl << endl;

    cout << saltoLinea << endl << endl;

    for (int i = 0; i < 6; i++) {
        cout << dados[i] << ", ";
    }

    cout << endl;

    cout << msjPuntaje + " +" << puntajeRonda << " PUNTOS" << endl;
}