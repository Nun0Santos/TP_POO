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

void ilha::mudaValorEdificio(int& l, int& c, const string& t) {
    if(tabuleiro[l][c]->obtemQuant_Edificios() > 0)
        return;
    tabuleiro[l][c]->defineEdificio(t, this);
}

void ilha::mudaValorTrab(const string& t) {
    int auxl = 0, auxc = 0, flag = 0;

    for (auxl ; auxl < lin; auxl++) {
        for(auxc ; auxc < col; auxc++){
            if(tabuleiro[auxl][auxc]->obtemTipo() == "pas"){
                flag = 1;
                break;
            }
        }
        if(flag == 1){break;}
    }

    if(t == "oper"){
        if(verificaTrabalhador(t)){
            tabuleiro[auxl][auxc]->defineTrab("O");
            tabuleiro[auxl][auxc]->defineQuantTrab();
            return;
        }
        cout << "Este trabalhador não existe" << endl;
    }
    if(t == "len"){
        if(verificaTrabalhador(t)){
            tabuleiro[auxl][auxc]->defineTrab("L");
            tabuleiro[auxl][auxc]->defineQuantTrab();
            return;
        }
        cout << "Este trabalhador não existe" << endl;
    }
    if(t == "min"){
        if(verificaTrabalhador(t)){
            tabuleiro[auxl][auxc]->defineTrab("M");
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
                        oss << tabuleiro[x][y]->obtemTrab() << endl;
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
            vector<string> lines;
            string line;
            int fx, fy;

            ifstream fich_leitura(v[1]);
            if(!fich_leitura.is_open()) {
                oss << "Erro ao tentar abrir o ficheiro";
                return oss.str();
            }

            getline(fich_leitura,line, '\n');

            fich_leitura.close();

            stringstream ss1(line);
            while (getline(ss1, line, ' ')) {
                lines.push_back(line);
            }


            if(comandos(lines)){
                if (lines[0] == "cons"){
                    istringstream ossFX(lines[2]);//transforma string em int
                    ossFX >> fx;//atribui valor transformado à variavel x
                    istringstream ossFY(lines[3]);//transforma string em int
                    ossFY >> fy;//atribui valor transformado à variavel y

                    if (verificaLinCol(fx,fy)){

                        istringstream o(lines[1]);
                        string aux;
                        o>>aux;

                        ilha::mudaValorEdificio(fx, fy, aux);
                        return oss.str();
                    }
                }
                if (lines[0] == "cont"){
                    istringstream o(lines[1]);
                    string aux;
                    o>>aux;

                    ilha::mudaValorTrab(aux);
                }
                if(lines[0] == "list"){
                    if(lines.size() > 1){
                        istringstream ossX(lines[1]);//transforma string em int
                        ossX >> x;//atribui valor transformado à variavel x
                        istringstream ossY(lines[2]);//transforma string em int
                        ossY >> y;//atribui valor transformado à variavel y

                        if(verificaLinCol(x,y)){
                            cout << mostraZona(x,y);
                            return oss.str();
                        }
                    }
                    else{
                        oss << mostraTodasZonas();
                        return oss.str();
                    }
                }
            }else{
                oss << "comandos do ficheiro não são válidos" << endl;
                return oss.str();
            }

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

                ilha::mudaValorEdificio(x, y, aux);
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
            return oss.str();
        }
    }
    return "Comando invalido\n";
}

