//
// Created by Rafael on 02/11/2021.
//

#ifndef TP_POO_GERAL_H
#define TP_POO_GERAL_H

#include <iostream>
#include <string>
#include <vector>
#include "ilha.h"
#include "zona.h"

bool comandos(vector<string> &v);
bool verificaComandos(const string& comando);
bool verificaTipo(const string& t);
bool verificaTrabalhador(const string& t);

void leFich(const string& filename);




#endif //TP_POO_GERAL_H
