//
// Created by Rafael on 16/11/2021.
//

#include "zona.h"
#include <sstream>

#include "minaCarvao.h"
#include "minaFerro.h"
#include "bateria.h"
#include "fundicao.h"
#include "centralEletrica.h"

#include "operario.h"
#include "lenhador.h"
#include "mineiro.h"


void Zona::definePosC(int c) {
    posC = c;
}

void Zona::definePosL(int l) {
    posL = l;
}

void Zona::defineTrab(string s, int dia, ilha* il) {
    if(s == "O"){
        Operario o(dia, this);
        if(!il->gastaRecursos("Dinheiro", o.obtemCusto()))
            return;

        workers.push_back(new Operario(dia, this));
        //workers.push_back(new Operario(o));//maneira correta
        ++quant_trab;
    }
    if(s == "L"){
        Lenhador o(dia, this);
        if(!il->gastaRecursos("Dinheiro", o.obtemCusto()))
            return;

        workers.push_back(new Lenhador(dia, this));
        //workers.push_back(new Lenhador(o));//maneira correta
        ++quant_trab;
    }
    if(s == "M"){
        Mineiro o(dia, this);
        if(!il->gastaRecursos("Dinheiro", o.obtemCusto()))
            return;

        workers.push_back(new Mineiro(dia, this));
        //workers.push_back(new Mineiro(o));//maneira correta
        ++quant_trab;
    }

    int i, flag = 0;
    vector<string> aux;
    for(i = 0; i < 5; ++i){
        if(trab[i] == "-"){
            if(flag == 0){
                flag = 1;
                aux.push_back(s);
                ++i;
            }

        }
        aux.push_back(trab[i]);
    }

    trab.clear();
    trab = aux;
}

void Zona::defineEdificio(const string& s, ilha* i, int dev) {
    if(dev == 0){//e preciso meter as condições para gastar os recursos devidos
        if(s == "mnF"){
            MinaFerro m(i);
            int custo = m.obtemCusto();
            if(i->gastaRecursos("Madeira", custo)){
                ed = new MinaFerro(i);
                ++quant_edificio;
                return;
            }

            custo = m.obtemCustoSubs();
            if(i->gastaRecursos("Dinheiro", custo)){
                ed = new MinaFerro(i);
                ++quant_edificio;
                return;
            }
        }
        if(s == "mnC"){
            MinaCarvao m(i, posL, posC);
            if(i->gastaRecursos("Madeira", m.obtemCusto()) || i->gastaRecursos("Dinheiro", m.obtemCustoSubs())){
                ed = new MinaCarvao(i, posL, posC);
                ++quant_edificio;
                return;
            }
        }
        if(s == "fun"){
            Fundicao m(i, posL, posC);
            if(i->gastaRecursos("Dinheiro", m.obtemCusto())){
                ed = new Fundicao(i, posL, posC);
                ++quant_edificio;
                return;
            }
        }
        if(s == "elec"){
            CentralEletrica m(i, posL, posC);
            if(i->gastaRecursos("Dinheiro", m.obtemCusto())){
                ed = new CentralEletrica(i, posL, posC);
                ++quant_edificio;
                return;
            }
        }
        if(s == "bat"){
            Bateria m(i);
            if(i->gastaRecursos("Dinheiro", m.obtemCusto())){
                ed = new Bateria(i);
                ++quant_edificio;
                return;
            }
        }
    }else{
        if(s == "mnF"){
            ed = new MinaFerro(i);
            ++quant_edificio;
            return;
        }
        if(s == "mnC"){
            ed = new MinaCarvao(i, posL, posC);
            ++quant_edificio;
            return;
        }
        if(s == "fun"){
            ed = new Fundicao(i, posL, posC);
            ++quant_edificio;
            return;
        }
        if(s == "elec"){
            ed = new CentralEletrica(i, posL, posC);
            ++quant_edificio;
            return;
        }
        if(s == "bat"){
            ed = new Bateria(i);
            ++quant_edificio;
            return;
        }
    }

}

int Zona::obtemC() const {
    return posC;
}

int Zona::obtemL() const {
    return posL;
}

string Zona::obtemTipo(){
    return tipo;
}

string Zona::obtemTrab() const {
    ostringstream oss;
    for(const auto & i : trab)
        oss << i << " ";
    return oss.str();
}



int Zona::obtemQuant_Trab() const {
    return quant_trab;
}

string Zona::obtemEdificio() const {
    return ed->obtemTipo();
}

int Zona::obtemQuant_Edificios() const {
    return quant_edificio;
}

int Zona::obtemOnOFF() const {
    return ed->getonoff();
}

Edificio *Zona::getEd() {
    return ed;
}

void Zona::vendeEdificio() {
    ed->vende();
    delete ed;
    ed = nullptr;
    quant_edificio = 0;
}

void Zona::ligaDesligaED() {
    ed->ligaDesliga();
}

string Zona::obtemWorkers() const {
    ostringstream oss;
    for(const auto & i : workers)
        oss << i->obtemTipo() << " : " << i->obtemID() << " | ";
    return oss.str();
}

