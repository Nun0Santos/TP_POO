//
// Created by user on 20/12/21.
//

#include "operario.h"
#include "zona.h"
#include <random>


Operario::Operario(int dia, Zona* z) : Trabalhador(setID()), desp(0), custo(15), probEmbora(0.05), dias(0), d(dia), tipo("O"), z(z){}

Operario::Operario(int a, int b, int c, double d, int e, int f, Zona *z) : Trabalhador(a), desp(b), custo(c), probEmbora(d), dias(e), d(f), tipo("O"), z(z){}


void Operario::despedimento() {
    if(dias < 10)
        return;

    double val = (double)rand() / RAND_MAX;

    if(val < probEmbora){
        desp = 1;
    }
}

int Operario::obtemCusto(){return custo;}

double Operario::obtemProb(){return probEmbora;}

void Operario::aumentaDias() {
    ++dias;
}

string Operario::obtemID() {
    ostringstream oss;
    oss << Trabalhador::ID() << "." << d;
    return oss.str();
}

int Operario::obtemDiasSim() {
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

int Operario::obtemIDT() {
    return Trabalhador::ID();
}

int Operario::obtemDID() {
    return d;
}

