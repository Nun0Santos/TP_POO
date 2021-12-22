//
// Created by Rafael on 18/11/2021.
//

#include "trabalhadores.h"
#include <sstream>
//Trabalhador::Trabalhador(int c, float prob, int x, int y, int d):custo(c),probEmbora(prob),x(x),y(y), dias(d){++id;}

int Trabalhador::obtemCusto() {return custo;}

float Trabalhador::obtemProb() {return probEmbora;}

/*string Trabalhador::obtemId() {
    ostringstream oss;
    oss << id << "." << dias;
    return oss.str();
}*/



