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
        TP/trabalhdores.cpp
        TP/trabalhdores.h TP/UI.cpp TP/UI.h TP/jogo.cpp TP/jogo.h)
