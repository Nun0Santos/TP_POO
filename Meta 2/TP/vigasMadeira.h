//
// Created by user on 27/12/21.
//

#ifndef TP_POO_VIGASMADEIRA_H
#define TP_POO_VIGASMADEIRA_H
#include "recursos.h"

class VigasMadeira: public Recursos{
public:
    VigasMadeira();

    double vende(double quant) override;
    int producao() override;

    Recursos * duplica() override;
private:
    int custoProducao, custoVenda;
};


#endif //TP_POO_VIGASMADEIRA_H
