//
// Created by Rafael on 02/11/2021.
//

#ifndef TP_POO_ILHA_H
#define TP_POO_ILHA_H

#include "geral.h"
#include "zona.h"

using namespace std;

class ilha{
public:
    ~ilha(){       //Destrutor
        delete(tabuleiro);
    }
    void defineCol();//pedir quantas colunas quer
    void defineLin();//pedir quantas linhas quer
    void criaIlha();//alocar dinamicamente a ilha
    string mostraIlha();
    void mudaValorEdificio(int& l, int& c, const string& t);//muda o valor do edificio "zona" no tabuleiro
    void mudaValorTrab(int& l, int& c, const string& t);//muda o valor dos trabalhadores "zona" no tabuleiro
    int obtemLin() const;//return das linhas
    int obtemCol() const;//return das colunas
    bool verificaLinCol(int x, int y) const;
    string mostraZona(int x, int y);
    string mostraTodasZonas();
    string executa();
private:
    int lin = 0, col = 0;
    const int maxLin = 8;
    const int maxCol = 16;
    const int minLin = 3;
    Zona **tabuleiro;
};

#endif //TP_POO_ILHA_H
