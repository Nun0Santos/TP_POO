#include "geral.h"
#include <fstream>

int main() {
    ilha a;



    a.defineLin();
    a.defineCol();
    a.criaIlha();
    a.mostraIlha();
    cout << "\n\n\n";



        //  a.executa();
        a.mudaValorEdificio(1,1,"mnF");
        a.mudaValorTrab(1,1,"len");
        a.mostraZona(1,1);
        a.mostraIlha();
    //a.mostraIlha();

    /*cout << "\n\n\n";
    a.mudaValor(2, 2, "mnF");
    a.mostraIlha();*/

    return 0;
}
