//
// Created by user on 20/12/21.
//

#ifndef TP_POO_OPERARIO_H
#define TP_POO_OPERARIO_H
#include "trabalhadores.h"

class Operario: public Trabalhador{
public:
    Operario(int dia, Zona* z);
    Operario(int a, int c, double d, int e, int f, Zona *z, int m);
    Operario(const Operario& outro);

    Operario& operator=(const Operario& outro);
    int pedeDemissao() override;
};


#endif //TP_POO_OPERARIO_H
