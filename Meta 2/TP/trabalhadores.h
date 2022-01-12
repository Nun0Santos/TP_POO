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
    Trabalhador(string t, int c, double p, int dias, int d, Zona* z);
    Trabalhador(string t, int c, double p, int dias, int d, Zona* z, int i, int m);
    Trabalhador(const Trabalhador& outro);
    virtual ~Trabalhador() = default;


    int ID() const;//obtem id_trab
    string obtemTipo();
    string obtemID() const;
    int obtemDiasSim() const;//obtem dias
    virtual int pedeDemissao();//ver se pede demissao
    void aumentaDias();//incrementa dias
    virtual int vidaBoa();//ver se o lenhador está no dia de descanso
    int obtemCusto() const;
    double obtemProb() const;
    virtual int obtemDescanso();//obtem descanso do lenhador
    int obtemDID();//obtem d
    Trabalhador& operator=(const Trabalhador& outro);
    bool previneDesp();//verificar se impede o despedimento devido a estar numa pastagem
    void movimenta();
    int obtemMovim() const;
    void redefineZona(Zona* z_a);
    virtual Trabalhador* duplica() const;
    double aumentoProbDem();
    bool isMNT();

private:
    string tipo;
    int custo; //Custo do trabalhador
    double probEmbora; //Probabilidade do trabalhador ir embora
    int dias, d; //Dias da simulacao / dia do jogo em que o trabalhador foi contratado
    int id_trab; //id do trabalhador
    static int id;
    Zona* z;
    int movim;//0 = não se movimentou; 1 = movimentou
};

#endif //TP_POO_TRABALHADORES_H
