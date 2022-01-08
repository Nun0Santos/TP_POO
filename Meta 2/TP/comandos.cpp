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
    vector<string> tipos = {"mnF", "mnC", "elec", "bat", "fun", "edificio-x"};

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
    vector<string> recursos = {"Ferro", "Aco", "Carvao", "Madeira", "Vigamadeira", "Eletricidade"};

    if(find(recursos.begin(), recursos.end(), t) != recursos.end()){
        return true;
    }
    return false;
}

bool comandos(const vector<string> &v) {

    bool TF = verificaComandos(v[0]);
    if (TF) {
        //comandos ficheiro
        if (v[0] == "exec") {
            return true;
        }

        //comandos stdin
        if (v[0] == "cons") {
            //codigo para o cons
            //chamar a função mudaValor e passar o v[1] para a lin, o v[2] para a col e o v[3] para t
            if (verificaTipo(v[1])) {
                return true;
            }
        }

        if (v[0] == "cont"){
            if (verificaTrabalhador(v[1])) {
                return true;
            }
        }

        if(v[0] == "list"){
            return true;
        }

        if(v[0] == "next"){
            return true;
        }

        if(v[0] == "liga"){
            return true;
        }

        if(v[0] == "des"){
            return true;
        }

        if(v[0] == "move"){
            return true;
        }

        if(v[0] == "vende"){
            return true;
        }

        if(v[0] == "save"){
            return true;
        }

        if(v[0] == "load"){
            return true;
        }

        if(v[0] == "apaga"){
            return true;
        }

        if(v[0] == "debcash"){
            return true;
        }

        if(v[0] == "debed"){
            if (verificaTipo(v[1])) {
                return true;
            }
        }

        if(v[0] == "debkill"){
            return true;
        }
    }
    return false;
}

