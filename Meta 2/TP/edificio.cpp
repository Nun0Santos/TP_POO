//
// Created by Rafael on 21/12/2021.
//

#include "edificio.h"

Edificio::Edificio(Zona* z) : onoff(0), z(z){}

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


