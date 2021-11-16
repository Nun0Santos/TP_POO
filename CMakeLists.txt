cmake_minimum_required(VERSION 3.20)
project(TP_POO)

set(CMAKE_CXX_STANDARD 14)

include_directories(TP)

add_executable(TP_POO
        TP/comandos.cpp
        TP/deserto.cpp
        TP/deserto.h
        TP/geral.h
        TP/ilha.cpp
        TP/ilha.h
        TP/main.cpp
        TP/mina_ferro.cpp
        TP/mina_ferro.h
        )
