//
// Created by Rafael on 18/12/2021.
//

#ifndef TP_POO_MONTANHA_H
#define TP_POO_MONTANHA_H

#include "zona.h"

class Montanha : public Zona{
public:
    Montanha(string t, int x, int y);

    void duplicaPrecoConstrucao();
    void aumentaProbDemissao();
    void trata(ilha& i) override;
private:
    float probDemissao, aumentoProd, quantFerro;
};


#endif //TP_POO_MONTANHA_H
