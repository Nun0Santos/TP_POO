//
// Created by Rafael on 02/11/2021.
//

#include "geral.h"

#include "montanha.h"

#include "pastagem.h"
#include "pantano.h"
#include "floresta.h"
#include "deserto.h"



#include <sstream>

#include <fstream>
#include <algorithm>
#include <random>
#include <chrono>

#include "dinheiro.h"
#include "barraAco.h"
#include "ferro.h"
#include "vigasMadeira.h"
#include "madeira.h"
#include "eletricidade.h"
#include "carvao.h"
#include "ilha.h"


using namespace std;

void ilha::defineLin(int a) {
    lin = a;
}

void ilha::defineCol(int a){
    col = a;
}

int ilha::obtemCol() const {
    return col;
}

int ilha::obtemLin() const {
    return lin;
}

void ilha::mudaValorEdificio(int& l, int& c, const string& t, int dev) {
    if(tabuleiro[l][c]->obtemQuant_Edificios() > 0)
        return;
    tabuleiro[l][c]->defineEdificio(t, this, dev);
}

void ilha::mudaValorTrab(const string& t) {
    int auxl, auxc , flag = 0;

    for (auxl = 0; auxl < lin; auxl++) {
        for(auxc = 0; auxc < col; auxc++){
            if(tabuleiro[auxl][auxc]->obtemTipo() == "pas"){
                flag = 1;
                break;
            }
        }
        if(flag == 1){break;}
    }

    if(t == "oper"){
        if(verificaTrabalhador(t)){
            tabuleiro[auxl][auxc]->defineTrab("O", dias);
            tabuleiro[auxl][auxc]->defineQuantTrab();
            return;
        }
        cout << "Este trabalhador não existe" << endl;
    }
    if(t == "len"){
        if(verificaTrabalhador(t)){
            tabuleiro[auxl][auxc]->defineTrab("L", dias);
            tabuleiro[auxl][auxc]->defineQuantTrab();
            return;
        }
        cout << "Este trabalhador não existe" << endl;
    }
    if(t == "min"){
        if(verificaTrabalhador(t)){
            tabuleiro[auxl][auxc]->defineTrab("M", dias);
            tabuleiro[auxl][auxc]->defineQuantTrab();
            return;
        }
        cout << "Este trabalhador não existe" << endl;
    }
}

bool ilha::verificaLinCol(int x, int y) const {
    if(x<=lin && y<=col)
        return true;
    return false;
}
string ilha::mostraZona(int x, int y) {
    ostringstream oss;

    for(int i = 0; i < 4; ++i){
        switch (i) {
            case 0:
                oss << tabuleiro[x][y]->obtemTipo() << endl;
                break;
                case 1:
                    if(tabuleiro[x][y]->getEd() == nullptr){
                        oss << "" << endl;
                        break;
                    }
                    oss << tabuleiro[x][y]->obtemEdificio() << endl;
                    break;
                    case 2:
                        oss << tabuleiro[x][y]->obtemWorkers() << endl;
                        break;
                        case 3:
                            oss << tabuleiro[x][y]->obtemQuant_Trab() << endl;
                            break;
                            default:
                                break;
        }
    }
    return oss.str();
}

string ilha::mostraTodasZonas() {
    ostringstream oss;
    int a = 1;

    for (int i = 0; i < lin; ++i) {
        oss << "\n";
        for (int j = 0; j < col; ++j) {
            oss << "Zona " << a << "\n";
            oss << mostraZona(i, j) << "\n";
            ++a;
        }
    }
    return oss.str();
}

void ilha::criaIlha() {
    tabuleiro = new Zona**[lin];
    for (int i = 0; i < lin; ++i) {
        tabuleiro[i] = new Zona*[col];
    }

    vector<string> tipos = {"pastagem", "floresta", "deserto", "montanha", "pantano", "zona-x"};
    unsigned num = chrono::system_clock::now().time_since_epoch().count();

    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            shuffle (tipos.begin(), tipos.end(), default_random_engine(num));
            if(tipos[0] == "pastagem"){
                tabuleiro[i][j] = new Pastagem();
                continue;
            }
            if(tipos[0] == "floresta"){
                tabuleiro[i][j] = new Floresta();
                continue;
            }
            if(tipos[0] == "deserto"){
                tabuleiro[i][j] = new Deserto();
                continue;
            }
            if(tipos[0] == "montanha"){
                tabuleiro[i][j] = new Montanha();
                continue;
            }
            if(tipos[0] == "pantano"){
                tabuleiro[i][j] = new Pantano();
                continue;
            }
            if(tipos[0] == "zona-x"){
                tabuleiro[i][j] = new Pastagem();
                continue;
            }
        }
    }
}

