//
// Created by Rafael on 1tt6/11/2021.
//

#ifndef TP_POO_ZONA_H
#define TP_POO_ZONA_H
#include <iostream>
#include <vector>
#include "edificio.h"
#include "trabalhadores.h"

class ilha;

using namespace std;

class Zona{
public:
    Zona(string t= "-", int l = 0, int c = 0) : tipo(move(t)), quant_trab(0), posL(l), posC(c), quant_edificio(0), ed(nullptr){
        for(int i = 0; i < 5; ++i){
            trab.emplace_back("-");
        }
    };

    virtual ~Zona(){
        delete ed;

        auto it = workers.begin();
        while (it != workers.end()){
            delete (*it);
            ++it;
        }
    }


    string defineTrab(string s, int dia, ilha* il);
    string defineEdificio(const string& s, ilha* i, int dev);
    string obtemTrab() const;
    string obtemWorkers() const;
    string obtemTipo();
    int obtemQuant_Trab() const;
    string obtemEdificio() const;
    int obtemQuant_Edificios() const;
    int obtemOnOFF() const;
    Edificio* getEd() const;
    void vendeEdificio();
    void ligaDesligaED();
    void verificaDespedimento();
    void trataTrabalhadores();
    void trataEdificios();
    virtual void trata(ilha& i);
    bool procuraTrab(string t);
    bool apagaTrabID(string id);
    int contaTrab(string t);
    string obtemTipo(string t);
    int obtemCusto(string t);
    double obtemProb(string t);
    int obtemDiasSim(string t);
    int pedeDemissao(string t);
    int obtemIDT(string t);
    int obtemDescanso(string t);
    int obtemDID(string t);
    bool procuraTrab(string t, int a);
    void destroiED();
    void apagaTodosTrab();
    virtual int getNArvores() const;
    virtual double obtemRedProd();
    bool previneDespedimento();
    int obtemMovTrab(string t);
    Trabalhador* moveTrab(string t);
    void recebeTrab(Trabalhador* auxt);
    virtual double getAumentoProbDem() const;

    Zona& atribui(const Zona& outro);
    virtual Zona* duplica() const = 0;
    void upgradeED();

private:
    string tipo;
    Edificio* ed;
    vector<string> trab;
    vector<Trabalhador*> workers;
    int quant_trab, quant_edificio;
    int posL, posC;
};

#endif //TP_POO_ZONA_H
