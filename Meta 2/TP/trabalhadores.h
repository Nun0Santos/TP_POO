//
// Created by Rafael on 18/11/2021.
//

#ifndef TP_POO_TRABALHADORES_H
#define TP_POO_TRABALHADORES_H

#include <iostream>
using namespace std;


class Trabalhador{
public:
    Trabalhador(int c, float prob, int x, int y, int d) : custo(c),probEmbora(prob),x(x),y(y), dias(d){++id;};
    int obtemCusto();
    float obtemProb();
    string obtemId();
    int obtemCoordenadas();


private:
    int custo; //Custo do trabalhador
    float probEmbora; //Probabilidade do trabalhador ir embora
    static int id; // Identificador do trabalhador com o formato n.d (n = numero crescente e d = dia da simulacao)
    int x;
    int y;
    int dias; //Dias da simulacao
};
int Trabalhador::id = 1;

#endif //TP_POO_TRABALHADORES_H
