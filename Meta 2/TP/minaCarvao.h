//
// Created by Rafael on 21/12/2021.
//

#ifndef TP_POO_MINACARVAO_H
#define TP_POO_MINACARVAO_H

#include "edificio.h"

class MinaCarvao : public Edificio{
public:
    MinaCarvao(ilha* i, int x, int y);

    void melhora();
    void desaba();
    string obtemTipo() override;
    void vende() override;
    int obtemCusto() override;
    int obtemCustoSubs() override;
    void produz() override;
private:
    string tipo;
    int custoConst, custoSubs, nivel, quantProd, upgradeDinheiro, upgradeRecurso, quantArmazenamento, probDesabar;
    int x, y;
};


#endif //TP_POO_MINACARVAO_H
