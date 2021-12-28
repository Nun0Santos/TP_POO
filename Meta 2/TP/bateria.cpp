//
// Created by Rafael on 21/12/2021.
//

#include "bateria.h"

Bateria::Bateria(ilha *i) : Edificio(i), quantEletricidade(100), nivel(1), upgradeDinheiro(5), custoConst(10), tipo("bat"){}

void Bateria::melhora() {
    if(nivel <= 5){
        ++nivel;
    }
}

string Bateria::obtemTipo(){
    return tipo;
}

void Bateria::vende() {
    Edificio::vende("Dinheiro", custoConst);
}

int Bateria::obtemCusto() {
    return custoConst;
}
