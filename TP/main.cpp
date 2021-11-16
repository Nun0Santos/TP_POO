#include "geral.h"



int main() {
    //ilha a;
    string comando;

    cout << "Boas" << endl;

    cout << "Comando : " << endl;
    getline(cin, comando);

    verificaComandos(comando);
    /*a.defineLin();
    a.defineCol();
    a.ilha::criaIlha();
    a.ilha::mostraIlha();*/

    return 0;
}
