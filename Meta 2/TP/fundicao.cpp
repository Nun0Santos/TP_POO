//
// Created by Rafael on 23/12/2021.
//

#include "fundicao.h"

Fundicao::Fundicao(Zona *z, ilha *i) : Edificio(z), i(i), custoConst(10), tipo("fun"){}

string Fundicao::obtemTipo() {
    return tipo;
}
