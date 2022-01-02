//
// Created by Rafael on 18/11/2021.
//

#ifndef TP_POO_TRABALHADORES_H
#define TP_POO_TRABALHADORES_H

#include <iostream>
#include <sstream>

using namespace std;

class Zona;

class Trabalhador{
public:
    Trabalhador(int i) : id_trab(i){};
    Trabalhador(const Trabalhador& outro);


    int ID() const;
    virtual string obtemTipo();
    virtual string obtemID();
    virtual int obtemDiasSim();
    virtual int pedeDemissao();
    virtual void aumentaDias();
    virtual int vidaBoa();
    virtual int obtemIDT();
    virtual int obtemCusto();
    virtual double obtemProb();
    virtual int obtemDescanso();
    virtual int obtemDID();
    Trabalhador& operator=(const Trabalhador& outro);
    static int setID();
private:
    int id_trab; //id do trabalhador
    static int id;
};

#endif //TP_POO_TRABALHADORES_H
