//
// Created by Rafael on 21/12/2021.
//

#include "bateria.h"

Bateria::Bateria(Zona *z, ilha *i) : Edificio(z), i(i), quantEletricidade(100), nivel(1), upgradeDinheiro(5), {}

void Bateria::melhora() {
    if(nivel <= 5){
        ++nivel;
    }
}
