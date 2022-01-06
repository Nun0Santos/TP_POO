//
// Created by user on 27/12/21.
//

#include "mineiro.h"
#include "zona.h"
#include <random>


Mineiro::Mineiro(int dia, Zona* z) : Trabalhador("M", 10, 0.1, 0, dia, z){}

Mineiro::Mineiro(int a, int c, double d, int e, int f, Zona *z, int m) : Trabalhador("O", c, d, e, f, z, a, m){}

int Mineiro::pedeDemissao() {
    if(Trabalhador::previneDesp()){
        return 0;
    }

    double val = (double)rand() / RAND_MAX;

    if(val < Trabalhador::obtemProb()){
        if(Trabalhador::obtemDiasSim() > 2){
            return 1;
        }
    }

    return 0;
}

Mineiro &Mineiro::operator=(const Mineiro &outro) {
    if(this == &outro) return *this;

    Trabalhador::operator=(outro);

    return *this;
}
