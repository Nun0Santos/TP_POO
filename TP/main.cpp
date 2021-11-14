#include "geral.h"


int main() {
    ilha a;

    cout << "Boas" ;

    //verificaComandos();
    a.defineLin();
    a.defineCol();
    a.ilha::criaIlha();
    a.ilha::mostraIlha();

    return 0;
}
