//
// Created by Rafael on 21/12/2021.
//

#include "minaCarvao.h"

MinaCarvao::MinaCarvao(ilha* i, int x, int y) : Edificio(i,"mnC", 10, x, y), custoSubs(10), upgradeDinheiro(10), upgradeRecurso(1), quantProd(2), probDesabar(10), quantArmazenamento(100){}

void MinaCarvao::melhora() {
    if(Edificio::getNivel() <= 5){
        if(gastaRecursos("Dinheiro", upgradeDinheiro)){
            if(gastaRecursos("VigaMadeira", upgradeRecurso)){
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
    if(!Edificio::procuraTrabalhador("O")) return;

}
