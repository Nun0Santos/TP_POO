//
// Created by user on 27/12/21.
//

#include "barraAco.h"

BarraAco::BarraAco() : custoVenda(2), custoCarvao(0.5), custoFerro(1.5), Recursos("BarraAco"){}

double BarraAco::vende(double quant) {
    return custoVenda*quant;
}

double BarraAco::producaoBAC() {
    return custoCarvao;
}

double BarraAco::producaoBAF() {
    return custoFerro;
}
