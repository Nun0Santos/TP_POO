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
    island.push_back(new ilha(*island[0]));
    nomes.push_back(t);
}
