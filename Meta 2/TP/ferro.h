//
// Created by user on 27/12/21.
//

#ifndef TP_POO_FERRO_H
#define TP_POO_FERRO_H
#include "recursos.h"

class Ferro: public Recursos{
public:
    Ferro();

    double vende(double quant) override;
    Recursos * duplica() override;

private:
    int custoVenda;
};


#endif //TP_POO_FERRO_H
