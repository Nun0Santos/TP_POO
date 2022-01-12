//
// Created by Rafael on 21/12/2021.
//

#ifndef TP_POO_PANTANO_H
#define TP_POO_PANTANO_H

#include "zona.h"

class Pantano : public Zona{
public:
    Pantano(string t, int x, int y);
    Pantano(const Pantano& outro);

    void trata(ilha& i) override;
    Pantano& atribui(const Zona& outro);
    Zona * duplica() const override;
private:
    int dias;
};


#endif //TP_POO_PANTANO_H
