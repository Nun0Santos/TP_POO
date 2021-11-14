//
// Created by user on 04/11/21.
//
#include <iostream>
#include <vector>
#include "geral.h"
using namespace std;

void verificaComandos(){
    string comandos = ("exec","cons","liga","des","move","vende","cont","list","next","save","load","apaga","config","debcash","debed","debskill");
    vector<string> verificacao; //indice 0 = nome do comando
    string comando;

    cout << "Comando : " << endl;
    cin >> comando;

    //tirar espaços   copiar pal ate encontrar um esoaço
    cout << comando;


}


