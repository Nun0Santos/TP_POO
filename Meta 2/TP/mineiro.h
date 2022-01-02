//
// Created by user on 27/12/21.
//

#ifndef TP_POO_MINEIRO_H
#define TP_POO_MINEIRO_H
#include "trabalhadores.h"

class Mineiro: public Trabalhador{
public:
    Mineiro(int dia, Zona* z);
    Mineiro(int a, int b, int c, double d, int e, int f, Zona *z);
    Mineiro(const Mineiro& outro);

    void despedimento();
    int obtemCusto() override;
    double obtemProb() override;
    string obtemID() override;
    void aumentaDias() override;
    int obtemDiasSim() override;
    int pedeDemissao() override;
    string obtemTipo() override;
    int obtemIDT() override;
    int obtemDID() override;
    Mineiro& operator=(const Mineiro& outro);
private:
    string tipo;
    int custo; //Custo do trabalhador
    double probEmbora; //Probabilidade do trabalhador ir embora
    int dias, d; //Dias da simulacao / dia do jogo em que o trabalhador foi contratado
    int desp; //flag para pedir demissão
    Zona* z;
};


#endif //TP_POO_MINEIRO_H
