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

    vector<string> comandos = {"exec","cons","liga","des","move","vende","cont","list","next","save","load","apaga","config","debcash","debed","debskill"};

    if(find(comandos.begin(), comandos.end(), comando) != comandos.end())
    {
        return true;
    }
    return false;
}


void tiraEspacos(string s, vector<string> &v){

    string temp = "";
    for(char i : s){

        if(i==' '){
            v.push_back(temp);
            temp = "";
        }
        else{
            temp.push_back(i);
        }

    }
    v.push_back(temp);

}

void comandos(){
    string comando;
    vector<string> v;

    cout << "\nComando: " << endl;
    getline(cin, comando);

    tiraEspacos(comando, v);

    bool TF = verificaComandos(v[0]);
    if(TF){
        if(comando=="cons"){
            //codigo para o cons

            return;
        }
        if(comando == "list"){
            //codigo para o list

            //chamar a função mudaValor e passar o v[1] para a lin, o v[2] para a col e o v[3] para t

            return;
        }


        //senão for nenhum dos dois é porque é um comando que ainda não fizemos o código
        return;
    }
}


