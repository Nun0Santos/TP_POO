//
// Created by Rafael on 21/12/2021.
//

#include "pantano.h"

Pantano::Pantano(string t, int x, int y) : Zona(t, x , y), dias(0), tipo("pnt"), destroi(0){}

void Pantano::contaDias() {
    if(dias >= 10){
        //remove edificio e trabalhador
    }
    ++dias;
}

string Pantano::obtemTipo() {
    return tipo;
}

bool Pantano::aumentaDestroi() {
    if(destroi == 10){
        destroi = 0;
        return true;
    }
    ++destroi;
    return false;
}
