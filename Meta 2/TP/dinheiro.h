//
// Created by Rafael on 28/12/2021.
//

#ifndef TP_POO_DINHEIRO_H
#define TP_POO_DINHEIRO_H

#include "recursos.h"

class Dinheiro : public Recursos{
public:
    Dinheiro();

    void aumenta(double quant) override;
    bool gasta(int quant) override;
    string obtemTipo() override;
    int obtemQuantidade() override;
private:
    string tipo;
    int quantidade;
};


#endif //TP_POO_DINHEIRO_H
