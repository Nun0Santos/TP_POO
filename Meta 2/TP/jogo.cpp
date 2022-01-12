//
// Created by Rafael on 02/12/2021.
//

#include "geral.h"
#include "sstream"
#include "ilha.h"
#include "jogo.h"


string Jogo::gereIsland(const string& str) {
    return island[0]->executa(str);
}

string Jogo::gereDias(const string& str) {
    vector<string> stages = {"Manha", "Tarde", "Noite"};
    ostringstream oss;

    if(str == stages[0]){
        oss << stages[1];
        return oss.str();
    }
    if(str == stages[1]){
        oss << stages[2];
        return oss.str();
    }
    if(str == stages[2]){
        oss << stages[0];
        return oss.str();
    }
    return "Etapa";
}

void Jogo::criaIsland(int a, int b) {
    island.push_back(new ilha());
    nomes.emplace_back("original");

    island[0]->defineCol(b);
    island[0]->defineLin(a);

    island[0]->criaIlha();
    island[0]->iniciaRecursos();
}

string Jogo::mostraIsland() {
    return island[0]->mostraIlha();
}

void Jogo::save(string t) {
    ilha* a = new ilha(*island[0]);
    island.push_back(a);
    nomes.push_back(t);
}

void Jogo::load(string t) {
    int i = 0;
    auto it = nomes.begin();
    while(it != nomes.end()){
        if((*it) == t){
            break;
        }
        ++i;
        ++it;
    }

    if(it == nomes.end()) return;

    island[0] = island[i];
}

void Jogo::apaga(string t) {
    auto it = nomes.begin();
    auto it1 = island.begin();
    while(it != nomes.end()){
        if((*it) == t){
            delete *it1;
            island.erase(it1);
            nomes.erase(it);
            break;
        }
        ++it1;
        ++it;
    }
}

bool Jogo::game() {
    return island[0]->game();
}
