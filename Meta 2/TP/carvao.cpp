//
// Created by user on 27/12/21.
//

#include "carvao.h"

Carvao::Carvao() : custoProducao(1), custoVenda(1), quantidade(0), tipo("carvao"){}

int Carvao::vende(int quant) {
    if(quant > quantidade){
        return -1;
    }

    quantidade -= quant;
    return custoVenda*quant;
}

int Carvao::producao() {
    return custoProducao;
}

void Carvao::aumenta(int quant) {
    quantidade += quant;
}

int Carvao::obtemQuantidade() {
    return quantidade;
}

string Carvao::obtemTipo() {
    return tipo;
}

bool Carvao::gasta(int quant) {
    if(quant > quantidade){
        return false;
    }

    quantidade -= quant;
    return true;
}
