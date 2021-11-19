//
// Created by Rafael on 02/11/2021.
//

#include "geral.h"
#include "ilha.h"
#include "zona.h"
#include <sstream>
#include<limits>

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


void ilha::executa() {
    string s1, s2;
    vector<string> v;
    int x = 0, y = 0;

    cout << "\nComando: ";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    getline(cin, s1);

    cout << "s1: " << s1 << "\n";
    stringstream ss(s1);

    while (getline(ss, s2, ' ')) {
        v.push_back(s2);

    }

    if(v.size() > 2){
        istringstream ossX(v[2]);//transforma string em int
        ossX >> x;//atribui valor transformado à variavel x
        istringstream ossY(v[3]);//transforma string em int
        ossY >> y;//atribui valor transformado à variavel y
    }

        if(comandos(v)){//função que verifica se o comando e se o tipo são válidos
            if (v[0] == "cons"){
                if (verificaLinCol(x,y)){

                    mudaValorEdificio(x, y, v[1]);
                }
            }
            if (v[0] == "cont"){
                if(verificaTrabalhador(v[1])){
                    mudaValorTrab(x, y, v[1]);
                }
            }
            if(v[0] == "list"){
                if(v.size() > 1){
                    //if(verificaLinCol(x,y)){
                        mostraZona(x,y);
                    //}
                }
                else{
                    mostraIlha();
                }
            }
        }
    }
    void ilha::mudaValorEdificio(int l, int c, string t) {
    if(tabuleiro[l][c].obtemQuant_Edificios() > 0)
        return;
    tabuleiro[l][c].defineEdificio(t);
}

void ilha::mudaValorTrab(int l, int c, string t) {
    if(t == "oper"){
        if(verificaTrabalhador("oper")){
            tabuleiro[l][c].defineTrab("O");
            tabuleiro[l][c].defineQuantTrab();
            return;
        }
        cout << "Este trabalhador não existe" << endl;
    }
    if(t == "len"){
        if(verificaTrabalhador("len")){
            tabuleiro[lin][col].defineTrab("L");
            tabuleiro[lin][col].defineQuantTrab();
            return;
        }
        cout << "Este trabalhador não existe" << endl;
    }
    if(t == "min"){
        if(verificaTrabalhador("min")){
            tabuleiro[lin][col].defineTrab("M");
            tabuleiro[lin][col].defineQuantTrab();
            return;
        }
        cout << "Este trabalhador não existe" << endl;
    }
}

bool ilha::verificaLinCol(int x, int y) {
    if (lin >= x && col <= y)
        return false;
    return true;
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
            cout << "|\t";
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
                cout << "\t|\t";
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

