//
// Created by Rafael on 28/12/2021.
//

#include "dinheiro.h"

Dinheiro::Dinheiro() : Recursos("Dinheiro", 10){}

Recursos *Dinheiro::duplica() {
    return new Dinheiro(*this);
}
