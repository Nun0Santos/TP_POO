//
// Created by Rafael on 21/12/2021.
//

#include "pantano.h"

Pantano::Pantano() : Zona("pantano", 0, 0), dias(0){}

void Pantano::contaDias() {
    if(dias >= 10){
        //remove edificio e trabalhador
    }
    ++dias;
}
