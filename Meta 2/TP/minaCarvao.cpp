//
// Created by Rafael on 21/12/2021.
//

#include "minaCarvao.h"

MinaCarvao::MinaCarvao(ilha* i, int x, int y) : Edificio(i,"mnC", 10, x, y), custoSubs(10), upgradeDinheiro(10), upgradeRecurso(1), quantProd(2), probDesabar(10), quantArmazenamento(0){}

void MinaCarvao::melhora() {
    if(Edificio::getNivel() <= 5){
        if(gastaRecursos("Dinheiro", upgradeDinheiro)){
            if(gastaRecursos("VigasMadeira", upgradeRecurso)){
                Edificio::incrementaNivel();
                ++quantProd;
                quantArmazenamento += 10;
            }else{
                aumentaRecursos("Dinheiro", upgradeDinheiro);
            }
        }
    }
}

int MinaCarvao::obtemCustoSubs() {
    return custoSubs*10;
}

void MinaCarvao::produz() {
    if(!Edificio::procuraTrabalhador("M")) return;
    if(quantArmazenamento < 100){

        quantArmazenamento += quantProd;

        if(Edificio::MNT()){
            aumentaRecursos("Carvao", quantProd*2);
            return;
        }

        if(Edificio::ZNX()){
            aumentaRecursos("Carvao", quantProd+(0.1*quantProd));
            return;
        }

        if(Edificio::DSR()){
            aumentaRecursos("Carvao", quantProd/2);
            return;
        }

        aumentaRecursos("Carvao", quantProd);
    }
}

MinaCarvao &MinaCarvao::operator=(const Edificio &outro) {
    if(this == &outro) return *this;

    Edificio::operator=(outro);

    if(typeid(this) == typeid(outro)){
        const auto* aux = dynamic_cast<const MinaCarvao*>(&outro);
        custoSubs = aux->custoSubs;
        quantProd = aux->quantProd;
        upgradeDinheiro = aux->upgradeDinheiro;
        upgradeRecurso = aux->upgradeRecurso;
        probDesabar = aux->probDesabar;
        quantArmazenamento = aux->quantArmazenamento;
    }

    return *this;
}

MinaCarvao::MinaCarvao(const MinaCarvao &outro) : Edificio(outro), custoSubs(0), quantProd(0), quantArmazenamento(0), upgradeDinheiro(0), upgradeRecurso(0), probDesabar(0){
    *this = outro;
}

Edificio *MinaCarvao::duplica() const {
    return new MinaCarvao(*this);
}

int MinaCarvao::desaba() {
    double val = (double)rand() / RAND_MAX;

    if(val < probDesabar){
        return 1;
    }

    return 0;
}
