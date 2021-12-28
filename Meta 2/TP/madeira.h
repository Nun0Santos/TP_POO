//
// Created by user on 27/12/21.
//

#ifndef TP_POO_MADEIRA_H
#define TP_POO_MADEIRA_H
#include "recursos.h"

class Madeira: public Recursos{
public:
    Madeira();

    int vende(int quant) override;
    string obtemTipo() override;
    int obtemQuantidade() override;
    bool gasta(int quant) override;
private:
    string tipo;
    int custoVenda, quantidade;
};


#endif //TP_POO_MADEIRA_H
