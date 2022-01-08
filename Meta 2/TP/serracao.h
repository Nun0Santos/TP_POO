//
// Created by Rafael on 08/01/2022.
//

#ifndef TP_POO_SERRACAO_H
#define TP_POO_SERRACAO_H

#include "edificio.h"

class Serracao : public Edificio{
public:
    Serracao(ilha* i);

    void produz() override;
    Edificio * duplica() const override;
};


#endif //TP_POO_SERRACAO_H
