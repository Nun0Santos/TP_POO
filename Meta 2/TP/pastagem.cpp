//
// Created by Rafael on 18/12/2021.
//

#include "pastagem.h"

string Pastagem::obtemTipo() {
    return tipo;
}

int Pastagem::produz() {
    return Zona::contaTrab("L");
}
