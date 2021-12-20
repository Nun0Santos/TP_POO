//
// Created by Rafael on 18/12/2021.
//

#ifndef TP_POO_DESERTO_H
#define TP_POO_DESERTO_H

#include "zona.h"

class Deserto : public Zona{
public:
    Deserto() : Zona("deserto", 0,0){}
private:
    float prod = 0.5;
};


#endif //TP_POO_DESERTO_H
