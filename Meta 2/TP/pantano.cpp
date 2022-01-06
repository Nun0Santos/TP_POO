//
// Created by Rafael on 21/12/2021.
//

#include "pantano.h"

Pantano::Pantano(string t, int x, int y) : Zona(t, x , y), dias(0){}

void Pantano::trata(ilha& i) {
    if(dias >= 3){
        if(Zona::getEd() != nullptr)
            Zona::destroiED();
        Zona::apagaTodosTrab();
        dias = 0;
        return;
    }
    ++dias;
}


