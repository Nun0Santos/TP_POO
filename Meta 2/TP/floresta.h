//
// Created by Rafael on 18/12/2021.
//

#ifndef TP_POO_FLORESTA_H
#define TP_POO_FLORESTA_H

#include "zona.h"

class Floresta : public Zona{
public:
    Floresta(string t, int x, int y) : Zona(t, x , y), nArvores(defineArvores()), tipo("flr"), nArvores_max(100), prod_kg(1), dias(0){}

    int defineArvores();
    int getNArvores() const;
    string obtemTipo() override;
    int produz() override;
private:
    string tipo;
    int nArvores, nArvores_max , prod_kg, dias;
};


#endif //TP_POO_FLORESTA_H
