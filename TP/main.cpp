#include "geral.h"

#include <fstream>

int main() {
    ilha a;



    a.defineLin();
    a.defineCol();
    //a.mostraIlha();
    a.criaIlha();
    cout << "\n\n\n";



    a.executa();

    //a.mostraIlha();

    /*cout << "\n\n\n";
    a.mudaValor(2, 2, "mnF");
    a.mostraIlha();*/

    return 0;
}
