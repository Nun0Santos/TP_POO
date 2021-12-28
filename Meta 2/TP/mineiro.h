//
// Created by user on 27/12/21.
//

#ifndef TP_POO_MINEIRO_H
#define TP_POO_MINEIRO_H
#include "trabalhadores.h"

class Mineiro: public Trabalhador{
public:
    Mineiro(int dia, Zona* z);
    Mineiro(const Mineiro& outro);

    void despedimento();
    int obtemCusto() const;
    float obtemProb() const;
    string obtemID() override;
    void aumentaDias() override;
    int obtemDiasSim() const;
    int pedeDemissao() override;
    string obtemTipo() override;
    Mineiro& operator=(const Mineiro& outro);
private:
    string tipo;
    int custo; //Custo do trabalhador
    float probEmbora; //Probabilidade do trabalhador ir embora
    int dias, d; //Dias da simulacao / dia do jogo em que o trabalhador foi contratado
    int desp; //flag para pedir demissão
    Zona* z;
};


#endif //TP_POO_MINEIRO_H
