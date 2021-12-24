//
// Created by Rafael on 02/12/2021.
//

#ifndef TP_POO_JOGO_H
#define TP_POO_JOGO_H

#include "geral.h"

using namespace std;

class ilha;

class Jogo{
public:
    void criaIsland(int a, int b);
    string gereIsland(const string& str);
    string gereDias(const string& str);
    string mostraIsland();

private:
    ilha* island;
};


#endif //TP_POO_JOGO_H
