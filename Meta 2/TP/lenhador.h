//
// Created by user on 27/12/21.
//

#ifndef TP_POO_LENHADOR_H
#define TP_POO_LENHADOR_H
#include "trabalhadores.h"

class Lenhador: public Trabalhador{
public:
    Lenhador(int dia, Zona* z);
    Lenhador(const Lenhador& outro);

    void despedimento();
    int obtemCusto() const;
    float obtemProb() const;
    string obtemID() override;
    void aumentaDias() override;
    int obtemDiasSim() const;
    int pedeDemissao() override;
    int vidaBoa() override;
    string obtemTipo() override;
    Lenhador& operator=(const Lenhador& outro);
private:
    string tipo;
    int custo; //Custo do trabalhador
    float probEmbora; //Probabilidade do trabalhador ir embora
    int dias, d; //Dias da simulacao / dia do jogo em que o trabalhador foi contratado
    int desp; //flag para pedir demissão
    int descanso;
    Zona* z;
};


#endif //TP_POO_LENHADOR_H
