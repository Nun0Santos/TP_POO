//
// Created by Rafael on 23/12/2021.
//

#include "fundicao.h"

Fundicao::Fundicao(ilha *i) : Edificio(i), custoConst(10), tipo("fun"){}

string Fundicao::obtemTipo() {
    return tipo;
}

void Fundicao::vende() {
    Edificio::aumentaRecursos("Dinheiro", custoConst);
}

int Fundicao::obtemCusto() {
    return custoConst;
}

