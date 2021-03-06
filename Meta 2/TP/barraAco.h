//
// Created by user on 27/12/21.
//

#ifndef TP_POO_BARRAACO_H
#define TP_POO_BARRAACO_H
#include "recursos.h"

class BarraAco: public Recursos{
public:
    BarraAco();

    double vende(double quant) override;
    double producaoBAC() override;
    double producaoBAF() override;
    Recursos * duplica() override;
private:
    double custoFerro, custoCarvao;
    int custoVenda;
};


#endif //TP_POO_BARRAACO_H
