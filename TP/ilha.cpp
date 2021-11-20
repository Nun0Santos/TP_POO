//
// Created by Rafael on 02/11/2021.
//

#include "geral.h"
#include <sstream>
#include<limits>
#include <fstream>

using namespace std;

void ilha::defineLin() {
    int auxl;
    cout << "Quantas linhas quer? " << endl;
    cin >> auxl;
    if(auxl>=3 && auxl<=8){
        lin = auxl;
        return;
    }
    cout << "Valor errado" << endl;
    ilha::defineLin();
}

void ilha::defineCol(){
    int auxc;

    cout << "Quantas colunas quer? " << endl;
    cin >> auxc;
    if(auxc>=3 && auxc<=16){
        col = auxc;
        return;
    }
    cout << "Valor errado" << endl;
    ilha::defineCol();
}

int ilha::obtemCol() const {
    return col;
}

int ilha::obtemLin() const {
    return lin;
}

void ilha::mudaValorEdificio(int& l, int& c, const string& t) {
    if(tabuleiro[l][c].obtemQuant_Edificios() > 0)
        return;
    tabuleiro[l][c].defineEdificio(t);
}

void ilha::mudaValorTrab(int& l, int& c, const string& t) {
    if(t == "oper"){
        if(verificaTrabalhador(t)){
            tabuleiro[l][c].defineTrab("O");
            tabuleiro[l][c].defineQuantTrab();
            return;
        }
        cout << "Este trabalhador não existe" << endl;
    }
    if(t == "len"){
        if(verificaTrabalhador(t)){
            tabuleiro[lin][col].obtemTrab();
            //tabuleiro[lin][col].defineQuantTrab();
            return;
        }
        cout << "Este trabalhador não existe" << endl;
    }
    if(t == "min"){
        if(verificaTrabalhador(t)){
            tabuleiro[lin][col].defineTrab("M");
            tabuleiro[lin][col].defineQuantTrab();
            return;
        }
        cout << "Este trabalhador não existe" << endl;
    }
}

bool ilha::verificaLinCol(int x, int y) {
   if(x<=lin && y<=col)
       return true;
    return false;
}
string ilha::mostraZona(int x, int y) {
    ostringstream oss;

        for(int i = 0; i < 4; ++i){
            switch (i) {
                case 0:
                    oss << tabuleiro[x][y].obtemTipo() << endl;
                    break;
                case 1:
                    oss << tabuleiro[x][y].obtemEdificio() << endl;
                    break;
                case 2:
                    oss << tabuleiro[x][y].obtemTrab() << endl;
                    break;
                case 3:
                    oss << tabuleiro[x][y].obtemQuant_Trab() << endl;
                    break;
                default:
                    break;
            }
        }
        return oss.str();
}
void ilha::criaIlha() {
    tabuleiro = new Zona*[lin];
    for (int i = 0; i < lin; ++i) {
        tabuleiro[i] = new Zona[col];
    }

    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            tabuleiro[i][j].defineTipo("-");
            tabuleiro[i][j].defineTrab("-");
            tabuleiro[i][j].definePosC(j);
            tabuleiro[i][j].definePosL(i);
            tabuleiro[i][j].defineEdificio("-");
        }
    }
}

string ilha::mostraIlha() {
    ostringstream oss;

    for (int k = 0; k < col; ++k) {
        if(k < col-1)
            oss << "+ ------------- ";
        else
            oss << "+ ------------- +";
    }

    for (int i = 0; i < lin; ++i) {
        oss << "\n";
        for (int j = 0; j < 4; ++j) {
            oss << "|\t";
            for (int k = 0; k < col; ++k) {
                switch (j) {
                    case 0:
                        oss << tabuleiro[i][k].obtemTipo();
                        break;
                    case 1:
                        oss << tabuleiro[i][k].obtemEdificio();
                        break;
                    case 2:
                        oss << tabuleiro[i][k].obtemTrab();
                        break;
                    case 3:
                        oss << tabuleiro[i][k].obtemQuant_Trab();
                        break;
                    default:
                        break;
                }
                oss << "\t|\t";
            }
            oss << "\n";
        }
        for (int k = 0; k < col; ++k) {
            if(k < col-1)
                oss << "+ ------------- ";
            else
                oss << "+ ------------- +";
        }
    }
    return oss.str();
}


