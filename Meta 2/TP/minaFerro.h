//
// Created by Rafael on 21/12/2021.
//

#ifndef TP_POO_MINAFERRO_H
#define TP_POO_MINAFERRO_H

#include "edificio.h"

class MinaFerro: public Edificio{
public:
    MinaFerro(ilha* i, int x, int y);

    void melhora();
    void desaba();
    int obtemCustoSubs() override;
    void produz() override;
    MinaFerro& operator=(const Edificio& outro);
    Edificio * duplica() const override;
private:
    int custoSubs, quantProd, upgradeDinheiro, upgradeRecurso, quantArmazenamento, probDesabar;

};


#endif //TP_POO_MINAFERRO_H
