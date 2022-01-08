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

Montanha &Montanha::operator=(const Zona &outro) {
    if(this == &outro) return *this;

    Zona::operator=(outro);

    if(typeid(this) == typeid(outro)){
        const auto* aux = dynamic_cast<const Montanha*>(&outro);
        probDemissao = aux->probDemissao;
        aumentoProd = aux->aumentoProd;
        quantFerro = aux->quantFerro;
    }
    return *this;
}

Zona *Montanha::duplica() const {
    return new Montanha(*this);
}

Montanha::Montanha(const Montanha &outro) : Zona(outro),probDemissao(0), aumentoProd(0), quantFerro(0){
    *this = outro;
}
