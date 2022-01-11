//
// Created by Rafael on 21/12/2021.
//

#include "edificio.h"
#include "ilha.h"


Edificio::Edificio(ilha* i, string t, int c, int x, int y) : onoff(0), i(i), tipo(move(t)), custoDinheiro(c), x(x), y(y), nivel(1){}

void Edificio::ligaDesliga() {
    if(onoff == 0){
        onoff = 1;
        return;
    }
    onoff = 0;
}

bool Edificio::procuraTrabalhador(string str) const {
    return i->procuraTrabalhador(x, y, move(str));
}

int Edificio::getonoff() const {
    return onoff;
}

string Edificio::obtemTipo(){
    return tipo;
}

void Edificio::vende() {
    i->aumentaRecursos("Dinheiro", custoDinheiro);
}

void Edificio::produz() {

}

bool Edificio::gastaRecursos(string t, double quant) {
    return i->gastaRecursos(move(t), quant);
}

void Edificio::aumentaRecursos(string t, double quant) {
    i->aumentaRecursos(move(t), quant);
}

int Edificio::obtemCustoDinheiro() const{
    return custoDinheiro;
}

int Edificio::obtemCustoSubs() {
    return 0;
}

bool Edificio::verificaLaterais(string t) {
    return i->verificaLaterais(x, y, move(t));
}

int Edificio::getNivel() const {
    return nivel;
}

void Edificio::incrementaNivel() {
    ++nivel;
}

void Edificio::melhora() {

}

Edificio &Edificio::operator=(const Edificio &outro) {
    if(this == &outro) return *this;

    tipo = outro.tipo;
    onoff = outro.onoff;
    custoDinheiro = outro.custoDinheiro;
    nivel = outro.nivel;
    x = outro.x;
    y = outro.y;
    i = outro.i;

    return * this;

}

Edificio *Edificio::duplica() const {
    return nullptr;
}

bool Edificio::MNT() {
    return i->MNT(x, y);
}

int Edificio::desaba() {
    return 0;
}

int Edificio::obtemQuantTrab() {
    return i->obtemQuantTrab(x, y);
}