//
// Created by Rafael on 02/11/2021.
//

#ifndef TP_POO_ILHA_H
#define TP_POO_ILHA_H

#include "geral.h"
#include "zona.h"
#include "recursos.h"

using namespace std;

class ilha{
public:
    ilha() : dias(1), lin(0), col(0), tabuleiro(nullptr), contratou(0){};
    ~ilha(){       //Destrutor
        for(int i = 0; i<col; ++i){
            delete tabuleiro[i];
        }
        delete [] tabuleiro;

        auto it = recursos.begin();
        while (it != recursos.end()){
            delete (*it);
            ++it;
        }
    }

    ilha(const ilha& outro);

    void defineCol(int a);//pedir quantas colunas quer
    void defineLin(int a);//pedir quantas linhas quer
    void criaIlha();//alocar dinamicamente a ilha
    string mostraIlha();
    void mudaValorEdificio(int& l, int& c, const string& t, int dev);//muda o valor do edificio "zona" no tabuleiro
    void mudaValorTrab(const string& t);//muda o valor dos trabalhadores "zona" no tabuleiro
    int obtemLin() const;//return das linhas
    int obtemCol() const;//return das colunas
    bool verificaLinCol(int x, int y) const;
    string mostraZona(int x, int y);
    string mostraTodasZonas();
    string executa(string s1);
    string executaFich(string s1);
    void despedimentos();
    void iniciaRecursos();
    void aumentaRecursos(string str, int quant);
    void aumentaRecursos(string str, double quant);
    bool gastaRecursos(string str, int quant);
    bool gastaRecursos(string str, double quant);
    void trataTrabalhadores();
    void trataEdificios();
    void trataZonas();
    bool verificaLaterais(int x, int y, string t);
    bool procuraTrabalhador(int x, int y, string t);
    bool moveTrabalhador(int x, int y, string t);
    bool apagaTrabID(string id);
    bool MNT(int x, int y);
    bool game();
    int obtemQuantTrab(int x, int y);
    bool ZNX(int x, int y);
    int getContratou() const;
    void setContratou();

    ilha& operator=(const ilha& outro);
private:
    int lin , col, dias;
    Zona ***tabuleiro;
    vector<Recursos*> recursos;
    int contratou;
};

#endif //TP_POO_ILHA_H
