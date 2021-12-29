cmake_minimum_required(VERSION 3.20)
project(TP_POO)

set(CMAKE_CXX_STANDARD 14)

include_directories(TP)

add_executable(TP_POO
        TP/comandos.cpp
        TP/geral.h
        TP/ilha.cpp
        TP/ilha.h
        TP/main.cpp
        TP/zona.cpp
        TP/zona.h
        TP/config.cpp
        TP/trabalhadores.cpp
        TP/trabalhadores.h
        TP/UI.cpp
        TP/UI.h
        TP/jogo.cpp
        TP/jogo.h
        TP/deserto.cpp
        TP/deserto.h
        TP/pastagem.cpp
        TP/pastagem.h
        TP/floresta.cpp
        TP/floresta.h
        TP/montanha.cpp
        TP/montanha.h
        TP/pantano.cpp
        TP/pantano.h
        TP/operario.h
        TP/operario.cpp
        TP/lenhador.cpp
        TP/lenhador.h
        TP/mineiro.cpp
        TP/mineiro.h
        TP/recursos.cpp
        TP/recursos.h
        TP/ferro.cpp
        TP/ferro.h
        TP/barraAco.cpp
        TP/barraAco.h
        TP/carvao.cpp
        TP/carvao.h
        TP/madeira.cpp
        TP/madeira.h
        TP/vigasMadeira.cpp
        TP/vigasMadeira.h
        TP/eletricidade.cpp
        TP/eletricidade.h
        TP/edificio.h
        TP/edificio.cpp
        TP/minaCarvao.cpp
        TP/minaCarvao.h
        TP/minaFerro.cpp
        TP/minaFerro.h
        TP/bateria.cpp
        TP/bateria.h
        TP/fundicao.cpp
        TP/fundicao.h
        TP/centralEletrica.cpp
        TP/centralEletrica.h
        TP/trabalhadores.cpp
        TP/trabalhadores.h TP/dinheiro.cpp TP/dinheiro.h)
