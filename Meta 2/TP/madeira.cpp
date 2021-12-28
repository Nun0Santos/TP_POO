//
// Created by user on 27/12/21.
//

#include "madeira.h"

Madeira::Madeira() : custoVenda(1), quantidade(0), tipo("Madeira"){}

int Madeira::vende(int quant) {
    if(quant > quantidade){
        return -1;
    }

    quantidade -= quant;
    return custoVenda*quant;
}

int Madeira::obtemQuantidade() {
    return quantidade;
}

string Madeira::obtemTipo() {
    return tipo;
}

bool Madeira::gasta(int quant) {
    if(quant > quantidade){
        return false;
    }

    quantidade -= quant;
    return true;
}
