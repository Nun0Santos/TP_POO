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
    Trabalhador() {
        id_trab = ++id;
    };
    Trabalhador(const Trabalhador& outro);


    int ID() const;
    virtual string obtemTipo();
    virtual string obtemID();
    virtual int pedeDemissao();
    virtual void aumentaDias();
    virtual int vidaBoa();
    Trabalhador& operator=(const Trabalhador& outro);
private:
    int id_trab; //Custo do trabalhador / id do trabalhador
    static int id;
};


#endif //TP_POO_TRABALHADORES_H
