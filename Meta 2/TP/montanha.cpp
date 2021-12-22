//
// Created by Rafael on 18/12/2021.
//

#include "montanha.h"

Montanha::Montanha() : Zona("montanha", 0, 0),probDemissao(0.05), aumentoProd(1), quantFerro(0){}

void Montanha::produzFerro() {
    quantFerro += 0.1;
}

void Montanha::aumentaProbDemissao() {
    //
}
