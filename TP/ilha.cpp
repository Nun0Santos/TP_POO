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

void ilha::mudaValor(int lin, int col, string t) {
    if(tabuleiro[lin][col].obte)
    tabuleiro[lin][col].defineEdificio(t);

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
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < col; ++k) {
                switch (j) {
                    case 0:
                        tabuleiro[i][k].obtemTipo();
                        break;
                    case 1:
                        tabuleiro[i][k].obtemEdificio();
                        break;
                    case 2:
                        tabuleiro[i][k].obtemTrab();
                        break;
                    case 3:
                        tabuleiro[i][k].obtemQuant_Trab();
                        break;
                    default:
                        break;
                }
                cout << "\t";
            }
            cout << "\n";
        }
    }
}