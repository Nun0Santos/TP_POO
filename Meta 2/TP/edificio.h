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
    bool procuraTrabalhador(int x, int y, string str) const;
    virtual string obtemTipo();
    int getonoff() const;
    virtual void vende();
    void vende(string t, int quant);
    virtual void produz();
    bool gastaRecursos(string t, double quant);
    void aumentaRecursos(string t, double quant);
    bool verificaLaterais(int x, int y, string t);
    virtual int obtemCusto();
    virtual int obtemCustoSubs();
private:
    string tipo;
    int onoff;
    ilha* i;
};


#endif //TP_POO_EDIFICIO_H
