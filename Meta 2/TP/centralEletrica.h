//
// Created by Rafael on 21/12/2021.
//

#ifndef TP_POO_CENTRALELETRICA_H
#define TP_POO_CENTRALELETRICA_H

#include "edificio.h"
#include "ilha.h"


class CentralEletrica : public Edificio{
public:
    CentralEletrica(Zona* z, ilha* i);

    string obtemTipo() override;
private:
    string tipo;
    int quantCarvao, custoConst;
    ilha* i;
};


#endif //TP_POO_CENTRALELETRICA_H
