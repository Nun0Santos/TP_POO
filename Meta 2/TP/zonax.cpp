//
// Created by Rafael on 12/01/2022.
//

#include "zonax.h"

ZonaX::ZonaX(string t, int x, int l) : Zona(move(t), x, l){}

Zona *ZonaX::duplica() const {
    return new ZonaX(*this);
}
