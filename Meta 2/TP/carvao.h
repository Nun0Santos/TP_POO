//
// Created by user on 27/12/21.
//

#ifndef TP_POO_CARVAO_H
#define TP_POO_CARVAO_H
#include "recursos.h"

class Carvao: public Recursos{
public:
    Carvao();

    int vende(int quant) override;
    int producao() override;
    void aumenta(double quant) override;
    double obtemQuantidadeD() override;
    string obtemTipo() override;
    bool gasta(int quant) override;
private:
    string tipo;
    int custoVenda, quantidade, custoProducao;
};


#endif //TP_POO_CARVAO_H
