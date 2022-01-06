//
// Created by user on 27/12/21.
//

#ifndef TP_POO_ELETRICIDADE_H
#define TP_POO_ELETRICIDADE_H
#include "recursos.h"

class Eletricidade: public Recursos{
public:
    Eletricidade();

    double vende(double quant) override;
    int producao() override;

private:
    int custoProducao;
    double custoVenda;
};


#endif //TP_POO_ELETRICIDADE_H
