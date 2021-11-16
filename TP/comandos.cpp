//
// Created by user on 04/11/21.
//
#include <iostream>
#include <vector>
#include <sstream>
#include "geral.h"
#include <algorithm>
#include <string>

using namespace std;

bool verificaComandos(const string& comando){
    string com = "cons";

    vector<string> comandos = {"exec","cons","liga","des","move","vende","cont","list","next","save","load","apaga","config","debcash","debed","debskill"};

    if(find(comandos.begin(), comandos.end(), com) != comandos.end())
    {
        cout << "\nO comando esta no vetor!" << endl;
        return true;
    }

    return false;

}

void comandos(const string& comando){
    bool TF = verificaComandos(comando);
    if(TF){
        if(comando=="cons"){
            //codigo para o cons

            return;
        }
        if(comando == "list"){
            //codigo para o list

            return;
        }


        //senão for nenhum dos dois é porque é um comando que ainda não fizemos o código
        return;
    }
}


