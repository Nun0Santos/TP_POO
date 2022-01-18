//
// Created by Rafael on 02/11/2021.
//

#include "geral.h"

#include "montanha.h"
#include "pastagem.h"
#include "pantano.h"
#include "floresta.h"
#include "deserto.h"
#include "zonax.h"


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

string ilha::mudaValorEdificio(int& l, int& c, const string& t, int dev) {
    if(tabuleiro[l][c]->obtemQuant_Edificios() > 0)
        return "ja tem um edificio nesta zona";
    return tabuleiro[l][c]->defineEdificio(t, this, dev);
}

string ilha::mudaValorTrab(const string& t) {
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
            if (!verificaLinCol(auxl, auxc)) return " ";
            return tabuleiro[auxl][auxc]->defineTrab("O", dias, this);
        }
    }
    if(t == "len"){
        if(verificaTrabalhador(t)){
            if (!verificaLinCol(auxl, auxc)) return " ";
            return tabuleiro[auxl][auxc]->defineTrab("L", dias, this);
        }
    }
    if(t == "min"){
        if(verificaTrabalhador(t)){
            if (!verificaLinCol(auxl, auxc)) return " ";
            return tabuleiro[auxl][auxc]->defineTrab("M", dias, this);
        }
    }

    return " ";
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
                if(tabuleiro[x][y]->obtemTipo() == "flr"){
                    oss << tabuleiro[x][y]->obtemTipo() << " | " << tabuleiro[x][y]->getNArvores() << endl;
                }else{
                    oss << tabuleiro[x][y]->obtemTipo() << endl;
                }
                break;
                case 1:
                    if(tabuleiro[x][y]->getEd() == nullptr){
                        oss << "" << endl;
                        break;
                    }
                    oss << tabuleiro[x][y]->obtemEdificio() << " | " << tabuleiro[x][y]->getNivel() << endl;
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
    int t ;
    tabuleiro = new Zona**[lin];
    for (int i = 0; i < lin; ++i) {
        tabuleiro[i] = new Zona*[col];
    }

    vector<string> tipos = {"pastagem", "floresta", "deserto", "montanha", "pantano", "zona-x"};
    unsigned num = chrono::system_clock::now().time_since_epoch().count();


    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            shuffle (tipos.begin(), tipos.end(), default_random_engine(num));

            random_device dev;
            mt19937 rng(dev());
            uniform_int_distribution<mt19937::result_type> dist6(0,5);
            t = dist6(rng);

            if(tipos[t] == "pastagem"){
                tabuleiro[i][j] = new Pastagem("pas", i, j);
                continue;
            }
            if(tipos[t] == "floresta"){
                tabuleiro[i][j] = new Floresta("flr", i, j);
                continue;
            }
            if(tipos[t] == "deserto"){
                tabuleiro[i][j] = new Deserto("dsr", i, j);
                continue;
            }
            if(tipos[t] == "montanha"){
                tabuleiro[i][j] = new Montanha("mnt", i, j);
                continue;
            }
            if(tipos[t] == "pantano"){
                tabuleiro[i][j] = new Pantano("pnt", i, j);
                continue;
            }
            if(tipos[t] == "zona-x"){
                tabuleiro[i][j] = new ZonaX("znx", i, j);
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
        for (int j = 0; j < 5; ++j) {
            oss << " |";
            for (int k = 0; k < col; ++k) {
                switch (j) {
                    case 0:
                        oss << i << "/" << k << "         ";
                        break;
                    case 1:
                        oss << "    " << tabuleiro[i][k]->obtemTipo() << "     ";
                        break;
                    case 2:
                        if(tabuleiro[i][k]->getEd() == nullptr){
                            oss << "            ";
                            break;
                        }
                        oss << "    " << tabuleiro[i][k]->obtemEdificio() << "     ";
                        break;
                    case 3:
                        oss << "  " << tabuleiro[i][k]->obtemTrab();
                        break;
                    case 4:
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
            oss << executaFich(v[1]);
            return oss.str();
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

                if(verificaTipo(aux)){
                    return ilha::mudaValorEdificio(x, y, aux, 0);
                }
                return "tipo invalido";
            }else{
                oss << "fora dos limites" << endl;
                return oss.str();
            }
        }

        if (v[0] == "cont"){
            istringstream o(v[1]);
            string aux;
            o>>aux;

            if(verificaTrabalhador(v[1])){
                return ilha::mudaValorTrab(aux);
            }
            return "trabalhador invalido";
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
            trataZonas();
            trataTrabalhadores();
            despedimentos();
            trataEdificios();
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
            return "fora dos limites";
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
            return "fora dos limites";
        }

        if(v[0] == "move"){
            istringstream ossX(v[2]);//transforma string em int
            ossX >> x;//atribui valor transformado à variavel x
            istringstream ossY(v[3]);//transforma string em int
            ossY >> y;//atribui valor transformado à variavel y

            if(verificaLinCol(x, y)){
                moveTrabalhador(x, y, v[1]);
                return oss.str();
            }
            return "fora dos limites";
        }

        if(v[0] == "vende"){
            //vender recursos
            //vender um edificio
            //fazer a distinção usando um vector onde temos os tipos de rescursos ou transformando em inteiro e verificar se é um numero
            if(verificaRecursos(v[1])){
                //verificar se a quantidade introduzida é valida
                //se for, vender os recursos, senao fazer o return
                double yD;
                istringstream ossY(v[2]);//transforma string em int
                ossY >> yD;
                if(gastaRecursos(v[1], yD)){
                    auto it = recursos.begin();
                    while(it != recursos.end()){
                        if((*it)->obtemTipo() == v[1]){
                            aumentaRecursos("Dinheiro", (*it)->vende(yD));
                            break;
                        }
                        ++it;
                    }
                    return oss.str();
                }else{
                    return "Nao tem essa quantidade de recurso";
                }
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
            apagaTrabID(v[1]);
            return oss.str();
        }
        if(v[0] == "upgrade"){
            istringstream ossX(v[1]);//transforma string em int
            ossX >> x;//atribui valor transformado à variavel x
            istringstream ossY(v[2]);//transforma string em int
            ossY >> y;//atribui valor transformado à variavel y

            if(verificaLinCol(x,y)){
                tabuleiro[x][y]->upgradeED();
                return oss.str();
            }
        }

        if(v[0] == "save"){


            return oss.str();
        }

        if(v[0] == "load"){


            return oss.str();
        }

        if(v[0] == "apaga"){


            return oss.str();
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
        ++it;
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
        trataZonas();
        trataTrabalhadores();
        despedimentos();
        trataEdificios();
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
            moveTrabalhador(x, y, v[1]);
            return oss.str();
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
        apagaTrabID(v[1]);
        return oss.str();
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
        ++it;
    }
    return false;
}

void ilha::trataEdificios() {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            if(tabuleiro[i][j]->getEd() == nullptr){
                continue;
            }
            if(tabuleiro[i][j]->obtemOnOFF() == 0){
                continue;
            }
            tabuleiro[i][j]->trataEdificios();
        }
    }
}

