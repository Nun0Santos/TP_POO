//
// Created by User on 12/01/2022.
//

#ifndef TP_POO_EDIFICIOX_H
#define TP_POO_EDIFICIOX_H
#include "edificio.h"


class Edificiox : public Edificio{
public:

     Edificiox(ilha *i, int i1, int i2);
     void produz()override;

    Edificio * duplica() const override;

};


#endif //TP_POO_EDIFICIOX_H
