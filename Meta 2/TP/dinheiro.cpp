//
// Created by Rafael on 28/12/2021.
//

#include "dinheiro.h"

Dinheiro::Dinheiro() : quantidade(0), tipo("Dinheiro"){}

void Dinheiro::aumenta(int quant) {
    quantidade += quant;
}

bool Dinheiro::gasta(int quant) {
    if(quant > quantidade){
        return false;
    }

    quantidade -= quant;
    return true;
}

string Dinheiro::obtemTipo() {
    return tipo;
}

int Dinheiro::obtemQuantidade() {
    return quantidade;
}


