//
// Created by Rafael on 21/12/2021.
//

#ifndef TP_POO_BATERIA_H
#define TP_POO_BATERIA_H

#include "edificio.h"

class Bateria : public Edificio{
public:
    Bateria(ilha* i);
    Bateria(const Bateria& outro);

    void melhora() override;
    Bateria& operator=(const Edificio& outro);
    Edificio * duplica() const override;

private:
    int quantEletricidade, upgradeDinheiro;
};


#endif //TP_POO_BATERIA_H
