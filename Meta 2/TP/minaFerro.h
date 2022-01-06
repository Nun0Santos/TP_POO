//
// Created by Rafael on 21/12/2021.
//

#ifndef TP_POO_MINAFERRO_H
#define TP_POO_MINAFERRO_H

#include "edificio.h"

class MinaFerro: public Edificio{
public:
    MinaFerro(ilha* i);

    void melhora();
    void desaba();
    int obtemCustoSubs() override;
    void produz() override;
private:
    int custoSubs, quantProd, upgradeDinheiro, upgradeRecurso, quantArmazenamento, probDesabar;

};


#endif //TP_POO_MINAFERRO_H
