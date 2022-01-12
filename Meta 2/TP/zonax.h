//
// Created by Rafael on 12/01/2022.
//

#ifndef TP_POO_ZONAX_H
#define TP_POO_ZONAX_H

#include "zona.h"

class ZonaX : public Zona{
public:
    ZonaX(string t, int x, int l);

    Zona * duplica() const override;
    ZonaX& atribui(const Zona& outro);

};


#endif //TP_POO_ZONAX_H
