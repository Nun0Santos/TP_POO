//
// Created by user on 27/12/21.
//

#ifndef TP_POO_VIGASMADEIRA_H
#define TP_POO_VIGASMADEIRA_H
#include "recursos.h"

class VigasMadeira: public Recursos{
public:
    VigasMadeira();

    int vende(int quant) override;
    int producao() override;
    void aumenta(int quant) override;
    int obtemQuantidade() override;
    string obtemTipo() override;
    bool gasta(int quant) override;
private:
    string tipo;
    int quantidade;
    int custoProducao, custoVenda;
};


#endif //TP_POO_VIGASMADEIRA_H
