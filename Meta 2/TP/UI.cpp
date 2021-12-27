//
// Created by Rafael on 02/12/2021.
//

#include "UI.h"
#include "sstream"

void UI::start() {

    int l = defineL() , c = defineC();
    string str, s2;
    vector<string> v;
    ostringstream oss;

    j.criaIsland(l, c);
    cout << j.mostraIsland();


    while(str != "fim"){
        str = "-";
        cout << "\nFase do dia : " <<j.gereDias("Manha") << endl;
        while(str != "next"){
            str = defineComando();

            stringstream ss(str);

            while (getline(ss, s2, ' ')) {
                v.push_back(s2);
            }

            if(str  == "fim")
                break;
            if(v[0] == "list" || v[0] == "load"){
                cout << j.gereIsland(str);
            }else{
                j.gereIsland(str);
            }
        }
        cout << "\nFase do dia : " <<j.gereDias("Tarde") << endl;
        cout << j.mostraIsland();
    }
}

void UI::menu() {

    int resp;

    cout << " _____    _                 _ \n"
            "|_   _|  | |               | |\n"
            "  | | ___| | __ _ _ __   __| |\n"
            "  | |/ __| |/ _` | '_ \\ / _` |\n"
            " _| |\\__ \\ | (_| | | | | (_| |\n"
            " \\___/___/_|\\__,_|_| |_|\\__,_|\n"
            "                              \n"
            "                              " << endl;

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
                        return;
                        default:
                            cout << "Comando invalido\n";
                            continue;
        }
        break;
    }
}

int UI::defineL() {
    int l = 0;
    while(l < 3 || l > 8){
        cout << "\nN. de linhas: ";
        cin >> l;
        if(l < 3 || l > 8)
            cout << "Valor invalido! Tem que estar compreendido entre 3 e 8." << endl;
    }
    return l;
}

int UI::defineC() {
    int c = 0;
    while(c < 3 || c > 16){
        cout << "\nN. de colunas: ";
        cin >> c;
        if(c < 3 || c > 8)
            cout << "Valor invalido! Tem que estar compreendido entre 3 e 16." << endl;
    }
    return c;
}

string UI::defineComando() {
    string str;
    cout << "\nComando: ";
    cin.sync();
    getline(cin, str);
    return str;
}
