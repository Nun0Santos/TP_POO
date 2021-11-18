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
    void mostraIlha();
    void mudaValorEdificio(int lin, int col, string t);//muda o valor do edificio "zona" no tabuleiro
    void mudaValorTrab(int lin, int col, string t);//muda o valor dos trabalhadores "zona" no tabuleiro
    void mudaValorQuantTrab(int lin, int col, string t);//muda o valor da quantidade de trabalhadores da "zona" no tabuleiro
    int obtemLin() const;//return das linhas
    int obtemCol() const;//return das colunas
    bool verificaLinCol(int x, int y);
    vector<string> pedeComando();
    void executa();
    //Zona defineZona(int lin, int col, string t);//definir cada zona nas quadriculas
    //string obtemDescricaoZona(int lin, int col, Zona& z) const ;

    //Funções temporárias, não há certeza, perguntar ao stor se é correto
    //void trabalhadorZona();//identificar os trabalhadores em cada zona
    //void quanttrabalhaZona();//quantidade de trabalhores em cada zona
private:
    int lin = 0, col = 0;
    const int maxLin = 8;
    const int maxCol = 16;
    const int minLin = 3;
    Zona **tabuleiro;
    //Zona a;

    //variaveis das funções "temporárias"
    //int quant_zonas;
};

#endif //TP_POO_ILHA_H
