//
// Created by Rafael on 08/01/2022.
//

#include "serracao.h"

Serracao::Serracao(ilha *i) : Edificio(i, "ser", 10, 0, 0){}

void Serracao::produz() {
    if(Edificio::procuraTrabalhador("0")) return;
    if(Edificio::gastaRecursos("Madeira", 2)){
        Edificio::aumentaRecursos("VigasMadeira", 1);
        return;
    }
}

Edificio *Serracao::duplica() const {
    return new Serracao(*this);
}


