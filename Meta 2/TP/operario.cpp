//
// Created by user on 20/12/21.
//

#include "operario.h"
#include "zona.h"
#include <random>

Operario::Operario(int dia, Zona* z) : desp(0), custo(15), probEmbora(0.05), dias(0), d(dia), tipo("O"), z(z){}

void Operario::despedimento() {
    if(dias < 10)
        return;

    double val = (double)rand() / RAND_MAX;

    if(val < probEmbora){
        desp = 1;
    }
}

int Operario::obtemCusto() const{return custo;}

float Operario::obtemProb() const{return probEmbora;}

void Operario::aumentaDias() {
    ++dias;
}

string Operario::obtemID() {
    ostringstream oss;
    oss << Trabalhador::ID() << "." << d;
    return oss.str();
}

int Operario::obtemDiasSim() const {
    return dias;
}

int Operario::pedeDemissao(){
    return desp;
}

string Operario::obtemTipo() {
    return tipo;
}

Operario &Operario::operator=(const Operario &outro) {
    if(this == &outro){return *this;}

    desp = outro.desp;
    dias = outro.dias;
    d = outro.d;
    z = outro.z;

    return *this;
}

Operario::Operario(const Operario &outro) : Trabalhador(outro){
    *this = outro;
}
