#include "geral.h"
#include <fstream>

int main() {
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




    return 0;
}
