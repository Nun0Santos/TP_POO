//
// Created by user on 27/12/21.
//

#include "madeira.h"

Madeira::Madeira() : Recursos("Madeira"), custoVenda(1){}

double Madeira::vende(double quant) {
    return custoVenda*quant;
}
