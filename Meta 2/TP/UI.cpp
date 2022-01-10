//
// Created by Rafael on 02/12/2021.
//

#include "UI.h"
#include "sstream"

void UI::start() {

    int l = defineL() , c = defineC();
    string str, s2;
    vector<string> v;
    ostringstream oss;

    j.criaIsland(l, c);
    cout << j.mostraIsland();


    while(str != "fim"){
        str = "-";
        cout << "\nFase do dia : " <<j.gereDias("Manha") << endl;
        while(str != "next"){
            str = defineComando();
            if(str  == "fim")
                break;
            cout << j.gereIsland(str);
        }
        cout << "\nFase do dia : " <<j.gereDias("Tarde") << endl;
        cout << j.mostraIsland();
    }
}

void UI::menu() {

    int resp;

    cout << " _____    _                 _ \n"
            "|_   _|  | |               | |\n"
            "  | | ___| | __ _ _ __   __| |\n"
            "  | |/ __| |/ _` | '_ \\ / _` |\n"
            " _| |\\__ \\ | (_| | | | | (_| |\n"
            " \\___/___/_|\\__,_|_| |_|\\__,_|\n"
            "                              \n"
            "                              " << endl;

    cout << "1 - Play \2\n2 - Help \2\n3 - Exit \2 " << endl;
    while (true) {
        cout << "Comando: ";
        cin >> resp;
        switch (resp) {
            case 1:
                start();
                break;
                case 2:
                    help();
                    break;
                    case 3:
                        cout << "Exit";
                        return;
                        default:
                            cout << "Comando invalido\n";
                            continue;
        }
        break;
    }
}

int UI::defineL() {
    int l = 0;
    while(l < 3 || l > 8){
        cout << "\nN. de linhas: ";
        cin >> l;
        if(l < 3 || l > 8)
            cout << "Valor invalido! Tem que estar compreendido entre 3 e 8." << endl;
    }
    return l;
}

int UI::defineC() {
    int c = 0;
    while(c < 3 || c > 16){
        cout << "\nN. de colunas: ";
        cin >> c;
        if(c < 3 || c > 8)
            cout << "Valor invalido! Tem que estar compreendido entre 3 e 16." << endl;
    }
    return c;
}

string UI::defineComando() {
    string str;
    cout << "\nComando: ";
    cin.sync();
    getline(cin, str);
    return str;
}

