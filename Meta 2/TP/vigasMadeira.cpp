//
// Created by user on 27/12/21.
//

#include "vigasMadeira.h"

VigasMadeira::VigasMadeira() : custoProducao(2), custoVenda(2), Recursos("VigasMadeira", 0){}

double VigasMadeira::vende(double quant) {
    return custoVenda*quant;
}

int VigasMadeira::producao() {
    return custoProducao;
}

Recursos *VigasMadeira::duplica() {
    return new VigasMadeira(*this);
}
