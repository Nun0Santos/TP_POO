//
// Created by user on 27/12/21.
//

#include "ferro.h"

Ferro::Ferro() : Recursos("Ferro"), custoVenda(1){}

double Ferro::vende(double quant) {
    return custoVenda*quant;
}

Recursos *Ferro::duplica() {
    return new Ferro(*this);
}

