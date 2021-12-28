//
// Created by user on 27/12/21.
//

#ifndef TP_POO_RECURSOS_H
#define TP_POO_RECURSOS_H

#include <iostream>

using namespace std;

class Recursos {
public:
    virtual int vende(int quant);
    virtual double vendeE(int quant);
    virtual int producao();
    virtual double producaoBAF();
    virtual double producaoBAC();
    virtual void aumenta(int quant);
    virtual bool gasta(int quant);
    virtual string obtemTipo();
    virtual int obtemQuantidade();
private:

};


#endif //TP_POO_RECURSOS_H
