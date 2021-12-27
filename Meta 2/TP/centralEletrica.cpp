//
// Created by Rafael on 21/12/2021.
//

#include "centralEletrica.h"

CentralEletrica::CentralEletrica(Zona* z, ilha* i) : Edificio(z), custoConst(15), quantCarvao(100), i(i), tipo("elec"){}

string CentralEletrica::obtemTipo() {
    return tipo;
}

void CentralEletrica::vende() {
    //adicionar o dinheiro aos recursos
}
