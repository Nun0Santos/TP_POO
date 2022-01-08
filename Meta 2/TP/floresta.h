//
// Created by Rafael on 18/12/2021.
//

#ifndef TP_POO_FLORESTA_H
#define TP_POO_FLORESTA_H

#include "zona.h"

class Floresta : public Zona{
public:
    Floresta(string t, int x, int y) : Zona(t, x , y), nArvores(defineArvores()),  nArvores_max(100), prod_kg(1), dias(0){}
    Floresta(const Floresta& outro);

    int defineArvores();
    int getNArvores() const override;
    void trata(ilha& i) override;
    Floresta& operator=(const Zona& outro);
    Zona * duplica() const override;
private:
    int nArvores, nArvores_max , prod_kg, dias;
};


#endif //TP_POO_FLORESTA_H
