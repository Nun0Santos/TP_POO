//
// Created by Rafael on 1tt6/11/2021.
//

#ifndef TP_POO_ZONA_H
#define TP_POO_ZONA_H
#include <iostream>
#include <vector>
#include "edificio.h"

class ilha;

using namespace std;

class Zona{
public:
    Zona(string t= "-", int l = 0, int c = 0) : tipo(move(t)), quant_trab(0), posL(l), posC(c), quant_edificio(0), onoff(0), ed(nullptr){
        for(int i = 0; i < 5; ++i){
            trab.emplace_back("-");
        }
    };

    void defineTipo(string str);
    void definePosL(int l);
    void definePosC(int c);
    void defineTrab(string s);
    void defineEdificio(const string& s, ilha* i);
    void defineQuantTrab();
    int obtemL() const;
    int obtemC() const;
    string obtemTrab() const;
    virtual string obtemTipo();
    int obtemQuant_Trab() const;
    string obtemEdificio() const;
    int obtemQuant_Edificios() const;
    int obtemOnOFF() const;
    Edificio* getEd();
private:
    string tipo;
    Edificio* ed;
    vector<string> trab;
    int quant_trab, quant_edificio, onoff;
    int posL, posC;
};

#endif //TP_POO_ZONA_H
