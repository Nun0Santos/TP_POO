//
// Created by Rafael on 21/12/2021.
//

#ifndef TP_POO_PANTANO_H
#define TP_POO_PANTANO_H

#include "zona.h"

class Pantano : public Zona{
public:
    Pantano();

    void contaDias();
private:
    int dias;
};


#endif //TP_POO_PANTANO_H
