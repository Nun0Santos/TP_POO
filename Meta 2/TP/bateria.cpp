//
// Created by Rafael on 21/12/2021.
//

#include "bateria.h"

Bateria::Bateria(ilha *i) : Edificio(i, "bat", 10, 0, 0), quantEletricidade(100), upgradeDinheiro(5){}

void Bateria::melhora() {
    if(Edificio::getNivel() <= 5){
        if(gastaRecursos("Dinheiro", upgradeDinheiro)){
            Edificio::incrementaNivel();
            quantEletricidade += 50;
        }
    }
}

Bateria &Bateria::operator=(const Edificio &outro) {
    if(this == &outro) return *this;

    Edificio::operator=(outro);

    if(typeid(this) == typeid(outro)){
        const auto* aux = dynamic_cast<const Bateria*> (&outro);
        quantEletricidade = aux->quantEletricidade;
        upgradeDinheiro = aux->upgradeDinheiro;
    }

    return *this;
}

Bateria::Bateria(const Bateria &outro) : Edificio(outro), quantEletricidade(0), upgradeDinheiro(0){
    *this = outro;
}

Edificio *Bateria::duplica() const {
    return new Bateria(*this);
}
