//
// Created by Rafael on 21/12/2021.
//

#ifndef TP_POO_CENTRALELETRICA_H
#define TP_POO_CENTRALELETRICA_H

#include "edificio.h"


class CentralEletrica : public Edificio{
public:
    CentralEletrica(ilha* i, int x, int y);

    string obtemTipo() override;
    void vende() override;
    void produz(int i);
    int obtemCusto() override;
private:
    int x, y;
    string tipo;
    int quantCarvao, custoConst;
};


#endif //TP_POO_CENTRALELETRICA_H