string ilha::executa() {
    string s1, s2;
        vector<string> v;

        int x = 0, y = 0;

        cout << "\nComando: ";
        cin.sync();
        //cin.ignore(numeric_limits<streamsize>::max(),'\n');

        getline(cin, s1);

        cout << "s1: " << s1 << "\n";
        stringstream ss(s1);

        while (getline(ss, s2, ' ')) {
            v.push_back(s2);

        }

        if(v.size() > 2){
            istringstream ossX(v[2]);//transforma string em int
            ossX >> x;//atribui valor transformado à variavel x
            istringstream ossY(v[3]);//transforma string em int
            ossY >> y;//atribui valor transformado à variavel y
        }

        if(comandos(v)){//função que verifica se o comando e se o tipo são válidos
            //COMANDOS DO FICHEIRO
            if(v[0] == "exec"){
                vector<string> lines;
                string line;
                int fx, fy;

                ifstream fich_leitura(v[1]);
                if(!fich_leitura.is_open()) {
                    cerr << "Erro ao tentar abrir o ficheiro";
                    return s1;
                }

                getline(fich_leitura,line, '\n');

                fich_leitura.close();

                stringstream ss1(line);
                while (getline(ss1, line, ' ')) {
                    lines.push_back(line);
                }

                if(lines.size() > 2){
                    istringstream ossFX(lines[2]);//transforma string em int
                    ossFX >> fx;//atribui valor transformado à variavel x
                    istringstream ossFY(lines[3]);//transforma string em int
                    ossFY >> fy;//atribui valor transformado à variavel y
                }

                if(comandos(lines)){
                    if (lines[0] == "cons"){
                        if (verificaLinCol(fx,fy)){
                            istringstream o(lines[1]);
                            string aux;
                            o>>aux;

                            ilha::mudaValorEdificio(fx, fy, aux);
                            return s1;
                        }
                    }
                    if (lines[0] == "cont"){
                        if(verificaTrabalhador(lines[1])){
                            ilha::mudaValorTrab(fx, fy, lines[1]);
                            return s1;
                        }
                    }
                    if(lines[0] == "list"){
                        if(v.size() > 1){
                            if(verificaLinCol(fx,fy)){
                                cout << mostraZona(fx,fy);
                                return s1;
                            }
                        }
                        else{
                            cout << mostraIlha();
                            return s1;
                        }
                    }
                }else{
                    cout << "comandos do ficheiro não são válidos" << endl;
                    return s1;
                }

            }

            //COMANDOS STDIN
            if (v[0] == "cons"){
                if (verificaLinCol(x,y)){
                    istringstream o(v[1]);
                    string aux;
                    o>>aux;

                    ilha::mudaValorEdificio(x, y, aux);
                    return s1;
                }else{
                    cout << "fora dos limites" << endl;
                    return s1;
                }
            }
            if (v[0] == "cont"){
                if (verificaLinCol(x,y)){
                    istringstream o(v[1]);
                    string aux;
                    o>>aux;
                    ilha::mudaValorTrab(x, y, aux);
                    return s1;

                }else{
                    cout << "fora dos limites" << endl;
                    return s1;
                }
            }
            if(v[0] == "list"){
                if(v.size() > 1){
                    if(verificaLinCol(x,y)){
                        cout << mostraZona(x,y);
                        return s1;
                    }
                }
                else{
                    cout << mostraIlha();
                    return s1;
                }
            }
        }
        return s1;
}