//
// Created by Rafael on 21/12/2021.
//

#include "centralEletrica.h"

CentralEletrica::CentralEletrica(ilha* i, int x, int y) : Edificio(i, "elec", 15, x, y), quantCarvao(0){}

void CentralEletrica::produz() {
    if(!Edificio::procuraTrabalhador("O")) return;
    if(Edificio::verificaLaterais("elec")){
        if(Edificio::gastaRecursos("Madeira", 1)){
            if(ZNX()){
                Edificio::aumentaRecursos("Eletricidade", 1+(0.1*1));
                if(quantCarvao<100){
                    Edificio::aumentaRecursos("Carvao", 1+(0.1*1));
                    ++quantCarvao;
                }
            }
            Edificio::aumentaRecursos("Eletricidade", 1);
            if(quantCarvao<100){
                Edificio::aumentaRecursos("Carvao", 1);
                ++quantCarvao;
            }
        }
    }
}

CentralEletrica &CentralEletrica::operator=(const CentralEletrica &outro) {
    if(this == &outro) return  *this;

    Edificio::operator=(outro);

    if(typeid(this) == typeid(outro)){
        const auto* aux = dynamic_cast<const CentralEletrica*>(&outro);
        quantCarvao = aux->quantCarvao;
    }
    return *this;
}

Edificio *CentralEletrica::duplica() const {
    return new CentralEletrica(*this);
}
