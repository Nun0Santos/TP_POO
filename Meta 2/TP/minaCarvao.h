//
// Created by Rafael on 21/12/2021.
//

#ifndef TP_POO_MINACARVAO_H
#define TP_POO_MINACARVAO_H

#include "edificio.h"

class MinaCarvao : public Edificio{
public:
    MinaCarvao(ilha* i, int x, int y);

    void melhora() override;
    void desaba();
    int obtemCustoSubs() override;
    void produz() override;

private:
    int custoSubs, quantProd, upgradeDinheiro, upgradeRecurso, probDesabar, quantArmazenamento;
};


#endif //TP_POO_MINACARVAO_H
