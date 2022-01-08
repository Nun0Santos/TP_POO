//
// Created by Rafael on 18/12/2021.
//

#ifndef TP_POO_DESERTO_H
#define TP_POO_DESERTO_H

#include "zona.h"

class Deserto : public Zona{
public:
    Deserto(string t, int x, int y) : Zona(t, x , y), prod(0.05){}
    Deserto(const Deserto& outro);

    double obtemRedProd() override;
    Deserto& operator=(const Zona& outro);

    Zona * duplica() const override;
private:

    double prod;
};


#endif //TP_POO_DESERTO_H
