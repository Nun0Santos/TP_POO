//
// Created by Rafael on 02/11/2021.
//
/*--------------------------------------    Mina de ferro   ----------------------------------------------------

 Permite obter ferro. Pode ser construída gastando 10 vigas de madeira, em que cada viga pode
ser substituída por 10 €. Produz 2 Kg de ferro por dia. Pode ser melhorada até ao nível 5 em que cada nível
aumenta a produção em 1 kg de ferro por dia. Cada nível de melhoramento exige 15 € e 1 viga de madeira
(não substituível por €). A mina apenas produz se existir um mineiro na zona em que a mina se encontra. Em
cada dia a mina tem 15% de probabilidade de desabar. A mina de ferro armazena até 100 kg de ferro, mais 10
Kg por cada nível adicional. Depois disso, pára de produzir.*/

#include "geral.h"

void mina_ferro::custoConstrucao() {
        string resposta;

        cout <<"Deseja construir a Mina de Ferro com dinhero? [S/N]" << endl;
        cin >> resposta;

        /*if(){
            cout << "Resposta errada!"<<endl;
            mina_ferro::custoConstrucao();
        }*/



}



