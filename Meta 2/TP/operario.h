//
// Created by user on 20/12/21.
//

#ifndef TP_POO_OPERARIO_H
#define TP_POO_OPERARIO_H
#include "trabalhadores.h"

class Operario: public Trabalhador{
public:
    Operario(int dia, Zona* z);
    Operario(const Operario& outro);

    void despedimento();
    int obtemCusto() const;
    float obtemProb() const;
    string obtemID() override;
    void aumentaDias() override;
    int obtemDiasSim() const;
    int pedeDemissao() override;
    string obtemTipo() override;
    Operario& operator=(const Operario& outro);
private:
    string tipo;
    int custo; //Custo do trabalhador
    float probEmbora; //Probabilidade do trabalhador ir embora
    int dias, d; //Dias da simulacao / dia do jogo em que o trabalhador foi contratado
    int desp; //flag para pedir demissão
    Zona* z;
};


#endif //TP_POO_OPERARIO_H
