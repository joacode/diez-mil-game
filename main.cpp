# include<iostream>
#include "rlutil.h"
#include <cstdlib>
#include "menu.cpp"
#include "interfaz.cpp"

using namespace std;
using namespace rlutil;

int unJugador() {
    char k;
    string pName, msjPuntaje;
    int dados[6] = {0, 0, 0, 0, 0, 0}, puntaje[6] = {0, 0, 0, 0, 0, 0};
    int nTiro, nRonda = 0, puntajeRonda, puntajeTotal = 0;

    cout << "MODO DE JUEGO 1 JUGADOR" << endl;
    cout << "INGRESE EL NOMBRE DEL JUGADOR: ";
    cin >> pName;

    cout << "PRESIONA 's' PARA LANZAR: ";
    cin >> k;

    while (k != 'n') {
        rlutil::cls();
        nRonda++;
        srand(time(nullptr));

        // 3 tiros
        for (nTiro = 1; nTiro <= 3; nTiro++) {
            puntajeRonda = 0;

            fill_n(puntaje, 6, 0);

            if (k == 's') {
                for (int i = 0; i < 6; i++) {
                    dados[i] = rand() % 6 + 1;

                    switch (dados[i]) {
                        case 1:
                            puntaje[0] = puntaje[0] + 1;
                            break;

                        case 2:
                            puntaje[1] = puntaje[1] + 1;
                            break;

                        case 3:
                            puntaje[2] = puntaje[2] + 1;
                            break;

                        case 4:
                            puntaje[3] = puntaje[3] + 1;
                            break;

                        case 5:
                            puntaje[4] = puntaje[4] + 1;
                            break;

                        case 6:
                            puntaje[5] = puntaje[5] + 1;
                            break;

                        default:
                            break;
                    }
                }

                for (int i = 0; i < 6; i++) {

                    if (puntaje[0] == 1 && puntaje[1] == 1 && puntaje[2] == 1 && puntaje[3] == 1 && puntaje[4] == 1 &&
                        puntaje[5] == 1) {
                        puntajeRonda = 1500;
                        msjPuntaje = "Obtuviste una escalera larga! + " + to_string(puntajeRonda);
                        break;
                    }

                    switch (i) {
                        case 0:
                            switch (puntaje[i]) {
                                case 1:
                                    puntaje[i] = puntaje[i] * 100;
                                    msjPuntaje = "Obtuviste un Juego de 1!";
                                    continue;

                                case 2:
                                    puntaje[i] = puntaje[i] * 100;
                                    msjPuntaje = "Obtuviste un Juego de 1!";
                                    continue;

                                case 3:
                                    puntaje[i] = 1000;
                                    msjPuntaje = "Obtuviste un Trio de 1!";
                                    continue;

                                case 4:
                                    puntaje[i] = 2000;
                                    msjPuntaje = "Obtuviste un Trio de 1 ampliado!";
                                    continue;

                                case 5:
                                    puntaje[i] = 2000;
                                    msjPuntaje = "Obtuviste un Trio de 1 ampliado!";
                                    continue;

                                case 6:
                                    puntaje[i] = 10000;
                                    msjPuntaje = "Obtuviste un Sexteto! Ganaste la partida!";
                                    continue;

                                default:
                                    continue;
                            }

                        case 1:
                            if (puntaje[i] >= 3) {
                                puntaje[i] = puntaje[i] * 100;
                                msjPuntaje = "Obtuviste un Trio " + to_string(i + 1) + "++!";
                            }
                            continue;

                        case 2:
                            if (puntaje[i] >= 3) {
                                puntaje[i] = puntaje[i] * 100;
                                msjPuntaje = "Obtuviste un Trio " + to_string(i + 1) + "++!";
                            }
                            continue;

                        case 3:
                            if (puntaje[i] >= 3) {
                                puntaje[i] = puntaje[i] * 100;
                                msjPuntaje = "Obtuviste un Trio " + to_string(i + 1) + "++!";
                            }
                            continue;

                        case 4:
                            if (puntaje[i] >= 3) {
                                puntaje[i] = puntaje[i] * 100;
                                msjPuntaje = "Obtuviste un Trio " + to_string(i + 1) + "++!";
                            } else if (puntaje[i] != 0 && puntaje[i] < 3 && puntaje[0] == 0) {
                                puntaje[i] = puntaje[i] * 50;
                                msjPuntaje = "Obtuviste un Juego de 5!";
                            }
                            continue;

                        case 5:
                            if (puntaje[i] >= 3) {
                                puntaje[i] = puntaje[i] * 100;
                                msjPuntaje = "Obtuviste un Trio " + to_string(i + 1) + "++!";
                            }
                            continue;

                        default:
                            puntajeRonda = 0;
                            msjPuntaje = "No obtuviste ningun juego!";
                            continue;
                    }
                }

                for (int i = 0; i < 6; i++) {
                    if (puntajeRonda < puntaje[i]) {
                        puntajeRonda = puntaje[i];
                    }
                }

                cout << endl;
            }

            cout << msjPuntaje + " +" << puntajeRonda << " PUNTOS" << endl;

            interfaz(pName, nRonda, puntajeTotal, puntajeRonda, nTiro, msjPuntaje, dados);

            if (nTiro != 3) {
                cout << "CONTINUAR LANZANDO? (s/n): ";
                cin >> k;
                if (k == 'n') {
                    rlutil::cls();
                    break;
                }
            } else {
                break;
            }
        }

        if (puntajeTotal < 10000 && nRonda < 10) {
            puntajeTotal = puntajeTotal + puntajeRonda;
        } else if (puntajeTotal == 10000 || nRonda == 10) {
            rlutil::cls();
            cout << "FIN DE LA PARTIDA!" << endl;
            cout << "JUEGO TERMINADO EN " << nRonda << " TURNOS" << endl;
            cout << "PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS" << endl;
            break;
        }

        cout << "RONDA FINALIZADA" << endl;
        cout << "PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS" << endl;

        cout << "EMPEZAR UN NUEVO TURNO? (s/n): ";
        cin >> k;
        if (k == 'n') {
            rlutil::cls();
            cout << "JUEGO TERMINADO EN " << nRonda << " TURNOS" << endl;
            cout << "PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS" << endl << endl;
            break;
        }
    }

    return 0;
}

int main() {
    char j;

    while (1) {
        int m = menu();

        if (m == 0 || m == 1) {
            unJugador();
            cout << "JUGAR OTRA VEZ? (s/n): " << endl;
            cin >> j;
            if (j == 'n') break;
        } else {
            break;
        }
        rlutil::cls();
    }

    return 0;
}
