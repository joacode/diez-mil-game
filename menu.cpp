#include<iostream>
#include<time.h>
#include"rlutil.h"

void showItem(const char* text, int posx, int posy, bool selected) {

    if (selected) {
        rlutil::setBackgroundColor(rlutil::LIGHTMAGENTA);
    }
    else {
        rlutil::setBackgroundColor(rlutil::BLACK);
    }

    rlutil::locate(posx, posy);
    std::cout << text << std::endl;
    rlutil::setBackgroundColor(rlutil::BLACK);
}

int menu() {
    int op = 1, y = 0;

    rlutil::hidecursor();

    do {

        rlutil::setColor(rlutil::YELLOW);
        rlutil::setBackgroundColor(rlutil::BLACK);

        showItem("JUEGO  SOLITARIO", 30, 10, y == 0);
        showItem(" JUEGO DE A DOS ", 30, 11, y == 1);
        showItem("MAXIMO  PUNTAJE ", 30, 13, y == 2);
        showItem("     SALIR      ", 30, 12, y == 3);

        rlutil::locate(28, 10 + y);
        std::cout << (char)126 << std::endl;

        int key = rlutil::getkey();
        switch (key)
        {
        case rlutil::KEY_UP:
            rlutil::locate(28, 10 + y);
            std::cout << " " << std::endl;
            y--;
            if (y < 0) {
                y = 0;
            }
            continue;

        case rlutil::KEY_DOWN:
            rlutil::locate(28, 10 + y);
            std::cout << " " << std::endl;
            y++;
            if (y > 2) {
                y = 2;
            }
            continue;

        case rlutil::KEY_SPACE:
            if (y == 0) {
                rlutil::cls();
                return op = 0;
            } else if (y == 1) {
                rlutil::cls();
                return op = 1;
            } else if (y == 2) {
                rlutil::cls();
                return op = 2;
            } else {
                rlutil::cls();
                return op = 3;
            }
        }

    } while (op != 0);

    std::cout << std::endl;
    return op;
}
