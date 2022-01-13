//
// Created by user on 27/12/21.
//

#ifndef TP_POO_RECURSOS_H
#define TP_POO_RECURSOS_H

#include <iostream>

using namespace std;

class Recursos {
public:
    Recursos(string t, int q = 5);
    virtual ~Recursos() = default;

    virtual double vende(double quant);
    virtual int producao();
    virtual double producaoBAF();
    virtual double producaoBAC();
    void aumenta(double quant);
    bool gasta(int quant);
    string obtemTipo();
    double obtemQuantidade() const;
    virtual Recursos* duplica() = 0;

private:
    string tipo;
    double quantidade;
};


#endif //TP_POO_RECURSOS_H
