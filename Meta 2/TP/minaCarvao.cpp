//
// Created by Rafael on 21/12/2021.
//

#include "minaCarvao.h"

MinaCarvao::MinaCarvao(ilha* i, int x, int y) : Edificio(i), custoConst(10), custoSubs(10), nivel(1), upgradeDinheiro(10), upgradeRecurso(1), quantProd(2), probDesabar(10), quantArmazenamento(100), tipo("mnC"), x(x), y(y){}

void MinaCarvao::melhora() {
    if(nivel <= 5){
        ++nivel;
        ++quantProd;
        quantArmazenamento += 10;
    }
}

string MinaCarvao::obtemTipo() {
    return tipo;
}

void MinaCarvao::vende() {
    Edificio::aumentaRecursos("Dinheiro", custoConst);
}

int MinaCarvao::obtemCusto() {
    return custoConst;
}

int MinaCarvao::obtemCustoSubs() {
    return custoSubs;
}

void MinaCarvao::produz() {
    if(!Edificio::procuraTrabalhador(x, y, "O")) return;

}
