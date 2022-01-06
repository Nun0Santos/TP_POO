//
// Created by Rafael on 18/11/2021.
//

#ifndef TP_POO_TRABALHADORES_H
#define TP_POO_TRABALHADORES_H

#include <iostream>
#include <sstream>

using namespace std;

class Zona;

class Trabalhador{
public:
    Trabalhador(string t, int c, double p, int dias, int d, Zona* z);
    Trabalhador(string t, int c, double p, int dias, int d, Zona* z, int i);
    Trabalhador(const Trabalhador& outro);


    int ID() const;
    string obtemTipo();
    string obtemID() const;
    int obtemDiasSim() const;
    virtual int pedeDemissao() const;
    void aumentaDias();
    virtual int vidaBoa();
    int obtemCusto() const;
    double obtemProb() const;
    virtual int obtemDescanso();
    int obtemDID();
    Trabalhador& operator=(const Trabalhador& outro);
private:
    string tipo;
    int custo; //Custo do trabalhador
    double probEmbora; //Probabilidade do trabalhador ir embora
    int dias, d; //Dias da simulacao / dia do jogo em que o trabalhador foi contratado
    int id_trab; //id do trabalhador
    static int id;
    Zona* z;
};

#endif //TP_POO_TRABALHADORES_H
