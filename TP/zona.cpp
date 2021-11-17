//
// Created by Rafael on 16/11/2021.
//

#include "zona.h"
#include <sstream>

void Zona::defineTipo(string str) {
    tipo = str;
}

void Zona::definePosC(int c) {
    posC = c;
}

void Zona::definePosL(int l) {
    posL = l;
}

void Zona::defineTrab(string s) {
    if(trab.size() > 5){
        return;
    }
    trab.push_back(s);
}

void Zona::defineEdificio(string s) {
    edificio = s;
}

int Zona::obtemC() const {
    return posC;
}

int Zona::obtemL() const {
    return posL;
}

string Zona::obtemTipo() const {
    return tipo;
}

string Zona::obtemTrab() const {
    ostringstream oss;
    for(const auto & i : trab)
        oss << i << " ";
    return oss.str();
}

int Zona::obtemQuant_Trab() const {
    return quant_trab;
}

string Zona::obtemEdificio() const {
    return edificio;
}

int Zona::obtemQuant_Edificios() const {
    return quant_edificio;
}

int Zona::obtemOnOFF() const {
    return onoff;
}