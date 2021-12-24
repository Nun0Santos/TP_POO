//
// Created by Rafael on 18/12/2021.
//

#ifndef TP_POO_FLORESTA_H
#define TP_POO_FLORESTA_H

#include "zona.h"

class Floresta : public Zona{
public:
    Floresta() : Zona("floresta", 0, 0), nArvores(defineArvores()), tipo("flr"){}

    int defineArvores();
    int getNArvores() const;
    string obtemTipo() override;
private:
    string tipo;
    int nArvores, nArvores_max = 100, prod_kg = 1;
};


#endif //TP_POO_FLORESTA_H
