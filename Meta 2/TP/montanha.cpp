//
// Created by Rafael on 18/12/2021.
//

#include "montanha.h"

Montanha::Montanha(string t, int x, int y) : Zona(t, x , y),probDemissao(0.05), aumentoProd(1), quantFerro(0), tipo("mnt"){}

void Montanha::produzFerro() {
    quantFerro += 0.1;
}

void Montanha::aumentaProbDemissao() {
    //
}

string Montanha::obtemTipo() {
    return tipo;
}

double Montanha::produzD() {
    if(Zona::obtemQuant_Trab() == 0){
        return 0.1;
    }else{
        return 0.1*Zona::obtemQuant_Trab();
    }
}
