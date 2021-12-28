//
// Created by user on 27/12/21.
//

#include "barraAco.h"

BarraAco::BarraAco() : custoVenda(2), quantidade(0), custoCarvao(0.5), custoFerro(1.5), tipo("BarraAco"){}

int BarraAco::vende(int quant) {
    if(quant > quantidade){
        return -1;
    }

    quantidade -= quant;
    return custoVenda*quant;
}

double BarraAco::producaoBAC() {
    return custoCarvao;
}

double BarraAco::producaoBAF() {
    return custoFerro;
}

void BarraAco::aumenta(int quant) {
    quantidade += quant;
}

int BarraAco::obtemQuantidade() {
    return quantidade;
}

string BarraAco::obtemTipo() {
    return tipo;
}

bool BarraAco::gasta(int quant) {
    if(quant > quantidade){
        return false;
    }

    quantidade -= quant;
    return true;
}

