//
// Created by Rafael on 21/12/2021.
//

#ifndef TP_POO_EDIFICIO_H
#define TP_POO_EDIFICIO_H

#include "zona.h"

class Edificio {
public:
    Edificio(Zona* z);

    void ligaDesliga();
    bool procuraTrabalhador(string str) const;
private:
    int onoff;
    Zona* z;
};


#endif //TP_POO_EDIFICIO_H
