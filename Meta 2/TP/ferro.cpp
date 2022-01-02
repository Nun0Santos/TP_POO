//
// Created by user on 27/12/21.
//

#include "ferro.h"

Ferro::Ferro() : custoVenda(1), quantidade(0), tipo("Ferro"){}

int Ferro::vende(int quant) {
    if(quant > quantidade){
        return -1;
    }

    quantidade -= quant;
    return custoVenda*quant;
}

void Ferro::aumenta(double quant) {
    quantidade += quant;
}

double Ferro::obtemQuantidadeD() {
    return quantidade;
}

string Ferro::obtemTipo() {
    return tipo;
}

bool Ferro::gasta(int quant) {
    if(quant > quantidade){
        return false;
    }

    quantidade -= quant;
    return true;
}
