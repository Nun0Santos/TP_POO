//
// Created by user on 27/12/21.
//

#include "mineiro.h"
#include "zona.h"
#include <random>


Mineiro::Mineiro(int dia, Zona* z) : Trabalhador("M", 10, 0.1, 0, dia, z){}

Mineiro::Mineiro(int a, int c, double d, int e, int f, Zona *z, int m) : Trabalhador("M", c, d, e, f, z, a, m){}

int Mineiro::pedeDemissao() {
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

Trabalhador *Mineiro::duplica() const {
    return new Mineiro(*this);
}

