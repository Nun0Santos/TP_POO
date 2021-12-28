//
// Created by user on 27/12/21.
//

#ifndef TP_POO_BARRAACO_H
#define TP_POO_BARRAACO_H
#include "recursos.h"

class BarraAco: public Recursos{
public:
    BarraAco();

    int vende(int quant) override;
    double producaoBAC() override;
    double producaoBAF() override;
    void aumenta(int quant) override;
    string obtemTipo() override;
    int obtemQuantidade() override;
    bool gasta(int quant) override;
private:
    string  tipo;
    double custoFerro, custoCarvao;
    int custoVenda, quantidade;
};


#endif //TP_POO_BARRAACO_H
