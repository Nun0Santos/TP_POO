//
// Created by Rafael on 23/12/2021.
//

#ifndef TP_POO_FUNDICAO_H
#define TP_POO_FUNDICAO_H

#include "edificio.h"
#include "ilha.h"

class Fundicao : public Edificio{
public:
    Fundicao(ilha* i, int x, int y);

    void produz() override;
};


#endif //TP_POO_FUNDICAO_H
