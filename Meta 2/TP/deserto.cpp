//
// Created by Rafael on 18/12/2021.
//

#include "deserto.h"

double Deserto::obtemRedProd() {
    return prod;
}

Deserto &Deserto::operator=(const Zona &outro) {
    if(this == &outro) return *this;

    Zona::operator=(outro);

    if(typeid(this) == typeid(outro)){
        const auto* aux = dynamic_cast<const Deserto*>(&outro);
        prod = aux->prod;
    }

    return *this;
}

Zona *Deserto::duplica() const {
    return new Deserto(*this);
}

Deserto::Deserto(const Deserto &outro) : Zona(outro), prod(0){
    *this = outro;
}
