cmake_minimum_required(VERSION 3.10)
project(hangman VERSION 1.0 DESCRIPTION "Projeto referente a unidade 1 de LIP I." LANGUAGES CXX)

include_directories( include )
set(APP_NAME "program")
add_executable(${APP_NAME} src/main.cpp src/hangman.cpp src/view.cpp)