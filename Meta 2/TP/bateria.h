//
// Created by Rafael on 21/12/2021.
//

#ifndef TP_POO_BATERIA_H
#define TP_POO_BATERIA_H

#include "edificio.h"
#include "ilha.h"

class Bateria : public Edificio{
public:
    Bateria(Zona* z, ilha* i);

    void melhora();
    string obtemTipo() override;
private:
    string tipo;
    int quantEletricidade, custoConst, nivel, upgradeDinheiro;
    ilha* i;
};


#endif //TP_POO_BATERIA_H
