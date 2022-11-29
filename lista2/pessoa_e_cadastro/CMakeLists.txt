cmake_minimum_required(VERSION 3.5)
project("Pessoa e Cadastro" VERSION 0.1 LANGUAGES CXX )

# set the compiling flags
set ( CMAKE_CXX_FLAGS "-Wall" )


### [1] Application target
# configura o diretório contendo os .h, assim você pode incluílos apenas com include "arquivo.h"
include_directories( ./include )

### [2] Test engine
# includes do test manager

# Cria um executável com nome "program" com base no main.cpp
set( APP_NAME "program" )
add_executable( ${APP_NAME}
                src/main.cpp
                src/Cadastro.cpp
                src/Pessoa.cpp
                )

# define C++14 standard
set_property(TARGET ${APP_NAME} PROPERTY CXX_STANDARD 14)

add_custom_target(
    verify
    COMMAND python3 ${CMAKE_SOURCE_DIR}/../scripts/verify-inputs.py ./${APP_NAME}
    DEPENDS ${APP_NAME}
)

# The end