string ilha::mostraIlha() {
    ostringstream oss;

    oss << "Dia " << dias << endl;

    for(auto & it : recursos){
        oss << it->obtemTipo() << ": " << it->obtemQuantidade() << "| ";
    }

    oss << "\n";

    for (int k = 0; k < col; ++k) {
        if(k < col-1)
            oss << "+ ----------- ";
        else
            oss << "+ ----------- +";
    }

    for (int i = 0; i < lin; ++i) {
        oss << "\n";
        for (int j = 0; j < 4; ++j) {
            oss << " |";
            for (int k = 0; k < col; ++k) {
                switch (j) {
                    case 0:
                        oss << "    " << tabuleiro[i][k]->obtemTipo() << "     ";
                        break;
                    case 1:
                        if(tabuleiro[i][k]->getEd() == nullptr){
                            oss << "            ";
                            break;
                        }
                        oss << "    " << tabuleiro[i][k]->obtemEdificio() << "     ";
                        break;
                    case 2:
                        oss << "  " << tabuleiro[i][k]->obtemTrab();
                        break;
                    case 3:
                        oss <<  "     " << tabuleiro[i][k]->obtemQuant_Trab() << "      ";
                        break;
                    default:
                        break;
                }
                oss << " |";
            }
            oss << "\n";
        }
        for (int k = 0; k < col; ++k) {
            if(k < col-1)
                oss << " + -----------";
            else
                oss << " + ----------- +";
        }
    }
    return oss.str();
}


string ilha::executa(string s1) {
    string s2;
    vector<string> v;
    ostringstream oss;

    int x = 0, y = 0;

    stringstream ss(s1);

    while (getline(ss, s2, ' ')) {
        v.push_back(s2);
    }

    if(comandos(v)){//função que verifica se o comando e se o tipo são válidos
        //COMANDOS DO FICHEIRO
        if(v[0] == "exec"){
            executaFich(v[1]);
        }

        //COMANDOS STDIN
        if (v[0] == "cons"){
            istringstream ossX(v[2]);//transforma string em int
            ossX >> x;//atribui valor transformado à variavel x
            istringstream ossY(v[3]);//transforma string em int
            ossY >> y;//atribui valor transformado à variavel y

            if (verificaLinCol(x,y)){
                istringstream o(v[1]);
                string aux;
                o>>aux;

                ilha::mudaValorEdificio(x, y, aux, 0);
                return oss.str();
            }else{
                oss << "fora dos limites" << endl;
                return oss.str();
            }
        }

        if (v[0] == "cont"){
            istringstream o(v[1]);
            string aux;
            o>>aux;

            ilha::mudaValorTrab(aux);
            return oss.str();
        }

        if(v[0] == "list"){
            if(v.size() > 1){
                istringstream ossX(v[1]);//transforma string em int
                ossX >> x;//atribui valor transformado à variavel x
                istringstream ossY(v[2]);//transforma string em int
                ossY >> y;//atribui valor transformado à variavel y

                if(verificaLinCol(x,y)){
                    oss << mostraZona(x,y);
                    return oss.str();
                }
            }
            else{
                oss << mostraTodasZonas();
                return oss.str();
            }
        }

        if(v[0] == "next"){
            //trataTrabalhadores();
            //despedimentos();
            ++dias;
            return oss.str();
        }

        if(v[0] == "liga"){
            istringstream ossX(v[1]);//transforma string em int
            ossX >> x;//atribui valor transformado à variavel x
            istringstream ossY(v[2]);//transforma string em int
            ossY >> y;//atribui valor transformado à variavel y

            if(verificaLinCol(x,y)){
                if(tabuleiro[x][y]->getEd() == nullptr){
                    return oss.str();
                }
                if(tabuleiro[x][y]->obtemOnOFF() == 0){
                    tabuleiro[x][y]->ligaDesligaED();
                }
                oss << tabuleiro[x][y]->obtemOnOFF();
                return oss.str();
            }
        }

        if(v[0] == "des"){
            istringstream ossX(v[1]);//transforma string em int
            ossX >> x;//atribui valor transformado à variavel x
            istringstream ossY(v[2]);//transforma string em int
            ossY >> y;//atribui valor transformado à variavel y

            if(verificaLinCol(x,y)){
                if(tabuleiro[x][y]->getEd() == nullptr){
                    return oss.str();
                }
                if(tabuleiro[x][y]->obtemOnOFF() == 1){
                    tabuleiro[x][y]->ligaDesligaED();
                }
                oss << tabuleiro[x][y]->obtemOnOFF();
                return oss.str();
            }
        }

        if(v[0] == "move"){
            istringstream ossX(v[2]);//transforma string em int
            ossX >> x;//atribui valor transformado à variavel x
            istringstream ossY(v[3]);//transforma string em int
            ossY >> y;//atribui valor transformado à variavel y

            if(verificaLinCol(x, y)){

            }
        }

        if(v[0] == "vende"){
            //vender recursos
            //vender um edificio
            //fazer a distinção usando um vector onde temos os tipos de rescursos ou transformando em inteiro e verificar se é um numero
            if(verificaRecursos(v[1])){
                //verificar se a quantidade introduzida é valida
                //se for, vender os recursos, senao fazer o return
            }
            istringstream ossX(v[1]);//transforma string em int
            ossX >> x;//atribui valor transformado à variavel x
            istringstream ossY(v[2]);//transforma string em int
            ossY >> y;//atribui valor transformado à variavel y

            if(verificaLinCol(x, y)){
                //vender o edificio na posicao indicada
                if(tabuleiro[x][y]->getEd() != nullptr){
                    tabuleiro[x][y]->vendeEdificio();
                }
                return oss.str();
            }
        }

        if(v[0] == "save"){
            //temos que copiar a nossa ilha atual para uma ilha auxiliar, para usarmos os operadores e construtores por copia
        }
        if(v[0] == "load"){
            //mostrar a ilha auxiliar
        }
        if(v[0] == "apaga"){
            //apagar a ilha auxiliar
        }
        if(v[0] == "debcash"){
            istringstream ossQ(v[1]);
            ossQ >> x;
            aumentaRecursos("Dinheiro", x);

            return oss.str();
        }
        if(v[0] == "debed"){
            istringstream ossX(v[2]);//transforma string em int
            ossX >> x;//atribui valor transformado à variavel x
            istringstream ossY(v[3]);//transforma string em int
            ossY >> y;//atribui valor transformado à variavel y

            if (verificaLinCol(x,y)){
                istringstream o(v[1]);
                string aux;
                o>>aux;

                ilha::mudaValorEdificio(x, y, aux, 1);//passamos o 1 para indicar que é o comando do programador
                return oss.str();
            }else{
                oss << "fora dos limites" << endl;
                return oss.str();
            }
        }
        if(v[0] == "debkill"){
            //apagar um trabalhador através do id
        }
    }
    return "Comando invalido\n";
}

