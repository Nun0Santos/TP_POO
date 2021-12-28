//
// Created by user on 27/12/21.
//

#ifndef TP_POO_FERRO_H
#define TP_POO_FERRO_H
#include "recursos.h"

class Ferro: public Recursos{
public:
    Ferro();

    int vende(int quant) override;
    void aumenta(int quant) override;
    int obtemQuantidade() override;
    string obtemTipo() override;
    bool gasta(int quant) override;
private:
    string tipo;
    int custoVenda, quantidade;
};


#endif //TP_POO_FERRO_H
