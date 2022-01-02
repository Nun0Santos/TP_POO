//
// Created by Rafael on 18/11/2021.
//

#include "trabalhadores.h"
#include <sstream>

int Trabalhador::id = -1;

int Trabalhador::ID() const {
    return id_trab;
}

string Trabalhador::obtemTipo(){
    return "-";
}

string Trabalhador::obtemID() {
    return "-";
}

int Trabalhador::pedeDemissao() {
    return 0;
}

void Trabalhador::aumentaDias() {

}

int Trabalhador::vidaBoa() {
    return 0;
}

Trabalhador::Trabalhador(const Trabalhador &outro) {
    *this = outro;
}

Trabalhador &Trabalhador::operator=(const Trabalhador &outro) {
    if(this == &outro){return *this;}

    id_trab = outro.id_trab;

    return *this;
}

int Trabalhador::setID() {
    return id++;
}

int Trabalhador::obtemDiasSim() {
    return 0;
}

int Trabalhador::obtemIDT() {
    return 0;
}

int Trabalhador::obtemCusto() {
    return 0;
}

double Trabalhador::obtemProb() {
    return 0;
}

int Trabalhador::obtemDescanso() {
    return 0;
}

int Trabalhador::obtemDID() {
    return 0;
}






