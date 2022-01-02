//
// Created by user on 27/12/21.
//

#ifndef TP_POO_ELETRICIDADE_H
#define TP_POO_ELETRICIDADE_H
#include "recursos.h"

class Eletricidade: public Recursos{
public:
    Eletricidade();

    double vendeE(int quant) override;
    int producao() override;
    void aumenta(double quant) override;
    string obtemTipo() override;
    int obtemQuantidade() override;
    bool gasta(int quant) override;
private:
    string tipo;
    int quantidade, custoProducao;
    double custoVenda;
};


#endif //TP_POO_ELETRICIDADE_H
