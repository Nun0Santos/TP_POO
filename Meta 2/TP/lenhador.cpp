//
// Created by user on 27/12/21.
//

#include "lenhador.h"
#include "zona.h"
#include <random>

Lenhador::Lenhador(int dia, Zona* z) : z(z), desp(0), custo(20), probEmbora(0), dias(0), d(dia), tipo("L"), descanso(0){}

void Lenhador::despedimento() {
    if(probEmbora == 0)
        return;

    double val = (double)rand() / RAND_MAX;

    if(val < probEmbora){
        desp = 1;
    }
}

int Lenhador::obtemCusto() const{return custo;}

float Lenhador::obtemProb() const{return probEmbora;}

void Lenhador::aumentaDias() {
    ++dias;
}

string Lenhador::obtemID(){
    ostringstream oss;
    oss << Trabalhador::ID() << "." << d;
    return oss.str();
}

int Lenhador::obtemDiasSim() const {
    return dias;
}

int Lenhador::pedeDemissao(){
    return desp;
}

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

string Lenhador::obtemTipo() {
    return tipo;
}

Lenhador::Lenhador(const Lenhador &outro) {
    *this = outro;
}

Lenhador &Lenhador::operator=(const Lenhador &outro) {
    if(this == &outro){return *this;}

    desp = outro.desp;
    dias = outro.dias;
    d = outro.d;
    z = outro.z;

    return *this;
}
