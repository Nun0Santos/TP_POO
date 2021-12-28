//
// Created by Rafael on 21/12/2021.
//

#include "edificio.h"
#include "ilha.h"


Edificio::Edificio(ilha* i) : onoff(0), i(i), tipo(""){}

void Edificio::ligaDesliga() {
    if(onoff == 0){
        onoff = 1;
        return;
    }
    onoff = 0;
}

bool Edificio::procuraTrabalhador(string str) const {
    return true;//criar funcao que procure se existe o trabalhador indicado
}

int Edificio::getonoff() const {
    return onoff;
}

string Edificio::obtemTipo(){
    return tipo;
}

void Edificio::vende(string t, int quant) {
    i->aumentaRecursos(move(t), quant);
}

void Edificio::produz() {

}

bool Edificio::gastaRecursos(string t, int quant) {
    return i->gastaRecursos(move(t), quant);
}

void Edificio::aumentaRecursos(string t, int quant) {
    i->aumentaRecursos(move(t), quant);
}

void Edificio::vende() {

}

int Edificio::obtemCusto() {
    return 0;
}

int Edificio::obtemCustoSubs() {
    return 0;
}