void Zona::verificaDespedimento() {
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->pedeDemissao() == 1){
            if((*it)->obtemTipo() == "L"){
                if((*it)->vidaBoa() != 0){
                    continue;
                }
            }

            delete (*it);
            it = workers.erase(it);
        }
        ++it;
    }
}

void Zona::trataTrabalhadores() {
    auto it = workers.begin();
    while(it != workers.end()){
        (*it)->aumentaDias();

        if((*it)->obtemTipo() == "L"){
            (*it)->vidaBoa();
        }

        ++it;
    }
}

void Zona::trataEdificios() {
    ed->produz();
}

bool Zona::procuraTrab(string t) {
    auto  it = trab.begin();
    while (it != trab.end()){
        if((*it) == t){
            return true;
        }
        ++it;
    }
    return false;
}
bool Zona::apagaTrabID(string id) {
    vector<string>::reverse_iterator i;
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemID() == id){
            if(quant_trab <= 5){
                for(i = trab.rbegin(); i < trab.rend(); ++i){
                    if((*i) == (*it)->obtemTipo()){
                        trab.erase((i+1).base());
                        trab.emplace_back("-");
                    }
                }
            }
            delete *it;
            workers.erase(it);
            --quant_trab;
            return true;
        }
        ++it;
    }
    return false;
}

int Zona::contaTrab(string t) {
    int i = 0;
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemTipo() == t){
            ++i;
        }
        ++it;
    }
    return i;
}

void Zona::trata(ilha& i) {

}

string Zona::obtemTipo(string t) {
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemID() == t){
            return (*it)->obtemTipo();
        }

        ++it;
    }
    return "-";
}

int Zona::obtemCusto(string t) {
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemID() == t){
            return (*it)->obtemCusto();
        }
        ++it;
    }
    return 0;
}

double Zona::obtemProb(string t) {
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemID() == t){
            return (*it)->obtemProb();
        }
        ++it;
    }
    return 0;
}

int Zona::obtemDiasSim(string t) {
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemID() == t){
            return (*it)->obtemDiasSim();
        }
        ++it;
    }
    return 0;
}

int Zona::pedeDemissao(string t) {
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemID() == t){
            return (*it)->pedeDemissao();
        }
        ++it;
    }
    return 0;
}

int Zona::obtemIDT(string t) {
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemID() == t){
            return (*it)->ID();
        }
        ++it;
    }
    return 0;
}

int Zona::obtemDescanso(string t) {
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemID() == t){
            return (*it)->obtemDescanso();
        }
        ++it;
    }
    return 0;
}

int Zona::obtemDID(string t) {
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemID() == t){
            return (*it)->obtemDID();
        }
        ++it;
    }
    return 0;
}

void Zona::definetrab(string t, int a, int b, int c, double d, int e, int f, int g) {
    if(t == "L"){
        workers.push_back(new Lenhador(a, c, d, e, f,g, this));
        int i, flag = 0;
        vector<string> aux;
        for(i = 0; i < 5; ++i){
            if(trab[i] == "-"){
                if(flag == 0){
                    flag = 1;
                    aux.push_back(t);
                    ++i;
                }

            }
            aux.push_back(trab[i]);
        }

        trab.clear();
        trab = aux;
        ++quant_trab;
        return;
    }
    if(t == "O"){
        workers.push_back(new Operario(a, c, d, e, f, this));
        int i, flag = 0;
        vector<string> aux;
        for(i = 0; i < 5; ++i){
            if(trab[i] == "-"){
                if(flag == 0){
                    flag = 1;
                    aux.push_back(t);
                    ++i;
                }

            }
            aux.push_back(trab[i]);
        }

        trab.clear();
        trab = aux;
        ++quant_trab;
        return;
    }
    if(t == "M"){
        workers.push_back(new Mineiro(a, c, d, e, f, this));
        int i, flag = 0;
        vector<string> aux;
        for(i = 0; i < 5; ++i){
            if(trab[i] == "-"){
                if(flag == 0){
                    flag = 1;
                    aux.push_back(t);
                    ++i;
                }

            }
            aux.push_back(trab[i]);
        }

        trab.clear();
        trab = aux;
        ++quant_trab;
        return;
    }

}

bool Zona::procuraTrab(string t, int a) {
    auto it = workers.begin();
    while (it != workers.end()){
        if((*it)->obtemID() == t){
            return true;
        }
        ++it;
    }
    return false;
}

void Zona::destroiED() {
    delete ed;
    ed = nullptr;
    --quant_edificio;
}

void Zona::apagaTodosTrab() {
    if(workers.empty()) return;
    auto it = workers.begin();
    while (it != workers.end()){
        delete *it;
        it = workers.erase(it);
    }

    workers.clear();

    trab.clear();

    for (int i = 0; i < 5; ++i) {
        trab.emplace_back("-");
    }
    quant_trab = 0;
}

int Zona::getNArvores() const {
    return -1;
}

double Zona::obtemRedProd() {
    return 0;
}