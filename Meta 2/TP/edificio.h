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
    Edificio(ilha* i, string t, int c, int x, int y);
    virtual ~Edificio() = default;

    void ligaDesliga();
    bool procuraTrabalhador(string str) const;
    string obtemTipo();
    int getonoff() const;
    void vende();
    virtual void produz();
    bool gastaRecursos(string t, double quant);
    void aumentaRecursos(string t, double quant);
    bool verificaLaterais(string t);
    int obtemCustoDinheiro() const;
    virtual int obtemCustoSubs();
    int getNivel() const;
    void incrementaNivel();
    virtual void melhora();
    virtual Edificio* duplica() const;
    bool MNT();
    virtual int desaba();
    int obtemQuantTrab();
    bool ZNX();

    Edificio& operator=(const Edificio& outro);
private:
    string tipo;
    int onoff, custoDinheiro, nivel;
    ilha* i;
    int x, y;
};


#endif //TP_POO_EDIFICIO_H
