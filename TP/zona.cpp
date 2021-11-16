//
// Created by Rafael on 16/11/2021.
//

#include "zona.h"

void Zona::defineTipo(string str) {
    tipo = str;
}

void Zona::definePosC(int c) {
    posC = c;
}

void Zona::definePosL(int l) {
    posL = l;
}

int Zona::obtemC() const {
    return posC;
}

int Zona::obtemL() const {
    return posL;
}

string Zona::obtemDescricao() const {
    return tipo;
}