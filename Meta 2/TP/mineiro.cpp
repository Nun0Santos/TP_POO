//
// Created by user on 27/12/21.
//

#include "mineiro.h"
#include "zona.h"
#include <random>

Mineiro::Mineiro(int dia, Zona* z) : z(z), desp(0), custo(10), probEmbora(0.1), dias(0), d(dia), tipo("M"){}

void Mineiro::despedimento() {
    if(dias < 2)
        return;

    double val = (double)rand() / RAND_MAX;

    if(val < probEmbora){
        desp = 1;
    }
}

int Mineiro::obtemCusto() const{return custo;}

float Mineiro::obtemProb() const{return probEmbora;}

void Mineiro::aumentaDias() {
    ++dias;
}

string Mineiro::obtemID(){
    ostringstream oss;
    oss << Trabalhador::ID() << "." << d;
    return oss.str();
}

int Mineiro::obtemDiasSim() const {
    return dias;
}

int Mineiro::pedeDemissao(){
    return desp;
}

string Mineiro::obtemTipo(){
    return tipo;
}

Mineiro &Mineiro::operator=(const Mineiro &outro) {
    if(this == &outro){return *this;}

    desp = outro.desp;
    dias = outro.dias;
    d = outro.d;
    z = outro.z;

    return *this;
}

Mineiro::Mineiro(const Mineiro &outro) {
    *this = outro;
}
