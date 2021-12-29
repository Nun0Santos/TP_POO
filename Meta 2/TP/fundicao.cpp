//
// Created by Rafael on 23/12/2021.
//

#include "fundicao.h"

Fundicao::Fundicao(ilha *i, int x, int y) : Edificio(i), custoConst(10), tipo("fun"), x(x), y(y){}

string Fundicao::obtemTipo() {
    return tipo;
}

void Fundicao::vende() {
    Edificio::aumentaRecursos("Dinheiro", custoConst);
}

int Fundicao::obtemCusto() {
    return custoConst;
}

void Fundicao::produz() {
    if(Edificio::procuraTrabalhador(x, y, "0")) return;
    if(Edificio::verificaLaterais(x, y, "fun")){
        if(Edificio::gastaRecursos("Ferro", 1.5)){
            if(Edificio::gastaRecursos("Carvao", 0.5)){
                Edificio::aumentaRecursos("BarraAco", 1);
                return;
            }
            Edificio::aumentaRecursos("Ferro", 1.5);
        }
    }
}