void ilha::despedimentos() {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            if(tabuleiro[i][j]->obtemQuant_Trab() == 0){
                continue;
            }
            tabuleiro[i][j]->verificaDespedimento();
        }
    }

    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            if(tabuleiro[i][j]->obtemQuant_Trab() == 0){
                continue;
            }
            tabuleiro[i][j]->verificaDespedimento();
        }
    }
}

void ilha::iniciaRecursos() {
    recursos.push_back(new Dinheiro);
    recursos.push_back(new Carvao);
    recursos.push_back(new Ferro);
    recursos.push_back(new BarraAco);
    recursos.push_back(new Eletricidade);
    recursos.push_back(new VigasMadeira);
    recursos.push_back(new Madeira);
}

void ilha::aumentaRecursos(string str, int quant) {
    auto it = recursos.begin();
    while(it != recursos.end()){
        if((*it)->obtemTipo() == str){
            (*it)->aumenta(quant);
            break;
        }
    }
}

bool ilha::gastaRecursos(string str, int quant) {
    auto it = recursos.begin();
    while(it != recursos.end()){
        if((*it)->obtemTipo() == str){
            if((*it)->obtemQuantidade() >= quant){
                (*it)->gasta(quant);
                return true;
            }
            break;
        }
        ++it;
    }
    return false;
}

void ilha::trataTrabalhadores() {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            if(tabuleiro[i][j]->obtemQuant_Trab() == 0){
                continue;
            }
            tabuleiro[i][j]->trataTrabalhadores();
        }
    }
}