void UI::help() {
    int resp;

    cout << "\n"
            "  _____           _                   /\\/|           \n"
            " |_   _|         | |                 |/\\/            \n"
            "   | |  _ __  ___| |_ _ __ _   _  ___ ___   ___  ___ \n"
            "   | | | '_ \\/ __| __| '__| | | |/ __/ _ \\ / _ \\/ __|\n"
            "  _| |_| | | \\__ \\ |_| |  | |_| | (_| (_) |  __/\\__ \\\n"
            " |_____|_| |_|___/\\__|_|   \\__,_|\\___\\___/ \\___||___/\n"
            "                                  )_)                \n"
            "";

    cout << "\nComandos do jogo : \n";

    cout << "\n1. exec <nomeFicheiro> -> Executa um conjunto de comandos existentes em nomeFicheiro. Esse ficheiro tem os comandos, um por cada linha, segundo a mesma sintaxe como quando sao escritos.\n"
            "\n2. cons <tipo> <linha> <coluna> -> Constroi um edificio de um dado tipo na zona posicionada na linha e coluna. Nesta zona nao podera haver outro edificio e as condicoes necessaria para a"
            "construcao do tipo de edificio deverao ser observadas na altura de execucao do comando. Tipo = minaf | minac | central | bat | fund | edx (abreviaturas baseadas nos nomes dos recursos"
            "em minusculas e sem letras acentuadas).\n"
            "\n3. liga <linha> <coluna> -> Liga o edificio (caso exista) que esta construido na zona posicionada na linha e coluna.\n"
            "\n4. des <linha> <coluna> -> desliga o edificio (caso exista) que esta construido na zona posicionada na linha e coluna.\n"
            "\n5. move <id> <linha> <coluna> -> Move o trabalhador com o identificador id para a zona posicionada na linha e coluna.\n"
            "\n6. vende <tipo> <quanto> -> Vende recursos de um dado tipo e de acordo com quanto se pretende vender (de acordo com a unidade de cada recurso). Tipo = ferro | aco | carvao | mad | viga | eletr"
            "(abreviaturas baseadas nos nomes dos recursos em minusculas e sem letras acentuadas).\n"
            "\n7. cont <tipo> -> Contrata um trabalhador de um dado tipo e este, tal como dito anteriormente, vai para a zona de pasto a espera de ordens do jogador. Tipo = oper | len | miner (abreviaturas "
            "baseadas nos nomes dos recursos em minusculas e sem letras acentuadas).\n"
            "\n8. list <linha> <coluna> -> Obtem a informacaoo do jogo, globalmente se nao for indicada nenhuma linha.coluna, ou detalhada acerca de uma zona caso a sua posicao linha coluna seja indicada.\n"
            "\n9. vende <linha> <coluna> -> Vende o edificio existente na zona indicada na linha e coluna especificadas. Recupera os euros gastos na sua construcao mas nao os recursos adicionalmente usados "
            "(exemplo, as vigas na mina). Os recursos armazenados no edificio em questao sao automaticamente vendidos e os euros resultantes passam para o jogador.\n"
            "\n10. next -> Termina a fase de recolha de comandos e desencadeia as acoes necessarias ao seu processamento.\n"
            "\n11. save <nome> -> Grava o estado do jogo em memoria, associando-lhe um nome. Esta acao consiste em fazer uma especie de savegame para memoria, possibilitando ao jogador manter em memoria"
            "diversos snapshots do jogo, correspondentes a diversos momentos, permitindo-lhe a qualquer momento recuperar um desses momentos. O jogo continua ativo, mas a copia feita para memoria ja"
            "nao sera afetada pelos comandos entretanto escritos a partir deste momento.\n"
            "\n12. load <nome> -> Recupera um dado estado do jogo em memoria, identificado ao nome indicado, e carrega-o. O jogo recuperado passa a ser o que esta em efeito: os comandos passam a agir sobre este.\n"
            "\n13. apaga <nome> -> Apaga um determinado savegame de memoria.\n"
            "\n14. config <ficheiro> -> Le o ficheiro de texto e extrai dele os preços de contratacao dos trabalhadores e de compra dos edificios. Sao configurados apenas os valores base de € e nao os numeros de recursos"
            "adicionais (ex.: numero de vigas para a mina). Os valores lidos sobrepoe-se aos indicados no enunciado, que apenas sao considerados enquanto nao for lido um ficheiro de configuracao\n"
            "\tO ficheiro tem o conteudo em que cada linha tem duas palavras separadas por um espaco:\n"
            "\t nome da coisa (edificio ou trabalhador) e preco (apenas aparte dos €). Os nomes sao os\n"
            "\t mesmos usados nos comandos de contratacao e de construcao. Exemplo:\n"
            "\n\t\tminac 15\n"
            "\t\tlen 12\n"
            "\n15. debcash <valor> -> Adicina a quantidade de euros especificada em valor. A quantidade pode ser positiva (adicionar) ou negativa (remove. Serve para debug e teste.\n"
            "\n16. debed <tipo> <linha> <coluna> -> Adiciona um edificio a custo zero na zona linha, coluna, respeitando as restricoes de nao poder haver mais do que um edificio"
            "na zona. Serve para debug e teste.\n"
            "\n17. debkill <id> -> Remove o trabalhador com a identificacao id. Serve para debug e teste\n";

            while(true){
                cout << "\nDeseja comecar o jogo? (1 -> SIM | 2 -> NAO)?" << endl;
                cin >> resp;
                switch (resp) {
                    case 1:
                        start();
                        break;
                    case 2:
                        menu();
                        return;
                }
               break;
            }
}
