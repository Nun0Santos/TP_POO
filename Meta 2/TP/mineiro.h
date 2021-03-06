//
// Created by user on 27/12/21.
//

#ifndef TP_POO_MINEIRO_H
#define TP_POO_MINEIRO_H
#include "trabalhadores.h"

class Mineiro: public Trabalhador{
public:
    Mineiro(int dia, Zona* z);
    Mineiro(int a, int c, double d, int e, int f, Zona *z, int m);

    int pedeDemissao() override;
    Trabalhador * duplica() const override;
};


#endif //TP_POO_MINEIRO_H
