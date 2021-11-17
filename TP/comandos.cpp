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

    vector<string> comandos = {"exec","cons","liga","des","move","vende","cont","list","next","save","load","apaga","config","debcash","debed","debskill"};

    if(find(comandos.begin(), comandos.end(), com) != comandos.end())
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

bool verificaTipo(const string& t){
    vector<string> tipos = {"minaferro", "minacarvao", "centraleletrica", "bateria", "fundicao", "edificio-x"};
}

void comandos(){
    string comando;
    vector<string> v;

    cout << "\nComando: " << endl;
    getline(cin, comando);

    tiraEspacos(comando, v);

    bool TF = verificaComandos(v[0]);
    if(TF){
        if(v[0] == "exec"){
            cout << "o exec esta a funcionar";
            /*string filename("comandos.txt");
            vector <string> lines;
            string line;

            ifstream input_file(filename);
            if(!input_file.is_open()) {
                cerr << "Erro ao tentar abrir o ficheiro";
            }
            while (getline(input_file,line)){
                lines.push_back(line);
            }
            for (const auto &i : lines)
                cout << i << endl;

            input_file.close();*/

        }
        if(v[0] =="cons"){
            //codigo para o cons
            cout << "cons e valido";
            //chamar a função mudaValor e passar o v[1] para a lin, o v[2] para a col e o v[3] para t

            return;
        }
        if(v[0] == "list"){
            //codigo para o list


            return;
        }


        //senão for nenhum dos dois é porque é um comando que ainda não fizemos o código
        return;
    }
}


