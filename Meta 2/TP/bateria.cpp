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