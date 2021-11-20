#include "geral.h"
#include <fstream>

int main() {
    ilha a;
    string aux;

    leFich("fich_config.txt");


    a.defineLin();
    a.defineCol();
    a.criaIlha();
    a.mostraIlha();
    cout << "\n\n";
    while(aux != "fim"){
        aux = a.executa();
        a.mostraIlha();
    }




    return 0;
}
