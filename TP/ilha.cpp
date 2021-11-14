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

void ilha::criaIlha() {
    tabuleiro = new string*[lin];
    for (int i = 0; i < lin; ++i) {
        tabuleiro[i] = new string[col];
    }

    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            tabuleiro[i][j] = "ola";
        }
    }


}

void ilha::mostraIlha() {
    cout << "  " ;
    for (int i = 0; i < col; ++i) {
        cout << "-\t";
    }
    cout << "\n";

    for (int i = 0; i < lin; ++i) {
        cout << " |";
        for (int j = 0; j < col; ++j) {
            cout << tabuleiro[i][j] << "\t";
        }
        cout << "\n";
    }
}

/*void ilha::cria_tabela() {
    int i, j;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            ta
        }
    }

}*/

/*void ilha::defineZona() {


}*/