//
// Created by Rafael on 02/12/2021.
//

#include "UI.h"

void UI::start() {
    ilha a;
    string aux;

    leFich("fich_config.txt");


    a.defineLin();
    a.defineCol();
    a.criaIlha();
    cout << a.mostraIlha();
    cout << "\n\n";
    while(aux != "fim"){
        aux = a.executa();
        cout << a.mostraIlha();
    }
}
