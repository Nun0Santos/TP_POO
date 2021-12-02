//
// Created by Rafael on 02/12/2021.
//

#include "UI.h"

void UI::start() {
    ilha a;
    string aux, opt;

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

void UI::menu() {
    int resp;

    cout << "1 - Play\n2 - Help\n3 - Exit " << endl;
    while (true) {
        cout << "Comando: ";
        cin >> resp;
        switch (resp) {
            case 1:
                start();
                break;
                case 2:
                    cout << "Help";
                    break;
                    case 3:
                        cout << "Exit";
                        break;
                        default:
                            cout << "Comando invalido";
                            continue;
        }
        break;
    }
}

//UI::UI(Jogo &nJ)  : j(nJ){}
