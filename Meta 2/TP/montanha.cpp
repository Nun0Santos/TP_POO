//
// Created by Rafael on 18/12/2021.
//

#include "montanha.h"
#include "ilha.h"

Montanha::Montanha(string t, int x, int y) : Zona(t, x , y),probDemissao(0.05), aumentoProd(1), quantFerro(0){}

void Montanha::aumentaProbDemissao() {
    //
}


void Montanha::trata(ilha& i){
    if(Zona::obtemQuant_Trab() == 0){
        i.aumentaRecursos("Ferro", 0.1);
    }else{
        i.aumentaRecursos("Ferro", 0.1*Zona::obtemQuant_Trab());
    }
}
