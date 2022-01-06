//
// Created by user on 27/12/21.
//

#include "lenhador.h"
#include "zona.h"
#include <random>


Lenhador::Lenhador(int dia, Zona* z) : Trabalhador("L", 20, 0.05, 0, dia, z), descanso(0){}

Lenhador::Lenhador(int a, int c, double d, int e, int f, int g, Zona *z) : Trabalhador("L", c, d, e, f, z, a), descanso(g){}

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
        return 0;
    }
    return 0;
}

int Lenhador::obtemDescanso() {
    return descanso;
}

int Lenhador::pedeDemissao() const {
    if(Trabalhador::obtemProb() == 0)
        return 0;

    double val = (double)rand() / RAND_MAX;

    if(val < Trabalhador::obtemProb()){
        return 1;
    }

    return 0;
}

Lenhador &Lenhador::operator=(const Lenhador &outro) {
    if(this == &outro) return *this;

    Trabalhador::operator=(outro);

    descanso = outro.descanso;

    return *this;
}
