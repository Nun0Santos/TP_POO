//
// Created by User on 12/01/2022.
//

#include "edificiox.h"

Edificiox::Edificiox(ilha *i, int i1, int i2) : Edificio(i, "edX", 30, 0, 0){}

void Edificiox::produz() {
    if(Edificio::procuraTrabalhador("O") && Edificio::procuraTrabalhador("M") && Edificio::procuraTrabalhador("L")){
        aumentaRecursos("Ferro",5);
        aumentaRecursos("BarraAco",5);
        aumentaRecursos("Carvao",5);
        aumentaRecursos("Madeira",5);
        aumentaRecursos("VigasMadeira",5);
        aumentaRecursos("Electriciade",5);
    }
}


