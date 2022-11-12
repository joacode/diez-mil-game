# include<iostream>
#include "rlutil.h"
#include <cstdlib>
#include "menu.cpp"
#include "interfaz.cpp"

using namespace std;
using namespace rlutil;

class MaxPuntaje {
    private: int maxPuntaje;

    public:
        void setMaxPuntaje(int m) {
        maxPuntaje = m;
        }

        int getMaxPuntaje() {
            return maxPuntaje;
        }
};

class NombreMaxPuntaje {
    private: string nombreMaxPuntaje;

    public:
        void setNombreMaxPuntaje(string nombre) {
            nombreMaxPuntaje = nombre;
        }

        string getNombreMaxPuntaje() {
            return nombreMaxPuntaje;
        }
};

string pedirNombre(int indexJugadores, int current) {
    string pName;

    if (indexJugadores > 0 && current == 1) {
        cout << "INGRESE EL NOMBRE DEL JUGADOR 1: ";
        cin >> pName;
    } else if (indexJugadores > 0 && current == 2) {
        cout << "INGRESE EL NOMBRE DEL JUGADOR 2: ";
        cin >> pName;
    } else {
        cout << "INGRESE EL NOMBRE DEL JUGADOR: ";
        cin >> pName;
    }

    return pName;
}

int juego(int indexJugadores, MaxPuntaje& maxPuntaje, NombreMaxPuntaje& nombreMaxPuntaje) {
    char k;
    string msjPuntaje, nJugadores[2] = {"", "null"}, jGanador;
    int dados[6] = {0, 0, 0, 0, 0, 0}, puntaje[6] = {0, 0, 0, 0, 0, 0}, puntajesTotales[2] = {0, 0};
    int nRonda = 0, puntajeRonda, puntajeGanador;

    puntajeRonda = 0;

    nJugadores[0] = pedirNombre(indexJugadores, 1);
    if (indexJugadores == 1) {
        nJugadores[1] = pedirNombre(indexJugadores, 2);
    }

    nRonda++;
    k = pantallaTurno(nRonda, nJugadores, nJugadores[0], puntajesTotales);

    while (k != 'n') {
        rlutil::cls();

        for (int step = 0; step <= indexJugadores; step++) {
            srand(time(nullptr));

            // 3 tiros
            for (int nTiro = 1; nTiro <= 3; nTiro++) {
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

                        if (puntaje[0] == 1 && puntaje[1] == 1 && puntaje[2] == 1 && puntaje[3] == 1 &&
                            puntaje[4] == 1 &&
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

                    if (puntajeRonda < 50) {
                        puntajeRonda = 0;
                        msjPuntaje = "No obtuviste ningun juego!";
                    }

                    cout << endl;
                }

                cout << msjPuntaje + " +" << puntajeRonda << " PUNTOS" << endl;

                interfaz(nJugadores[step], nRonda, puntajesTotales[step], puntajeRonda, nTiro, msjPuntaje, dados);

                if (nTiro != 3) {
                    do {
                        cout << "CONTINUAR LANZANDO? (s/n): ";
                        cin >> k;
                    } while (k != 's' && k != 'n');

                    if (k == 'n') {
                        rlutil::cls();
                        break;
                    }
                } else {
                    cout << msjPuntaje + " +" << puntajeRonda << " PUNTOS" << endl;
                    interfaz(nJugadores[step], nRonda, puntajesTotales[step], puntajeRonda, nTiro, msjPuntaje, dados);

                    do {
                        cout << endl << endl << "SE ACABARON TUS TIROS! PRESIONA 's' PARA CONTINUAR... (s): ";
                        cin >> k;
                    } while (k != 's');
                }
            }


            if (puntajesTotales[step] < 10000 && nRonda < 10) {
                puntajesTotales[step] = puntajesTotales[step] + puntajeRonda;
            } else if (puntajesTotales[step] == 10000) {
                rlutil::cls();
                cout << "FIN DE LA PARTIDA!" << endl;
                cout << "JUEGO TERMINADO EN " << nRonda << " TURNOS" << endl;
                cout << "PUNTAJE GANADOR: " << nJugadores[step] << ", " << puntajesTotales[step] << " PUNTOS" << endl;
                return 0;
            }

            if (nRonda < 10) {
                if (step == 0) {
                    k = pantallaTurno(nRonda + 1, nJugadores, nJugadores[1], puntajesTotales);
                } else {
                    k = pantallaTurno(nRonda + 1, nJugadores, nJugadores[0], puntajesTotales);
                }
            }
        }
        nRonda++;
        if (nRonda > 10) {
            if (puntajesTotales[0] > puntajesTotales[1]) {
                jGanador = nJugadores[0];
                puntajeGanador = puntajesTotales[0];
            } else {
                jGanador = nJugadores[1];
                puntajeGanador = puntajesTotales[1];
            }
            rlutil::cls();
            cout << "FIN DE LA PARTIDA!" << endl;
            cout << "JUEGO TERMINADO EN " << nRonda - 1 << " TURNOS" << endl;
            cout << "PUNTAJE GANADOR: " << jGanador << ", " << puntajeGanador << " PUNTOS";

            if (puntajeGanador > maxPuntaje.getMaxPuntaje()) {
                maxPuntaje.setMaxPuntaje(puntajeGanador);
                nombreMaxPuntaje.setNombreMaxPuntaje(jGanador);
            }

            break;
        }
    }

    return 0;
}

int main() {
    MaxPuntaje maxPuntaje{};
    NombreMaxPuntaje nombreMaxPuntaje{};
    char j;
    int indexJugadores;

    maxPuntaje.setMaxPuntaje(0);
    nombreMaxPuntaje.setNombreMaxPuntaje("");

    while (true) {
        int m = menu();

        if (m == 0) {
            cout << "MODO DE JUEGO 1 JUGADOR" << endl;
            indexJugadores = 0;
            juego(indexJugadores, maxPuntaje, nombreMaxPuntaje);

            do {
                cout << "JUGAR OTRA VEZ? (s/n): " << endl;
                cin >> j;
            } while (j != 's' && j != 'n');
            if (j == 'n') break;

        } else if (m == 1) {
            cout << "MODO DE JUEGO 2 JUGADORES" << endl;
            indexJugadores = 1;
            juego(indexJugadores, maxPuntaje, nombreMaxPuntaje);
            do {
                cout << "JUGAR OTRA VEZ? (s/n): " << endl;
                cin >> j;
            } while (j != 's' && j != 'n');
            if (j == 'n') break;

        } else if (m == 2) {
            int maxPuntos = maxPuntaje.getMaxPuntaje();
            string nombreMaxPuntos = nombreMaxPuntaje.getNombreMaxPuntaje();

            if (maxPuntos == 0 && nombreMaxPuntos.empty()) {
                cout << "AUN NO HAY JUEGOS REGISTRADOS" << endl;
            }
            cout << "PUNTAJE MAXIMO: " << nombreMaxPuntos << ", " << maxPuntos << " PUNTOS" << endl;

            do {
                cout << "PRESIONA 's' PARA CONTINUAR... (s): ";
                cin >> j;
            } while (j != 's');
            if (j == 's') continue;
        } else {
            break;
        }
        rlutil::cls();
    }

    return 0;
}
