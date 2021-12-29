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

    string obtemTipo() override;
    void vende() override;
    int obtemCusto() override;
    void produz() override;
private:
    string tipo;
    int custoConst, x, y;
};


#endif //TP_POO_FUNDICAO_H
