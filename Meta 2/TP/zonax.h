//
// Created by Rafael on 12/01/2022.
//

#ifndef TP_POO_ZONAX_H
#define TP_POO_ZONAX_H

#include "zona.h"

class ZonaX : public Zona{//aumenta a produção dos edificios em 10%
public:
    ZonaX(string t, int x, int l);

    Zona * duplica() const override;

};


#endif //TP_POO_ZONAX_H
