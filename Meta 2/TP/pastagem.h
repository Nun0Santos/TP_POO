//
// Created by Rafael on 18/12/2021.
//

#ifndef TP_POO_PASTAGEM_H
#define TP_POO_PASTAGEM_H

#include "zona.h"

class Pastagem : public Zona{
public:
    Pastagem(string t, int x, int y) : Zona(t, x , y){}

    Zona * duplica() const override;
    Pastagem& atribui(const Zona& outro);
};


#endif //TP_POO_PASTAGEM_H
