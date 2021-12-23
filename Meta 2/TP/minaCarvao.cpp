//
// Created by Rafael on 21/12/2021.
//

#include "minaCarvao.h"

MinaCarvao::MinaCarvao(Zona* z) : Edificio(z), custoConst(10), custoSubs(10), nivel(1), upgradeDinheiro(10), upgradeRecurso(1), quantProd(2), probDesabar(10), quantArmazenamento(100), tipo("minaCarvao"){}

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