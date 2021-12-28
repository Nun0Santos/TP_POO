//
// Created by Rafael on 21/12/2021.
//

#ifndef TP_POO_EDIFICIO_H
#define TP_POO_EDIFICIO_H

#include <iostream>

using namespace std;

class ilha;

class Edificio {
public:
    Edificio(ilha* i);

    void ligaDesliga();
    bool procuraTrabalhador(string str) const;
    virtual string obtemTipo();
    int getonoff() const;
    virtual void vende();
    void vende(string t, int quant);
    void produz();
    bool gastaRecursos(string t, int quant);
    void aumentaRecursos(string t, int quant);
    bool verificaLaterais(int x, int y);
    virtual int obtemCusto();
    virtual int obtemCustoSubs();
private:
    string tipo;
    int onoff;
    ilha* i;
};


#endif //TP_POO_EDIFICIO_H
