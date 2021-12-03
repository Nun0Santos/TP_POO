//
// Created by Rafael on 02/12/2021.
//

#include "geral.h"

void Jogo::gereIsland(const string& str) {
    island.executa(str);
}

string Jogo::gereDias() {
    return std::string();
}

void Jogo::criaIsland(int a, int b) {
    island.defineLin(a);
    island.defineCol(b);
    island.criaIlha();
}

string Jogo::mostraIsland() {
    return island.mostraIlha();
}
