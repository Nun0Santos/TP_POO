//
// Created by user on 27/12/21.
//

#include "eletricidade.h"

Eletricidade::Eletricidade() : custoVenda(1.5), custoProducao(1), Recursos("Electricidade"){}

double Eletricidade::vende(double quant) {
    return custoVenda*quant;
}

int Eletricidade::producao() {
    return custoProducao;
}