//
// Created by Rafael on 02/11/2021.
//

#include "geral.h"
#include "ilha.h"
#include "zona.h"
#include <sstream>
using namespace std;

void ilha::defineLin() {
    int auxl;
    cout << "Quantas linhas quer? " << endl;
    cin >> auxl;
    if(auxl>=3 && auxl<=8){
        lin = auxl;
        return;
    }
    cout << "Valor errado" << endl;
    ilha::defineLin();
}

void ilha::defineCol(){
    int auxc;

    cout << "Quantas colunas quer? " << endl;
    cin >> auxc;
    if(auxc>=3 && auxc<=16){
        col = auxc;
        return;
    }
    cout << "Valor errado" << endl;
    ilha::defineCol();
}

int ilha::obtemCol() const {
    return col;
}

int ilha::obtemLin() const {
    return lin;
}

vector<string> ilha::pedeComando() {
    string s1, s2;
    vector<string> v;

    cout << "\nComando: ";
    getline(cin, s1);
    while((getchar()) != '\n');
    stringstream ss(s1);

    while (getline(ss, s2, ' ')) {
        v.push_back(s2);

    }

    return v;
}

void ilha::executa() {
    vector<string> v = pedeComando();

    int x = stoi(v[2]);//valor das linhas convertido para int
    int y = stoi(v[3]);//valor das colunas convertido para int

        if(comandos(v)){//função que verifica se o comando e se o tipo são válidos
            if (v[0] == "cons"){
                if (verificaLinCol(x,y)){

                    mudaValorEdificio(x,y,v[1]);
                }
            }
            if (v[0] == "cont"){
                if(verificaTrabalhador(v[1])){
                    mudaValorTrab(0,0,v[1]);
                }
            }
            if(v[0] == "list"){
                if(v.size() > 1){
                    if(verificaLinCol(x,y)){
                        mostraZona(x,y);
                    }
                }
                else{
                    mostraIlha();
                }
            }
        }
    }
    void ilha::mudaValorEdificio(int lin, int col, string t) {
    if(tabuleiro[lin][col].obtemQuant_Edificios() > 0)
        return;
    tabuleiro[lin][col].defineEdificio(t);
}

/*void ilha::mudaValorQuantTrab(int lin, int col, string t) {
    if(t == "oper"){
        if(tabuleiro[lin][col].obtemTrab() == "O");
    }
}*/
void ilha::mudaValorTrab(int lin, int col, string t) {
    if(t == "oper"){
        cout << "aqui oper";
        tabuleiro[lin][col].obtemTrab() = "O";
    }
    if(t == "len"){
        cout << "teste";
        cout << "\n";
        tabuleiro[lin][col].obtemTrab() = 'L'; //Isto esta a mandar um - para o ecra
        cout << tabuleiro[lin][col].obtemTrab();
    }
    if(t == "min"){
        cout << "aqui min";
        tabuleiro[lin][col].obtemTrab() = "M";
    }
}

bool ilha::verificaLinCol(int x, int y) {
    if (lin >= x && col <= y)
        return true;
    return false;

}
void ilha::mostraZona(int x, int y) {
        for(int i = 0; i < 4; ++i){
            switch (i) {
                case 0:
                    cout << tabuleiro[x][y].obtemTipo() << endl;
                    break;
                case 1:
                    cout << tabuleiro[x][y].obtemEdificio() << endl;
                    break;
                case 2:
                    cout << tabuleiro[x][y].obtemTrab() << endl;
                    break;
                case 3:
                    cout << tabuleiro[x][y].obtemQuant_Trab() << endl;
                    break;
                default:
                    break;
            }
        }
}
void ilha::criaIlha() {
    tabuleiro = new Zona*[lin];
    for (int i = 0; i < lin; ++i) {
        tabuleiro[i] = new Zona[col];
    }

    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            tabuleiro[i][j].defineTipo("-");
            tabuleiro[i][j].defineTrab("-");
            tabuleiro[i][j].definePosC(j);
            tabuleiro[i][j].definePosL(i);
            tabuleiro[i][j].defineEdificio("-");
        }
    }
}

void ilha::mostraIlha() {
    for (int k = 0; k < col; ++k) {
        if(k < col-1)
            cout << "+ ------------- ";
        else
            cout << "+ ------------- +";
    }

    for (int i = 0; i < lin; ++i) {
        cout << "\n";
        for (int j = 0; j < 4; ++j) {
            cout << "|\t\t";
            for (int k = 0; k < col; ++k) {
                switch (j) {
                    case 0:
                        cout << tabuleiro[i][k].obtemTipo();
                        break;
                    case 1:
                        cout << tabuleiro[i][k].obtemEdificio();
                        break;
                    case 2:
                        cout << tabuleiro[i][k].obtemTrab();
                        break;
                    case 3:
                        cout << tabuleiro[i][k].obtemQuant_Trab();
                        break;
                    default:
                        break;
                }
                cout << "\t\t|\t\t";
            }
            cout << "\n";
        }
        for (int k = 0; k < col; ++k) {
            if(k < col-1)
                cout << "+ ------------- ";
            else
                cout << "+ ------------- +";
        }
    }
}

