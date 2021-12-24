//
// Created by Rafael on 18/12/2021.
//

#ifndef TP_POO_MONTANHA_H
#define TP_POO_MONTANHA_H

#include "zona.h"

class Montanha : public Zona{
public:
    Montanha();

    void duplicaPrecoConstrução();
    void produzFerro();
    void aumentaProbDemissao();
    string obtemTipo() override;
private:
    string tipo;
    float probDemissao, aumentoProd, quantFerro;
};


#endif //TP_POO_MONTANHA_H
