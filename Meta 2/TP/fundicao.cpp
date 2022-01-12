//
// Created by Rafael on 23/12/2021.
//

#include "fundicao.h"

Fundicao::Fundicao(ilha *i, int x, int y) : Edificio(i, "fun", 10, x, y){}

void Fundicao::produz() {
    if(Edificio::procuraTrabalhador("0")) return;
    if(Edificio::verificaLaterais("fun")){
        if(ZNX()){
            if(Edificio::gastaRecursos("Ferro", 1.5)){
                if(Edificio::gastaRecursos("Carvao", 0.5)){
                    Edificio::aumentaRecursos("BarraAco", 1+(0.1*1));
                    return;
                }
                Edificio::aumentaRecursos("Ferro", 1.5);
            }
        }
        if(Edificio::gastaRecursos("Ferro", 1.5)){
            if(Edificio::gastaRecursos("Carvao", 0.5)){
                Edificio::aumentaRecursos("BarraAco", 1);
                return;
            }
            Edificio::aumentaRecursos("Ferro", 1.5);
        }
    }
}

Edificio *Fundicao::duplica() const {
    return new Fundicao(*this);
}

