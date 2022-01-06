//
// Created by user on 27/12/21.
//

#ifndef TP_POO_LENHADOR_H
#define TP_POO_LENHADOR_H
#include "trabalhadores.h"

class Lenhador: public Trabalhador{
public:
    Lenhador(int dia, Zona* z);
    Lenhador(int a, int c, double d, int e, int f, int g, Zona *z);
    Lenhador(const Lenhador& outro);

    int vidaBoa() override;
    int obtemDescanso() override;
    int pedeDemissao() const override;

    Lenhador& operator=(const Lenhador& outro);
private:
    int descanso;

};


#endif //TP_POO_LENHADOR_H
