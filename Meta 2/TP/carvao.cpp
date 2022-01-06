//
// Created by user on 27/12/21.
//

#include "carvao.h"

Carvao::Carvao() : custoProducao(1), custoVenda(1), Recursos("Carvao"){}

double Carvao::vende(double quant) {
    return custoVenda*quant;
}

int Carvao::producao() {
    return custoProducao;
}