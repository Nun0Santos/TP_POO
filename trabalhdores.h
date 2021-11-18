//
// Created by Rafael on 18/11/2021.
//

#ifndef TP_POO_TRABALHDORES_H
#define TP_POO_TRABALHDORES_H

#include <iostream>
using namespace std;


class Trabalhador{
public:
    Trabalhador(string str) : tipo(move(str)){};

    string obtemTipo() const;
private:
    string tipo;
};

#endif //TP_POO_TRABALHDORES_H
