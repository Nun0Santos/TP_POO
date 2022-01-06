//
// Created by Rafael on 21/12/2021.
//

#include "centralEletrica.h"

CentralEletrica::CentralEletrica(ilha* i, int x, int y) : Edificio(i, "elec", 15, x, y), quantCarvao(0){}

void CentralEletrica::produz() {
    if(!Edificio::procuraTrabalhador("O")) return;
    if(Edificio::verificaLaterais("elec")){
        if(Edificio::gastaRecursos("Madeira", 1)){
            Edificio::aumentaRecursos("Eletricidade", 1);
            if(quantCarvao<100){
                Edificio::aumentaRecursos("Carvao", 1);
                ++quantCarvao;
            }
        }
    }
}
