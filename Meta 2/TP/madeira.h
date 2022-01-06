//
// Created by user on 27/12/21.
//

#ifndef TP_POO_MADEIRA_H
#define TP_POO_MADEIRA_H
#include "recursos.h"

class Madeira: public Recursos{
public:
    Madeira();

    double vende(double quant) override;

private:
    int custoVenda;
};


#endif //TP_POO_MADEIRA_H
