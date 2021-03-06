//
// Created by user on 20/12/21.
//

#include "operario.h"
#include "zona.h"
#include <random>


Operario::Operario(int dia, Zona* z) : Trabalhador("O", 15, 0.05, 0, dia, z){}

Operario::Operario(int a, int c, double d, int e, int f, Zona *z, int m) : Trabalhador("O", c, d, e, f, z, a, m){}


int Operario::pedeDemissao() {
    if(Trabalhador::previneDesp()){
        return 0;
    }

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

Operario &Operario::operator=(const Operario &outro) {
    if(this == &outro) return *this;

    Trabalhador::operator=(outro);

    return *this;
}

Trabalhador *Operario::duplica() const {
    return new Operario(*this);
}


