//
// Created by Rafael on 21/12/2021.
//

#include "centralEletrica.h"

CentralEletrica::CentralEletrica(ilha* i, int x, int y) : Edificio(i), custoConst(15), quantCarvao(100), tipo("elec"), x(x), y(y){}

string CentralEletrica::obtemTipo() {
    return tipo;
}

void CentralEletrica::vende() {
    Edificio::vende("Dinheiro", custoConst);
}

void CentralEletrica::produz(int i) {
    if(Edificio::gastaRecursos("Madeira", 1)){
        Edificio::aumentaRecursos("Eletricidade", 1);
        Edificio::aumentaRecursos("Carvao", 1);
    }
}

int CentralEletrica::obtemCusto() {
    return custoConst;
}
