//
// Created by user on 04/11/21.
//
#include <iostream>
#include <vector>
#include <sstream>
#include "geral.h"


using namespace std;

void verificaComandos(string comando){
    string comandos = ("exec","cons","liga","des","move","vende","cont","list","next","save","load","apaga","config","debcash","debed","debskill");
    vector<string> verificacao; //indice 0 = nome do comando
    string del;

    //tirar espaços   copiar pal ate encontrar um esoaço
    istringstream ss(comando);

    while(getline(ss, del, ' ')){
        cin >> del;
    }

    cout << del << endl;
}


