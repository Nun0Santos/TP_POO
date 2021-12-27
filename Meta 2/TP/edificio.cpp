//
// Created by Rafael on 21/12/2021.
//

#include "edificio.h"
#include "zona.h"

Edificio::Edificio(Zona* z) : onoff(0), z(z), tipo(""){}

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

void Edificio::vende() {
    return;
}


