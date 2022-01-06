//
// Created by Rafael on 21/12/2021.
//

#ifndef TP_POO_PANTANO_H
#define TP_POO_PANTANO_H

#include "zona.h"

class Pantano : public Zona{
public:
    Pantano(string t, int x, int y);

    void trata(ilha& i) override;
private:
    int dias;
};


#endif //TP_POO_PANTANO_H
