//
// Created by Rafael on 18/12/2021.
//

#include "pastagem.h"

Zona *Pastagem::duplica() const {
    return new Pastagem(*this);
}

Pastagem &Pastagem::atribui(const Zona& outro) {
    if(this == & outro) return *this;

    if(typeid(this) == typeid(outro)){
        Zona::atribui(outro);
    }

    return *this;
}
