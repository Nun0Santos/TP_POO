//
// Created by user on 27/12/21.
//

#ifndef TP_POO_CARVAO_H
#define TP_POO_CARVAO_H
#include "recursos.h"

class Carvao: public Recursos{
public:
    Carvao();

    double vende(double quant) override;
    int producao() override;
private:
    int custoVenda, custoProducao;
};


#endif //TP_POO_CARVAO_H
