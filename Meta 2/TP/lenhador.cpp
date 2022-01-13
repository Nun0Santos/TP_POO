//
// Created by user on 27/12/21.
//

#include "lenhador.h"
#include "zona.h"
#include <random>


Lenhador::Lenhador(int dia, Zona* z) : Trabalhador("L", 20, 0, 0, dia, z), descanso(0){}

Lenhador::Lenhador(int a, int c, double d, int e, int f, int g, Zona *z, int m) : Trabalhador("L", c, d, e, f, z, a, m), descanso(g){}

int Lenhador::vidaBoa() {
    if(descanso == -1){
         descanso = 0;
         return -1;
    }

    if(descanso < 4){
        if(descanso == 3){
            descanso = -1;
            return 0;
        }
        ++descanso;
    }
    return 0;
}

int Lenhador::obtemDescanso() {
    return descanso;
}

int Lenhador::pedeDemissao() {
    if(Trabalhador::obtemProb() == 0)
        return 0;

    double val = (double)rand() / RAND_MAX;

    if(isMNT()){
        if(val < Trabalhador::obtemProb()+Trabalhador::aumentoProbDem()){
            return 1;
        }
    }else{
        if(val < Trabalhador::obtemProb()){
            return 1;
        }
    }

    return 0;
}

Lenhador &Lenhador::operator=(const Trabalhador &outro) {
    if(this == &outro) return *this;
    if(typeid(*this) == typeid(outro)){
        Trabalhador::operator=(outro);

        const auto* aux = dynamic_cast<const Lenhador*> (&outro);

        descanso = aux->descanso;
    }

    return *this;
}

Lenhador::Lenhador(const Lenhador &outro) : Trabalhador(outro), descanso(0){
    *this = outro;
}

Trabalhador *Lenhador::duplica() const {
    return new Lenhador(*this);
}
