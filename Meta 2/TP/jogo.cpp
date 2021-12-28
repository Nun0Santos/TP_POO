//
// Created by Rafael on 02/12/2021.
//

#include "geral.h"
#include "sstream"
#include "ilha.h"

string Jogo::gereIsland(const string& str) {
    return island->executa(str);
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
    island = new ilha();
    island->defineLin(a);
    island->defineCol(b);
    island->criaIlha();
    island->iniciaRecursos();
}

string Jogo::mostraIsland() {
    return island->mostraIlha();
}
