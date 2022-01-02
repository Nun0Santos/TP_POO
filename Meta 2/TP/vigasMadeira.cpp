//
// Created by user on 27/12/21.
//

#include "vigasMadeira.h"

VigasMadeira::VigasMadeira() : custoProducao(2), custoVenda(2), quantidade(0), tipo("VigaMadeira"){}

int VigasMadeira::vende(int quant) {
    if(quant > quantidade){
        return -1;
    }

    quantidade -= quant;
    return custoVenda*quant;
}

int VigasMadeira::producao() {
    return custoProducao;
}

void VigasMadeira::aumenta(double quant) {
    quantidade += quant;
}

int VigasMadeira::obtemQuantidade() {
    return quantidade;
}

string VigasMadeira::obtemTipo() {
    return tipo;
}

bool VigasMadeira::gasta(int quant) {
    if(quant > quantidade){
        return false;
    }

    quantidade -= quant;
    return true;
}
