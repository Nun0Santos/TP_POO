//
// Created by Rafael on 18/12/2021.
//

#include "floresta.h"
#include <random>
#include "ilha.h"

int Floresta::defineArvores() {
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(20,40);

    return dist6(rng);
}

int Floresta::getNArvores() const {
    return nArvores;
}

void Floresta::trata(ilha& i){
    if(Zona::obtemQuant_Edificios() == 0){
        if(dias == 2){
            ++nArvores;
            dias = 0;
        }
        ++dias;
    }else{
        ++dias;
        --nArvores;
    }
    if(nArvores > 0){
        i.aumentaRecursos("Madeira", Zona::contaTrab("L"));
    }
}

Floresta &Floresta::atribui(const Zona &outro) {
    if(this == & outro) return *this;

    if(typeid(this) == typeid(outro)){
        Zona::atribui(outro);

        const auto* aux = dynamic_cast<const Floresta*>(&outro);
        nArvores = aux->nArvores;
        nArvores_max = aux->nArvores_max;
        prod_kg = aux->prod_kg;
        dias = aux->dias;
    }
    return *this;
}

Floresta::Floresta(const Floresta &outro) : Zona(outro), nArvores(0),  nArvores_max(0), prod_kg(0), dias(0){
    this->atribui(outro);
}

Zona *Floresta::duplica() const {
    return new Floresta(*this);
}
