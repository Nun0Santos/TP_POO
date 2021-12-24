//
// Created by Rafael on 18/12/2021.
//

#ifndef TP_POO_PASTAGEM_H
#define TP_POO_PASTAGEM_H

#include "zona.h"

class Pastagem : public Zona{
public:
    Pastagem() : Zona("pastagem", 0,0), tipo("pas"){}

    string obtemTipo() override;
private:
    string tipo;

};


#endif //TP_POO_PASTAGEM_H
