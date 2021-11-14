//
// Created by Rafael on 02/11/2021.
//

#ifndef TP_POO_MINA_FERRO_H
#define TP_POO_MINA_FERRO_H

#include "geral.h"
using namespace std;



class mina_ferro{
public:
    void custoConstrucao();
    void aumentaNivel();
    void adicionaArmazenamento();



private:
    int nivel = 1;
    const int max_Nivel = 5;
    int armazenamento;

};


















#endif //TP_POO_MINA_FERRO_H
