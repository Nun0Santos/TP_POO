//
// Created by user on 27/12/21.
//

#include "eletricidade.h"

Eletricidade::Eletricidade() : custoVenda(1.5), quantidade(0), custoProducao(1), tipo("Eletricidade"){}

double Eletricidade::vendeE(int quant) {
    if(quant > quantidade){
        return -1;
    }

    quantidade -= quant;
    return custoVenda*quant;
}

int Eletricidade::producao() {
    return custoProducao;
}

void Eletricidade::aumenta(int quant) {
    quantidade += quant;
}

int Eletricidade::obtemQuantidade() {
    return quantidade;
}

string Eletricidade::obtemTipo() {
    return tipo;
}

bool Eletricidade::gasta(int quant) {
    if(quant > quantidade){
        return false;
    }

    quantidade -= quant;
    return true;
}
