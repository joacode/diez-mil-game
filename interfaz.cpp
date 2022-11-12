# include<iostream>
#include "rlutil.h"

using namespace std;
using namespace rlutil;

char pantallaTurno(int nRonda, string nJugadores[2], string tocaJugar, int puntajesTotales[2]) {
    char k;
    rlutil::cls();
    cout << "RONDA N° " << nRonda << endl;

    if (nJugadores[1] != "null") {
        cout << "PROXIMO TURNO: " << tocaJugar << endl << endl;
    }

    if (nJugadores[1] != "null") {
        cout << "PUNTAJE " << nJugadores[0]  << ": " << puntajesTotales[0] << " PUNTOS" << endl;
        cout << "PUNTAJE " << nJugadores[1]  << ": " << puntajesTotales[1] << " PUNTOS" << endl << endl;
    } else {
        cout << "PUNTAJE " << nJugadores[0]  << ": " << puntajesTotales[0] << " PUNTOS" << endl << endl;
    }

    do {
        cout << "PRESIONA 's' PARA CONTINUAR... (s): ";
        cin >> k;
    } while (k != 's');

    rlutil::cls();
    return k;
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