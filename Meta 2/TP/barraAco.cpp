//
// Created by user on 27/12/21.
//

#include "barraAco.h"

BarraAco::BarraAco() : custoVenda(2), custoCarvao(0.5), custoFerro(1.5), Recursos("BarraAco", 0){}

double BarraAco::vende(double quant) {
    return custoVenda*quant;
}

double BarraAco::producaoBAC() {
    return custoCarvao;
}

double BarraAco::producaoBAF() {
    return custoFerro;
}

Recursos *BarraAco::duplica() {
    return new BarraAco(*this);
}
