//
// Created by Rafael on 17/11/2021.
//

#include "geral.h"
#include <fstream>


void leFich(const string& filename){
    vector <string> lines;
    string line;

    ifstream fich_leitura(filename);
    if(!fich_leitura.is_open()) {
        cerr << "Erro ao tentar abrir o ficheiro";
        return;
    }
    while(getline(fich_leitura,line)){
        lines.push_back(line);
    }

    fich_leitura.close();

    for (const auto &i : lines)
        cout << i << endl;


}
