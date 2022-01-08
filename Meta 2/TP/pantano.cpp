//
// Created by Rafael on 21/12/2021.
//

#include "pantano.h"

Pantano::Pantano(string t, int x, int y) : Zona(t, x , y), dias(0){}

void Pantano::trata(ilha& i) {
    if(dias >= 3){
        if(Zona::getEd() != nullptr)
            Zona::destroiED();
        Zona::apagaTodosTrab();
        dias = 0;
        return;
    }
    ++dias;
}

Pantano &Pantano::operator=(const Zona &outro) {
    if(this == & outro) return *this;

    Zona::operator=(outro);

    if(typeid(this) == typeid(outro)){
        const auto* aux = dynamic_cast<const Pantano*>(&outro);
        dias = aux->dias;
    }

    return *this;
}

Zona *Pantano::duplica() const {
    return new Pantano(*this);
}

Pantano::Pantano(const Pantano &outro) : Zona(outro), dias(0){
    *this = outro;
}


