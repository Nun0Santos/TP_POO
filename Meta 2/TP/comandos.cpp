//
// Created by user on 04/11/21.
//
#include <iostream>
#include <vector>
#include <sstream>
#include "geral.h"
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

bool verificaComandos(const string& com){

    vector<string> comandos = {"exec","cons","liga","des","move","vende","cont","list","next","save","load","apaga","config","debcash","debed","debkill", "upgrade"};

    if(find(comandos.begin(), comandos.end(), com) != comandos.end())
    {
        return true;
    }
    return false;
}

bool verificaTipo(const string& t){
    vector<string> tipos = {"mnF", "mnC", "elec", "bat", "fun", "edx", "ser"};

    if(find(tipos.begin(), tipos.end(), t) != tipos.end())
    {
        return true;
    }
    return false;
}
bool verificaTrabalhador(const string& t){
    vector<string> trab = {"len", "oper", "min"};

    if(find(trab.begin(), trab.end(), t) != trab.end())
    {
        return true;
    }
    return false;
}

bool verificaRecursos(const string& t){
    vector<string> recursos = {"Ferro", "Aco", "Carvao", "Madeira", "VigasMadeira", "Eletricidade"};

    if(find(recursos.begin(), recursos.end(), t) != recursos.end()){
        return true;
    }
    return false;
}

bool comandos(const vector<string> &v) {
    return verificaComandos(v[0]);
}

