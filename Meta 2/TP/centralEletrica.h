//
// Created by Rafael on 21/12/2021.
//

#ifndef TP_POO_CENTRALELETRICA_H
#define TP_POO_CENTRALELETRICA_H

#include "edificio.h"


class CentralEletrica : public Edificio{
public:
    CentralEletrica(ilha* i, int x, int y);

    void produz() override;
    CentralEletrica& operator=(const CentralEletrica& outro);
    Edificio * duplica() const override;
private:
    int quantCarvao;
};


#endif //TP_POO_CENTRALELETRICA_H
