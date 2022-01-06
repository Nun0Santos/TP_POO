//
// Created by user on 27/12/21.
//

#include "recursos.h"

Recursos::Recursos(string t) : tipo(move(t)), quantidade(0){}

int Recursos::producao() {
    return 0;
}

double Recursos::producaoBAF() {
    return 0;
}

double Recursos::producaoBAC() {
    return 0;
}

bool Recursos::gasta(int quant) {
    if(quant > quantidade){
        return false;
    }

    quantidade -= quant;
    return true;
}

string Recursos::obtemTipo() {
    return tipo;
}



void Recursos::aumenta(double quant) {
    quantidade += quant;
}

double Recursos::vende(double quant) {
    return 0;
}

double Recursos::obtemQuantidade() const {
    return quantidade;
}