string ilha::executaFich(string s1) {
    vector<string> v;
    string line;
    int x, y;
    ostringstream oss;


    ifstream fich_leitura(s1);
    if(!fich_leitura.is_open()) {
        oss << "Erro ao tentar abrir o ficheiro";
        return oss.str();
    }

    getline(fich_leitura,line, '\n');

    fich_leitura.close();

    stringstream ss1(line);
    while (getline(ss1, line, ' ')) {
        v.push_back(line);
    }

    if (v[0] == "cons"){
        istringstream ossX(v[2]);//transforma string em int
        ossX >> x;//atribui valor transformado à variavel x
        istringstream ossY(v[3]);//transforma string em int
        ossY >> y;//atribui valor transformado à variavel y

        if (verificaLinCol(x,y)){
            istringstream o(v[1]);
            string aux;
            o>>aux;

            ilha::mudaValorEdificio(x, y, aux, 0);
            return oss.str();
        }else{
            oss << "fora dos limites" << endl;
            return oss.str();
        }
    }

    if (v[0] == "cont"){
        istringstream o(v[1]);
        string aux;
        o>>aux;

        ilha::mudaValorTrab(aux);
        return oss.str();
    }

    if(v[0] == "list"){
        if(v.size() > 1){
            istringstream ossX(v[1]);//transforma string em int
            ossX >> x;//atribui valor transformado à variavel x
            istringstream ossY(v[2]);//transforma string em int
            ossY >> y;//atribui valor transformado à variavel y

            if(verificaLinCol(x,y)){
                oss << mostraZona(x,y);
                return oss.str();
            }
        }
        else{
            oss << mostraTodasZonas();
            return oss.str();
        }
    }

    if(v[0] == "next"){
        trataTrabalhadores();
        despedimentos();
        ++dias;
        return oss.str();
    }

    if(v[0] == "liga"){
        istringstream ossX(v[1]);//transforma string em int
        ossX >> x;//atribui valor transformado à variavel x
        istringstream ossY(v[2]);//transforma string em int
        ossY >> y;//atribui valor transformado à variavel y

        if(verificaLinCol(x,y)){
            if(tabuleiro[x][y]->getEd() == nullptr){
                return oss.str();
            }
            if(tabuleiro[x][y]->obtemOnOFF() == 0){
                tabuleiro[x][y]->ligaDesligaED();
            }
            oss << tabuleiro[x][y]->obtemOnOFF();
            return oss.str();
        }
    }

    if(v[0] == "des"){
        istringstream ossX(v[1]);//transforma string em int
        ossX >> x;//atribui valor transformado à variavel x
        istringstream ossY(v[2]);//transforma string em int
        ossY >> y;//atribui valor transformado à variavel y

        if(verificaLinCol(x,y)){
            if(tabuleiro[x][y]->getEd() == nullptr){
                return oss.str();
            }
            if(tabuleiro[x][y]->obtemOnOFF() == 1){
                tabuleiro[x][y]->ligaDesligaED();
            }
            oss << tabuleiro[x][y]->obtemOnOFF();
            return oss.str();
        }
    }

    if(v[0] == "move"){
        //mudar o trabalhador de sitio
    }

    if(v[0] == "vende"){
        //vender recursos
        //vender um edificio
        //fazer a distinção usando um vector onde temos os tipos de rescursos ou transformando em inteiro e verificar se é um numero
        if(verificaRecursos(v[1])){
            //verificar se a quantidade introduzida é valida
            //se for, vender os recursos, senao fazer o return
        }
        istringstream ossX(v[1]);//transforma string em int
        ossX >> x;//atribui valor transformado à variavel x
        istringstream ossY(v[2]);//transforma string em int
        ossY >> y;//atribui valor transformado à variavel y

        if(verificaLinCol(x, y)){
            //vender o edificio na posicao indicada
            if(tabuleiro[x][y]->getEd() != nullptr){
                if(tabuleiro[x][y]->obtemOnOFF() == 1){
                    tabuleiro[x][y]->vendeEdificio();
                }
            }
            return oss.str();
        }
    }

    if(v[0] == "save"){
        //temos que copiar a nossa ilha atual para uma ilha auxiliar, para usarmos os operadores e construtores por copia
    }

    if(v[0] == "load"){
        //mostrar a ilha auxiliar
    }

    if(v[0] == "apaga"){
        //apagar a ilha auxiliar
    }

    if(v[0] == "debcash"){
        istringstream ossQ(v[1]);
        ossQ >> x;
        aumentaRecursos("Dinheiro", x);
    }

    if(v[0] == "debed"){
        istringstream ossX(v[2]);//transforma string em int
        ossX >> x;//atribui valor transformado à variavel x
        istringstream ossY(v[3]);//transforma string em int
        ossY >> y;//atribui valor transformado à variavel y

        if (verificaLinCol(x,y)){
            istringstream o(v[1]);
            string aux;
            o>>aux;

            ilha::mudaValorEdificio(x, y, aux, 1);//passamos o 1 para indicar que é o comando do programador
            return oss.str();
        }else{
            oss << "fora dos limites" << endl;
            return oss.str();
        }
    }
    if(v[0] == "debkill"){
        //apagar um trabalhador através do id
    }

    return "Comando invalido\n";
}

bool ilha::gastaRecursos(string str, double quant) {
    auto it = recursos.begin();
    while(it != recursos.end()){
        if((*it)->obtemTipo() == str){
            if((*it)->obtemQuantidade() >= quant){
                (*it)->gasta(quant);
                return true;
            }
            break;
        }
    }
    return false;
}

