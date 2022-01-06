//
// Created by Rafael on 18/11/2021.
//

#include "trabalhadores.h"
#include <sstream>
#include "zona.h"

int Trabalhador::id = 0;

Trabalhador::Trabalhador(string t, int c, double p, int dias, int d, Zona* z) : tipo(move(t)), custo(c), probEmbora(p), dias(dias), d(d), z(z), id_trab(id), movim(0){
    ++id;
}

Trabalhador::Trabalhador(string t, int c, double p, int dias, int d, Zona *z, int i, int m) : tipo(move(t)), custo(c), probEmbora(p), dias(dias), d(d), z(z), id_trab(i), movim(m){

}

int Trabalhador::ID() const {
    return id_trab;
}

string Trabalhador::obtemTipo(){
    return tipo;
}

string Trabalhador::obtemID() const {
    ostringstream oss;
    oss << id << "." << d;
    return oss.str();
}

int Trabalhador::pedeDemissao() {
    if(probEmbora == 0)
        return 0;

    double val = (double)rand() / RAND_MAX;

    if(val < probEmbora){
        return 1;
    }

    return 0;
}

void Trabalhador::aumentaDias() {
    ++dias;
}

int Trabalhador::vidaBoa() {
    return -1;
}

Trabalhador::Trabalhador(const Trabalhador &outro) {
    *this = outro;
}

Trabalhador &Trabalhador::operator=(const Trabalhador &outro) {
    if(this == &outro){return *this;}

    z = outro.z;
    tipo = outro.tipo;
    custo = outro.custo;
    probEmbora = outro.probEmbora;
    dias = outro.dias;
    d = outro.d;
    id_trab = outro.id_trab;

    return *this;
}

int Trabalhador::obtemDiasSim() const {
    return dias;
}

int Trabalhador::obtemCusto() const {
    return custo;
}

double Trabalhador::obtemProb() const {
    return probEmbora;
}

int Trabalhador::obtemDescanso() {
    return -1;
}

int Trabalhador::obtemDID() {
    return d;
}

bool Trabalhador::previneDesp() {
    return z->previneDespedimento();
}

void Trabalhador::movimenta() {
    if(movim == 1){
        movim = 0;
    }else{
        movim = 1;
    }
}

int Trabalhador::obtemMovim() const{
    return movim;
}





