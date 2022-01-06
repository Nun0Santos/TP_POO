//
// Created by user on 20/12/21.
//

#include "operario.h"
#include "zona.h"
#include <random>


Operario::Operario(int dia, Zona* z) : Trabalhador("O", 15, 0.05, 0, dia, z){}

Operario::Operario(int a, int c, double d, int e, int f, Zona *z) : Trabalhador("O", c, d, e, f, z, a){}


int Operario::pedeDemissao() const {
    double val = (double)rand() / RAND_MAX;

    if(val < Trabalhador::obtemProb()){
        if(Trabalhador::obtemDiasSim() > 10){
            return 1;
        }
    }

    return 0;
}

Operario &Operario::operator=(const Operario &outro) {
    if(this == &outro) return *this;

    Trabalhador::operator=(outro);

    return *this;
}


