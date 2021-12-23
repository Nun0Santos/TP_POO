//
// Created by Rafael on 21/12/2021.
//

#include "minaFerro.h"
#include <random>


MinaFerro::MinaFerro(Zona* z) : Edificio(z), custoConst(10), custoSubs(10), nivel(1), upgradeDinheiro(15), upgradeRecurso(1), quantProd(2), probDesabar(15), quantArmazenamento(100), tipo("minaFerro"){}

void MinaFerro::melhora() {
    if(nivel <= 5){
        ++nivel;
        ++quantProd;
        quantArmazenamento += 10;
    }
}

void MinaFerro::desaba() {//isto está mal feito
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(1,probDesabar);

    if(dist6(rng) == 1){

    }

}

string MinaFerro::obtemTipo() {
    return tipo;
}


