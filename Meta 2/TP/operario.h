//
// Created by user on 20/12/21.
//

#ifndef TP_POO_OPERARIO_H
#define TP_POO_OPERARIO_H
#include "trabalhadores.h"

class Operario: public Trabalhador{
public:
    Operario(int dia, Zona* z);
    Operario(int a, int b, int c, double d, int e, int f, Zona *z);
    Operario(const Operario& outro);

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
    Operario& operator=(const Operario& outro);
private:
    string tipo;
    int custo; //Custo do trabalhador
    double probEmbora; //Probabilidade do trabalhador ir embora
    int dias, d; //Dias da simulacao / dia do jogo em que o trabalhador foi contratado
    int desp; //flag para pedir demissão
    Zona* z;
};


#endif //TP_POO_OPERARIO_H