bool ilha::verificaLaterais(int x, int y, string t) {
    if(t == "elec"){
        if(tabuleiro[x][y]->obtemEdificio() == t){
            if((x>=1 && x<lin-1) && (y>=1 && y < col-1)){
                if((tabuleiro[x-1][y]->getEd() != nullptr && tabuleiro[x-1][y]->obtemEdificio() == "bat") || (tabuleiro[x+1][y]->getEd() != nullptr && tabuleiro[x+1][y]->obtemEdificio() == "bat") || (tabuleiro[x][y-1]->getEd() != nullptr && tabuleiro[x][y-1]->obtemEdificio() == "bat") || (tabuleiro[x][y+1]->getEd() != nullptr && tabuleiro[x][y+1]->obtemEdificio() == "bat")){
                    if(tabuleiro[x-1][y]->obtemTipo() == "flr" || tabuleiro[x+1][y]->obtemTipo() == "flr" ||tabuleiro[x][y-1]->obtemTipo() == "flr" || tabuleiro[x][y+1]->obtemTipo() == "flr"){
                        return true;
                    }
                }
            }else{
                if(x == 0 && y == 0){
                    if((tabuleiro[x+1][y]->getEd() != nullptr && tabuleiro[x+1][y]->obtemEdificio() == "bat") || (tabuleiro[x][y+1]->getEd() != nullptr && tabuleiro[x][y+1]->obtemEdificio() == "bat")){
                        if(tabuleiro[x+1][y]->obtemTipo() == "flr" || tabuleiro[x][y+1]->obtemTipo() == "flr"){
                            return true;
                        }
                    }
                }
                if(x == lin-1 && y == col-1){
                    if((tabuleiro[x-1][y]->getEd() != nullptr && tabuleiro[x-1][y]->obtemEdificio() == "bat") || (tabuleiro[x][y-1]->getEd() != nullptr && tabuleiro[x][y-1]->obtemEdificio() == "bat") ){
                        if(tabuleiro[x-1][y]->obtemTipo() == "flr" ||tabuleiro[x][y-1]->obtemTipo() == "flr"){
                            return true;
                        }
                    }
                }
                if(x == 0){
                    if((tabuleiro[x+1][y]->getEd() != nullptr && tabuleiro[x+1][y]->obtemEdificio() == "bat") || (tabuleiro[x][y-1]->getEd() != nullptr && tabuleiro[x][y-1]->obtemEdificio() == "bat") || (tabuleiro[x][y+1]->getEd() != nullptr && tabuleiro[x][y+1]->obtemEdificio() == "bat")){
                        if(tabuleiro[x+1][y]->obtemTipo() == "flr" ||tabuleiro[x][y-1]->obtemTipo() == "flr" || tabuleiro[x][y+1]->obtemTipo() == "flr"){
                            return true;
                        }
                    }
                }
                if(y == 0){
                    if((tabuleiro[x-1][y]->getEd() != nullptr && tabuleiro[x-1][y]->obtemEdificio() == "bat") || (tabuleiro[x+1][y]->getEd() != nullptr && tabuleiro[x+1][y]->obtemEdificio() == "bat") || (tabuleiro[x][y+1]->getEd() != nullptr && tabuleiro[x][y+1]->obtemEdificio() == "bat")){
                        if(tabuleiro[x-1][y]->obtemTipo() == "flr" || tabuleiro[x+1][y]->obtemTipo() == "flr" || tabuleiro[x][y+1]->obtemTipo() == "flr"){
                            return true;
                        }
                    }
                }
                if(x == lin-1){
                    if((tabuleiro[x-1][y]->getEd() != nullptr && tabuleiro[x-1][y]->obtemEdificio() == "bat") || (tabuleiro[x][y-1]->getEd() != nullptr && tabuleiro[x][y-1]->obtemEdificio() == "bat") || (tabuleiro[x][y+1]->getEd() != nullptr && tabuleiro[x][y+1]->obtemEdificio() == "bat")){
                        if(tabuleiro[x-1][y]->obtemTipo() == "flr" || tabuleiro[x][y-1]->obtemTipo() == "flr" || tabuleiro[x][y+1]->obtemTipo() == "flr"){
                            return true;
                        }
                    }
                }
                if(y == col-1){
                    if((tabuleiro[x-1][y]->getEd() != nullptr && tabuleiro[x-1][y]->obtemEdificio() == "bat") || (tabuleiro[x+1][y]->getEd() != nullptr && tabuleiro[x+1][y]->obtemEdificio() == "bat") || (tabuleiro[x][y-1]->getEd() != nullptr && tabuleiro[x][y-1]->obtemEdificio() == "bat")){
                        if(tabuleiro[x-1][y]->obtemTipo() == "flr" || tabuleiro[x+1][y]->obtemTipo() == "flr" ||tabuleiro[x][y-1]->obtemTipo() == "flr"){
                            return true;
                        }
                    }
                }
            }
        }
    }

    if(t == "fun"){
        if(tabuleiro[x][y]->obtemEdificio() == t){
            if((x>=1 && x<lin-1) && (y>=1 && y < col-1)){
                if((tabuleiro[x-1][y]->getEd() != nullptr && tabuleiro[x-1][y]->obtemEdificio() == "mnF") || (tabuleiro[x+1][y]->getEd() != nullptr && tabuleiro[x+1][y]->obtemEdificio() == "mnF") || (tabuleiro[x][y-1]->getEd() != nullptr && tabuleiro[x][y-1]->obtemEdificio() == "mnF") || (tabuleiro[x][y+1]->getEd() != nullptr && tabuleiro[x][y+1]->obtemEdificio() == "mnF")){
                    if(((tabuleiro[x-1][y]->getEd() != nullptr && tabuleiro[x-1][y]->obtemEdificio() == "mnC") || (tabuleiro[x+1][y]->getEd() != nullptr && tabuleiro[x+1][y]->obtemTipo() == "mnC") ||(tabuleiro[x][y-1]->getEd() != nullptr && tabuleiro[x][y-1]->obtemTipo() == "mnC") || (tabuleiro[x][y-1]->getEd() != nullptr && tabuleiro[x][y+1]->obtemTipo() == "mnC")) || ((tabuleiro[x-1][y]->getEd() != nullptr && tabuleiro[x-1][y]->obtemEdificio() == "elec") || (tabuleiro[x+1][y]->getEd() != nullptr && tabuleiro[x+1][y]->obtemTipo() == "elec") ||(tabuleiro[x][y-1]->getEd() != nullptr && tabuleiro[x][y-1]->obtemTipo() == "elec") || (tabuleiro[x][y+1]->getEd() != nullptr && tabuleiro[x][y+1]->obtemTipo() == "elec"))){
                        return true;
                    }
                }
            }else{
                if(x == 0 && y == 0){
                    if((tabuleiro[x-1][y]->getEd() != nullptr && tabuleiro[x+1][y]->obtemEdificio() == "mnF") || (tabuleiro[x][y+1]->getEd() != nullptr && tabuleiro[x][y+1]->obtemEdificio() == "mnF")){
                        if(((tabuleiro[x+1][y]->getEd() != nullptr && tabuleiro[x+1][y]->obtemEdificio() == "mnC") || (tabuleiro[x][y+1]->getEd() != nullptr && tabuleiro[x][y+1]->obtemEdificio() == "mnC")) || ((tabuleiro[x+1][y]->getEd() != nullptr && tabuleiro[x+1][y]->obtemEdificio() == "elec") || (tabuleiro[x][y+1]->getEd() != nullptr && tabuleiro[x][y+1]->obtemEdificio() == "elec)"))){
                            return true;
                        }
                    }
                }
                if(x == lin-1 && y == col-1){
                    if((tabuleiro[x-1][y]->getEd() != nullptr && tabuleiro[x-1][y]->obtemEdificio() == "mnF") ||(tabuleiro[x][y-1]->getEd() != nullptr && tabuleiro[x][y-1]->obtemEdificio() == "mnF") ){
                        if(((tabuleiro[x-1][y]->getEd() != nullptr && tabuleiro[x-1][y]->obtemEdificio() == "mnC") || (tabuleiro[x][y-1]->getEd() != nullptr && tabuleiro[x][y-1]->obtemEdificio() == "mnC")) || ((tabuleiro[x-1][y]->getEd() != nullptr && tabuleiro[x-1][y]->obtemEdificio() == "elec") || (tabuleiro[x][y-1]->getEd() != nullptr && tabuleiro[x][y-1]->obtemEdificio() == "elec"))){
                            return true;
                        }
                    }
                }
                if(x == 0){
                    if((tabuleiro[x+1][y]->getEd() != nullptr && tabuleiro[x+1][y]->obtemEdificio() == "mnF") || (tabuleiro[x][y-1]->getEd() != nullptr && tabuleiro[x][y-1]->obtemEdificio() == "mnF") || (tabuleiro[x][y+1]->getEd() != nullptr && tabuleiro[x][y+1]->obtemEdificio() == "mnF")){
                        if(((tabuleiro[x+1][y]->getEd() != nullptr && tabuleiro[x+1][y]->obtemEdificio() == "mnC") || (tabuleiro[x][y-1]->getEd() != nullptr && tabuleiro[x][y-1]->obtemEdificio() == "mnC") || (tabuleiro[x][y+1]->getEd() != nullptr && tabuleiro[x][y+1]->obtemEdificio() == "mnC")) || ((tabuleiro[x+1][y]->getEd() != nullptr && tabuleiro[x+1][y]->obtemEdificio() == "elec") || (tabuleiro[x][y-1]->getEd() != nullptr && tabuleiro[x][y-1]->obtemEdificio() == "elec") || (tabuleiro[x][y+1]->getEd() != nullptr && tabuleiro[x][y+1]->obtemEdificio() == "elec"))){
                            return true;
                        }
                    }
                }
                if(y == 0){
                    if((tabuleiro[x-1][y]->getEd() != nullptr && tabuleiro[x-1][y]->obtemEdificio() == "mnF") || (tabuleiro[x+1][y]->getEd() != nullptr && tabuleiro[x+1][y]->obtemEdificio() == "mnF") || (tabuleiro[x][y+1]->getEd() != nullptr && tabuleiro[x][y+1]->obtemEdificio() == "mnF")){
                        if(((tabuleiro[x-1][y]->getEd() != nullptr && tabuleiro[x-1][y]->obtemEdificio() == "mnC") || (tabuleiro[x+1][y]->getEd() != nullptr && tabuleiro[x+1][y]->obtemEdificio() == "mnC") || (tabuleiro[x][y+1]->getEd() != nullptr && tabuleiro[x][y+1]->obtemEdificio() == "mnC")) || ((tabuleiro[x-1][y]->getEd() != nullptr && tabuleiro[x-1][y]->obtemEdificio() == "elec") || (tabuleiro[x+1][y]->getEd() != nullptr &&tabuleiro[x+1][y]->obtemEdificio() == "elec") || (tabuleiro[x][y+1]->getEd() != nullptr && tabuleiro[x][y+1]->obtemEdificio() == "elec"))){
                            return true;
                        }
                    }
                }
                if(x == lin-1){
                    if((tabuleiro[x-1][y]->getEd() != nullptr && tabuleiro[x-1][y]->obtemEdificio() == "mnF") || (tabuleiro[x][y-1]->getEd() != nullptr && tabuleiro[x][y-1]->obtemEdificio() == "mnF") || (tabuleiro[x][y+1]->getEd() != nullptr && tabuleiro[x][y+1]->obtemEdificio() == "mnF")){
                        if(((tabuleiro[x-1][y]->getEd() != nullptr && tabuleiro[x-1][y]->obtemEdificio() == "mnC") || (tabuleiro[x][y-1]->getEd() != nullptr && tabuleiro[x][y-1]->obtemEdificio() == "mnC") || (tabuleiro[x][y+1]->getEd() != nullptr && tabuleiro[x][y+1]->obtemEdificio() == "mnC")) || ((tabuleiro[x-1][y]->getEd() != nullptr && tabuleiro[x-1][y]->obtemEdificio() == "elec") || (tabuleiro[x][y-1]->getEd() != nullptr && tabuleiro[x][y-1]->obtemEdificio() == "elec") || (tabuleiro[x][y+1]->getEd() != nullptr && tabuleiro[x][y+1]->obtemEdificio() == "elec"))){
                            return true;
                        }
                    }
                }
                if(y == col-1){
                    if((tabuleiro[x-1][y]->getEd() != nullptr && tabuleiro[x-1][y]->obtemEdificio() == "mnF") || (tabuleiro[x+1][y]->getEd() != nullptr && tabuleiro[x+1][y]->obtemEdificio() == "mnF") || (tabuleiro[x][y-1]->getEd() != nullptr && tabuleiro[x][y-1]->obtemEdificio() == "mnF")){
                        if(((tabuleiro[x-1][y]->getEd() != nullptr && tabuleiro[x-1][y]->obtemEdificio() == "mnC") || (tabuleiro[x+1][y]->getEd() != nullptr && tabuleiro[x+1][y]->obtemEdificio() == "mnC") || (tabuleiro[x][y-1]->getEd() != nullptr && tabuleiro[x][y-1]->obtemEdificio() == "mnC")) || ((tabuleiro[x-1][y]->getEd() != nullptr && tabuleiro[x-1][y]->obtemEdificio() == "elec") || (tabuleiro[x+1][y]->getEd() != nullptr && tabuleiro[x+1][y]->obtemEdificio() == "elec") || (tabuleiro[x][y-1]->getEd() != nullptr && tabuleiro[x][y-1]->obtemEdificio() == "elec"))){
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

bool ilha::procuraTrabalhador(int x, int y, string t) {
    return tabuleiro[x][y]->procuraTrab(move(t));
}
bool ilha::apagaTrabID(string id) {
    for(int i=0; i<lin; ++i){
        for(int j=0; j<col; ++j){
            if(tabuleiro[i][j]->obtemQuant_Trab() > 0){
                if (tabuleiro[i][j]->apagaTrabID(id)){
                    return true;
                }
            }
        }
    }
    return false;
}

void ilha::trataZonas() {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            tabuleiro[i][j]->trata(*this);
        }
    }
}

void ilha::aumentaRecursos(string str, double quant) {
    auto it = recursos.begin();
    while(it != recursos.end()){
        if((*it)->obtemTipo() == str){
            (*it)->aumenta(quant);
            break;
        }
        ++it;
    }
}

bool ilha::moveTrabalhador(int x, int y, string t) {
    for(int i = 0; i < lin; ++i){
        for (int j = 0; j < col; ++j) {
            if(tabuleiro[i][j]->obtemQuant_Trab() > 0){//verifica se tem trabalhadores
                if(tabuleiro[i][j]->procuraTrab(t, 0)){
                    if(tabuleiro[i][j]->obtemMovTrab(t) == 0){
                        Trabalhador* aux = tabuleiro[i][j]->moveTrab(t);
                        tabuleiro[x][y]->recebeTrab(aux);
                    }

                    return true;
                }

            }
        }
    }

    return false;
}

ilha &ilha::operator=(const ilha &outro) {
    if(this == &outro) return *this;

    for(int i = 0; i<col; ++i){
        delete tabuleiro[i];
    }
    delete [] tabuleiro;

    auto it = recursos.begin();
    while (it != recursos.end()){
        delete (*it);
        ++it;
    }
    recursos.clear();

    lin = outro.lin;
    col = outro.col;
    dias = outro.dias;
    contratou = outro.contratou;

    tabuleiro = new Zona**[outro.lin];
    for (int i = 0; i < outro.lin; ++i) {
        tabuleiro[i] = new Zona*[outro.col];
    }

    for (int i = 0; i < outro.lin; ++i) {
        for (int j = 0; j < outro.col; ++j) {
            tabuleiro[i][j] = outro.tabuleiro[i][j]->duplica();
        }
    }

    auto it1 = outro.recursos.begin();
    while(it1 != outro.recursos.end()){
        recursos.push_back((*it1)->duplica());
        ++it1;
    }

    return *this;
}

ilha::ilha(const ilha &outro) : dias(1), lin(0), col(0), tabuleiro(nullptr), contratou(0){
    *this = outro;
}

bool ilha::MNT(int x, int y) {
    if(tabuleiro[x][y]->obtemTipo() == "mnt") return true;

    return false;
}

bool ilha::game() {
    double qr = 0;

    auto it = recursos.begin();
    while (it != recursos.end()){
        qr += (*it)->obtemQuantidade();
        ++it;
    }

    if(qr != 0){
        if(contratou == 1){//só verifica os trabalhadores apos ter feito alguma contratação
            int qt = 0;
            for (int i = 0; i < lin; ++i) {
                for (int j = 0; j < col; ++j) {
                    qt += tabuleiro[i][j]->obtemQuant_Trab();
                }
            }

            if(qt != 0){
                return false;
            }
        }else{
            return false;
        }
    }

    return true;
}

int ilha::obtemQuantTrab(int x, int y) {
    return tabuleiro[x][y]->obtemQuant_Trab();
}

bool ilha::ZNX(int x, int y) {
    if(tabuleiro[x][y]->obtemTipo() == "znx") return true;

    return false;
}


int ilha::getContratou() const {
    return contratou;
}

void ilha::setContratou() {
    if(contratou == 0){
        contratou = 1 ;
    }
}

bool ilha::DSR(int x, int y) {
    if(tabuleiro[x][y]->obtemTipo() == "dsr") return true;

    return false;
}
