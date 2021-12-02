//
// Created by Rafael on 02/12/2021.
//

#ifndef TP_POO_UI_H
#define TP_POO_UI_H

#include <geral.h>


class UI{
public:
    UI(Jogo& nJ) : j(nJ){};

    void start();
    void menu();

private:
    Jogo j;
};

#endif //TP_POO_UI_H
