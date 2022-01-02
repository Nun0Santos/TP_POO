//
// Created by Rafael on 18/12/2021.
//

#include "floresta.h"
#include <random>

int Floresta::defineArvores() {
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(20,40);

    return dist6(rng);
}

int Floresta::getNArvores() const {
    return nArvores;
}

string Floresta::obtemTipo() {
    return tipo;
}

int Floresta::produz() {
    if(Zona::obtemQuant_Edificios() == 0){
        if(dias == 2){
            ++nArvores;
            dias = 0;
        }
    }else{
        ++dias;
        --nArvores;
    }
    return Zona::contaTrab("L");
}
