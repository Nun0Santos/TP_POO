//
// Created by Rafael on 16/11/2021.
//

#ifndef TP_POO_ZONA_H
#define TP_POO_ZONA_H

#include <iostream>
using namespace std;

class Zona{
public:
    //Zona(string& t) : tipo(t) {};

    void defineTipo(string str);
    void definePosL(int l);
    void definePosC(int c);
    int obtemL() const;
    int obtemC() const;
    string obtemDescricao() const;

private:
    string tipo;
    char trab[5];
    int quant_trab;
    int posL, posC;
};

#endif //TP_POO_ZONA_H
