//
// Created by Rafael on 02/11/2021.
//

#include "geral.h"

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
    string temp = "", s;
    vector<string> v;

    cout << "\nComando: " << endl;
    getline(cin, s);


    for(char i : s){

        if(i==' '){
            v.push_back(temp);
            temp = "";
        }
        else{
            temp.push_back(i);
        }

    }
    v.push_back(temp);

    return v;
}

void ilha::executa() {
    vector<string> v = pedeComando();

    int x = stoi(v[2]);//valor das linhas convertido para int
    int y = stoi(v[3]);//valor das colunas convertido para int
    verificaLinCol(x, y);


    if(verificaLinCol(x, y)){//verifica se as linhas e as colunas estão dentro do limite da ilha
        if(comandos(v)){//função que verifica se o comando e se o tipo são válidos
            
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


/*bool verificaLinCol(int x, int y){
    if (obtemLin() >= x && obtemCol() <= y)
        return false;
    return true;
};*/


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