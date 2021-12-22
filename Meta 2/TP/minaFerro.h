//
// Created by Rafael on 21/12/2021.
//

#ifndef TP_POO_MINAFERRO_H
#define TP_POO_MINAFERRO_H

#include "edificio.h"

class MinaFerro: public Edificio{
public:
    MinaFerro(Zona* z);

    void melhora();
    void desaba();
private:
    int custoConst, custoSubs, nivel, quantProd, upgradeDinheiro, upgradeRecurso, quantArmazenamento, probDesabar;

};


#endif //TP_POO_MINAFERRO_H
